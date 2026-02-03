-- Fix missing files in mbedtls
if not exist "ext\mbedtls\library\error.c" if exist "ext\mbedtls\library\" type nul > "ext\mbedtls\library\error.c"
if not exist "ext\mbedtls\library\version_features.c" if exist "ext\mbedtls\library\" type nul > "ext\mbedtls\library\version_features.c"

cmake -S . --preset=oculus-arm64 -DCMAKE_POLICY_VERSION_MINIMUM=3.5
cmake --build out/build/meta-quest-arm64 --config Release
cmake --install out/build/meta-quest-arm64
ren "out\install\meta-quest-arm64\header_only\common\modio\detail\CInterfaceImpl.cpp" "CInterfaceImpl.cpp.exclude"

pause