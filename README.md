CDevStudio
==========

A C/C++ IDE based on Qt5. CDevStudio is cross compatible and runs under Linux, Unix, OS X and Windows

Install build environment
-------------------------

Required
* Setup a C/C++ toolchain and add it to the system path. C++11 features are required
* Setup Qt5 and add it to the system path. Version 5.0.0 or higher is required
* Setup CMake and add it to the system path. Version 2.8.11 or higher is required

Optional
* Setup doxygen and add it to the system path

Prepare CDevStudio
------------------

Download and prepare CDevStudio
* git clone https://github.com/swaechter/cdevstudio.git
* cd cdevstudio
* mkdir build
* cd build

Compile CDevStudio
------------------

Linux/Unix gcc/clang - Build
* cmake .. && make
* ./src/cdevstudio/cdevstudio

Mac OS X clang - Build
* cmake .. && make
* Copy the dylib libraries to the cdevstudio directory
* ./src/cdevstudio/cdevstudio

Windows MinGW - Build
* cmake .. -G"MinGW Makefiles" && mingw32-make
* Copy the dll libraries to the cdevstudio directory
* .\src\cdevstudio\cdevstudio

Windows MSVC - Build
* cmake .. && msbuild Project.sln
* Copy the dll libraries to the cdevstudio directory
* .\src\cdevstudio\buildtype\cdevstudio.exe

Packaging/Installing CDevStudio
-------------------------------

The following package systems are supported. For more information read the instructions.txt in each package system directory
* Linux: Make for all distributions via a pure 'make install'
* Linux: DEB for Debian via debuild
* Linux: RPM for Fedora via rpmbuild
* Linux: TAR.XZ for Arch Linux via makepkg
* Windows: EXE for all systems via NSIS

Notes
-----

Important notes
