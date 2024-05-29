/*
 *  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
 *
 *  This file is part of the mod.io SDK.
 *
 *  Distributed under the MIT License. (See accompanying file LICENSE or
 *   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
 *
 */

#ifdef MODIO_SEPARATE_COMPILATION
	#include "modio/core/entities/ModioUserDerivedToken.h"
#endif

#include "modio/detail/ModioConstants.h"
#include "modio/detail/ModioJsonHelpers.h"

namespace Modio
{
	void from_json(const nlohmann::json& Json, Modio::UserDerivedToken& Token)
	{
		Modio::Detail::ParseSafe(Json, Token.Entity, Modio::Detail::Constants::JSONKeys::TokenEntity);
		Modio::Detail::ParseSafe(Json, Token.Token, Modio::Detail::Constants::JSONKeys::TokenValue);
	}

} // namespace Modio