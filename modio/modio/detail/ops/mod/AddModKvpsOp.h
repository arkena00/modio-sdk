#pragma once
#include <filesystem>

#include "modio/core/ModioBuffer.h"
#include "modio/detail/serialization/ModioModInfoSerialization.h"
#include "modio/detail/AsioWrapper.h"
#include "modio/detail/ModioJsonHelpers.h"
#include "modio/detail/ops/http/PerformRequestAndGetResponseOp.h"
#include "modio/impl/SDKPreconditionChecks.h"

namespace Modio
{
    namespace Detail
    {
#include <asio/yield.hpp>
        class AddModKvpsOp
        {
        public:
            AddModKvpsOp(Modio::GameID GameID, Modio::ApiKey ApiKey, Modio::ModID ModId, std::vector<Modio::Metadata> Kvps)
                : GameID(GameID),
                  ApiKey(ApiKey),
                  ModId(ModId),
                  Kvps(std::move(Kvps))
            {
                RequestParams =
                Modio::Detail::AddModKvpMetadataRequest.SetGameID(Modio::Detail::SDKSessionData::CurrentGameID())
                .SetModID(ModId);

                for (const Modio::Metadata& metadata : Kvps)
                {
                    RequestParams = RequestParams.AppendPayloadValue("metadata_kvp[]", fmt::format("{}:{}", metadata.Key, metadata.Value));
                }
            }

            template<typename CoroType>
            void operator()(CoroType& Self, Modio::ErrorCode ec = {})
            {
                reenter(CoroutineState)
                {
                    yield Modio::Detail::PerformRequestAndGetResponseAsync(ResponseBodyBuffer, RequestParams,
                        CachedResponse::Disallow, std::move(Self));

                    if (ec)
                    {
                        Self.complete(ec);
                        return;
                    }

                    Self.complete({});
                    return;
                }
            }

        private:
            Modio::GameID GameID;
            Modio::ApiKey ApiKey;
            Modio::ModID ModId;
            std::vector<Modio::Metadata> Kvps;

            Modio::Detail::HttpRequestParams RequestParams {};
            Modio::Detail::DynamicBuffer ResponseBodyBuffer;
            ModioAsio::coroutine CoroutineState;
        };
    #include <asio/unyield.hpp>

        template<typename Callback>
		inline void AddModKvps(Modio::ModID ModId, std::vector<Modio::Metadata> Kvps, Callback&& OnCallback)
		{
            return ModioAsio::async_compose<Callback, 
                                        void(Modio::ErrorCode)>(
            Modio::Detail::AddModKvpsOp(Modio::Detail::SDKSessionData::CurrentGameID(),
                                        Modio::Detail::SDKSessionData::CurrentAPIKey(), ModId, std::move(Kvps)),
            OnCallback, 
            Modio::Detail::Services::GetGlobalContext().get_executor());
		}
    } // namespace Detail
} // namespace Modio