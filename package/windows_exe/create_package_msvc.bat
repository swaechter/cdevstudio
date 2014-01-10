cd ..\..\build
cmake .. -DCMAKE_BUILD_TYPE=Release
msbuild Project.sln /p:Configuration=Release
cd ..\package\windows_exe
makensis /DMSVC-MSBUILD package.nsis
