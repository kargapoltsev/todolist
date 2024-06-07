@echo off

set "build_dir=build\"

if exist %build_dir% (
    cd %build_dir%
    cmake -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 17 2022" -A x64 ..
    cd ..
)

set /p DUMMY=Press ENTER to continue...
