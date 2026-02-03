set LINUX_MULTIARCH_ROOT=C:/UnrealToolchains/v23_clang-18.1.0-rockylinux8
set PWD=%~dp0

cmake -S . --preset=linux64 -DCMAKE_POLICY_VERSION_MINIMUM=3.5 ^
-DCMAKE_C_FLAGS="--target=x86_64-unknown-linux-gnu --sysroot=%LINUX_MULTIARCH_ROOT%/x86_64-unknown-linux-gnu -I%PWD%/libs/linux/liburing/include" ^
-DCMAKE_CXX_FLAGS="--target=x86_64-unknown-linux-gnu --sysroot=%LINUX_MULTIARCH_ROOT%/x86_64-unknown-linux-gnu -I%PWD%/libs/linux/liburing/include" ^
-DCMAKE_SYSROOT="%LINUX_MULTIARCH_ROOT%/x86_64-unknown-linux-gnu" -DCMAKE_C_COMPILER="%LINUX_MULTIARCH_ROOT%/x86_64-unknown-linux-gnu/bin/clang.exe" ^
-DCMAKE_CXX_COMPILER="%LINUX_MULTIARCH_ROOT%/x86_64-unknown-linux-gnu/bin/clang.exe"


cmake --build out/build/linux64 --config Release
cmake --install out/build/linux64
ren "out/install/linux64/header_only/common/modio/detail/CInterfaceImpl.cpp" "CInterfaceImpl.cpp.exclude"

pause