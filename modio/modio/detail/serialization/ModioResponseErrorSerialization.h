/*
 *  Copyright (C) 2021-2024 mod.io Pty Ltd. <https://mod.io>
 *
 *  This file is part of the mod.io SDK.
 *
 *  Distributed under the MIT License. (See accompanying file LICENSE or
 *   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
 *
 */

#pragma once

#include "modio/detail/http/ResponseError.h"

namespace Modio
{
	namespace Detail
	{
		inline void from_json(const nlohmann::json& Json, Modio::Detail::ResponseError& Error)
		{
			if (Json.contains("error"))
			{
				const nlohmann::json& ErrorJson = Json.at("error");
				if (ErrorJson.is_object())
				{
					// Parse usual ResponseError variables
					Detail::ParseSafe(ErrorJson, Error.Code, "code");
					Detail::ParseSafe(ErrorJson, Error.ErrorRef, "error_ref");
					Detail::ParseSafe(ErrorJson, Error.Error, "message");

					// Check for optional ExtendedErrorInformation
					if (ErrorJson.contains("errors"))
					{
						const nlohmann::json& ExtendedErrors = ErrorJson.at("errors");
						if (ExtendedErrors.is_object())
						{
							std::vector<Modio::FieldError> FieldErrors;
							Modio::FieldError FieldError;
							for (auto& Item : ExtendedErrors.items())
							{
								FieldError.Field = Item.key();
								FieldError.Error = std::string(Item.value());
								FieldErrors.push_back(FieldError);
							}
							Error.ExtendedErrorInformation = FieldErrors;
						}
					}
				}
			}
		}
	} // namespace Detail
} // namespace Modio