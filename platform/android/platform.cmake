# 
#  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
#  
#  This file is part of the mod.io SDK.
#  
#  Distributed under the MIT License. (See accompanying file LICENSE or 
#   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
#   
# 

if(MODIO_PLATFORM STREQUAL "ANDROID" OR MODIO_PLATFORM STREQUAL "OCULUS")
add_subdirectory(${CMAKE_CURRENT_LIST_DIR})
endif()
