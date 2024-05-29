/*
 *  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
 *
 *  This file is part of the mod.io SDK.
 *
 *  Distributed under the MIT License. (See accompanying file LICENSE or
 *   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
 *
 */

// clang-format off

#include <SDKDDKVer.h>
#include "HAL/PlatformMisc.h"
#include "Misc/AssertionMacros.h"
#include "Windows/AllowWindowsPlatformTypes.h"

#include "Misc/EngineVersionComparison.h"

#if UE_VERSION_OLDER_THAN(5, 4, 0)
#include "Windows/PreWindowsApi.h"
#endif

#include "Windows/AllowWindowsPlatformAtomics.h"

// clang-format on