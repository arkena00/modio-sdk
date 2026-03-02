#pragma once
#include "modio/core/ModioCoreTypes.h"
#include <string>

namespace Modio
{
    struct GetModFileParams
    {
        std::string Version;
        std::string Platform;
    };
} // namespace Modio