cmake -S . --preset=win -DCMAKE_POLICY_VERSION_MINIMUM=3.5
cmake --build out/build/win --config Release
cmake --install out/build/win
ren "out\install\win\header_only\common\modio\detail\CInterfaceImpl.cpp" "CInterfaceImpl.cpp.exclude"

pause