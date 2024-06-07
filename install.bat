@echo off

set "build_dir=build\"

if exist %build_dir% (
  rd /s/q %build_dir%
  rd %build_dir%
)

mkdir %build_dir%
cd %build_dir%

conan install ..\conanfile.txt --profile=msvc-x64-debug --build=missing
cmake -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 17 2022" -A x64 ..

cd ..

set /p DUMMY=Press ENTER to continue...
