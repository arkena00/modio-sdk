/*
 *  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
 *
 *  This file is part of the mod.io SDK.
 *
 *  Distributed under the MIT License. (See accompanying file LICENSE or
 *   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
 *
 */

#pragma once

// Stubs for Posix extensions that are not available on some platforms, used by parts of FMT we don't use anyways
#ifdef MODIO_USE_FMT_POSIX_STUBS
inline void flockfile(FILE*) {}
inline void funlockfile(FILE*) {}
inline int getc_unlocked(FILE*)
{
	return -1;
}
inline int putc_unlocked(int, FILE*)
{
	return -1;
}
#endif

#ifndef MODIO_USE_CUSTOM_FMT
	#pragma push_macro("FMT_HEADER_ONLY")
	#ifndef FMT_HEADER_ONLY
		#define FMT_HEADER_ONLY
	#endif
#endif

#ifdef MODIO_PLATFORM_UNREAL

	#include MODIO_UNREAL_PLATFORM_PREAMBLE
	#pragma push_macro("check")
	#undef check
	#if PLATFORM_WINDOWS || PLATFORM_XBOXONEGDK || PLATFORM_XSX || PLATFORM_XB1
		#pragma warning(push)
		#pragma warning(disable : 4583)
		#pragma warning(disable : 4582)
		#pragma warning(disable : 4265)
	#endif
	#include <type_traits>
	#pragma push_macro("_LIBCPP_VERSION")
	#undef _LIBCPP_VERSION

	#include "fmt/chrono.h"
	#include "fmt/format.h"
	#include "fmt/printf.h"
	#include "fmt/ranges.h"
	#include "fmt/xchar.h"
	#if PLATFORM_WINDOWS || PLATFORM_XBOXONEGDK || PLATFORM_XSX || PLATFORM_XB1
		#pragma warning(pop)
	#endif
	#pragma pop_macro("_LIBCPP_VERSION")
	#pragma pop_macro("check")
	#include MODIO_UNREAL_PLATFORM_EPILOGUE

#else
	#pragma push_macro("_LIBCPP_VERSION")
	#undef _LIBCPP_VERSION
	#include "fmt/chrono.h"
	#include "fmt/format.h"
	#include "fmt/printf.h"
	#include "fmt/ranges.h"
	#include "fmt/xchar.h"
	#pragma pop_macro("_LIBCPP_VERSION")

#endif

#ifndef MODIO_USE_CUSTOM_FMT
	#pragma pop_macro("FMT_HEADER_ONLY")
#endif
