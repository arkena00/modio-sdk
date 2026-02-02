#pragma once
#include <filesystem>

#include "modio/core/ModioBuffer.h"
#include "modio/core/ModioCreateModParams.h"
#include "modio/detail/serialization/ModioModInfoSerialization.h"
#include "modio/detail/AsioWrapper.h"
#include "modio/detail/ModioJsonHelpers.h"
#include "modio/detail/ops/DownloadFileOp.h"
#include "modio/detail/ops/http/PerformRequestAndGetResponseOp.h"
#include "modio/impl/SDKPreconditionChecks.h"

namespace Modio
{
    namespace Detail
    {
#include <asio/yield.hpp>
        class GetModFileOp
        {
        public:
            GetModFileOp(Modio::GameID GameID, Modio::ApiKey ApiKey, Modio::ModID ModId, std::string FileVersion)
                : GameID(GameID),
                  ApiKey(ApiKey),
                  ModId(ModId),
                  FileVersion(FileVersion)
                {}

            template<typename CoroType>
            void operator()(CoroType& Self, Modio::ErrorCode ec = {})
            {
                reenter(CoroutineState)
                {
                    yield Modio::Detail::PerformRequestAndGetResponseAsync(
                        ModFileInfoBuffer,
                        Modio::Detail::GetModfileByVersionRequest.SetGameID(GameID)
                            .SetModID(ModId).AddQueryParamRaw("version", FileVersion),
                        Modio::Detail::CachedResponse::Allow, std::move(Self));
                    if (ec)
                    {
                        Self.complete(ec, "");
                        return;
                    }

                    ModDetailsData = TryMarshalResponse<Modio::ModDetails>(ModFileInfoBuffer);
                    if (!ModDetailsData.has_value())
                    {
                        Self.complete(Modio::make_error_code(Modio::HttpError::InvalidResponse), "");
                        return;
                    }

                    if (ModDetailsData->GetTotalResultCount() != 1)
                    {
                        Self.complete(Modio::make_error_code(Modio::HttpError::InvalidResponse), "");
                        return;
                    }

                    if (Modio::Optional<Modio::filesystem::path> TempFilePath =
                    Modio::Detail::Services::GetGlobalService<Modio::Detail::FileService>()
                        .MakeTempFilePath(ModDetailsData->At(0)->Filename))
                    {
                        DownloadPath = std::move(*TempFilePath);
                    }

                    yield Modio::Detail::DownloadFileAsync(Modio::Detail::HttpRequestParams::FileDownload(ModDetailsData->At(0)->DownloadBinaryURL).value()
                        , DownloadPath, {}, {}, std::move(Self));
                    if (ec)
                    {
                        Self.complete(ec, DownloadPath.generic_u8string());
                        return;
                    }

                    if (ec)
                    {
                        Self.complete(ec, DownloadPath.generic_u8string());
                        return;
                    }

                    Self.complete({}, DownloadPath.generic_u8string());
                    return;
                }
            }

        private:
            Modio::GameID GameID;
            Modio::ApiKey ApiKey;
            Modio::ModID ModId;
            std::string FileVersion;

            ModioAsio::coroutine CoroutineState;
            Modio::Detail::DynamicBuffer ModFileInfoBuffer;
            Modio::Optional<Modio::ModDetails> ModDetailsData;
            Modio::filesystem::path DownloadPath;
            std::string DownloadURL;
        };
    #include <asio/unyield.hpp>

        template<typename Callback>
		void GetModFileAsync(Modio::ModID ModId, std::string FileVersion, Callback&& OnCallback)
		{
            return ModioAsio::async_compose<Callback, 
                                        void(Modio::ErrorCode, const std::string&)>(
            Modio::Detail::GetModFileOp(Modio::Detail::SDKSessionData::CurrentGameID(),
                                        Modio::Detail::SDKSessionData::CurrentAPIKey(), ModId, FileVersion),
            OnCallback, 
            Modio::Detail::Services::GetGlobalContext().get_executor());
		}
    } // namespace Detail
} // namespace Modio