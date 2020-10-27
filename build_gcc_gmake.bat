::=============================================================================
:: Daniel J. Greenhoe
:: Build project using GNU compiler and GNU make
::=============================================================================
::-------------------------------------
:: Generate Environment variables
::-------------------------------------
  set BUILD_DIR=Build_gcc_gmake
  set MAKE_EXE=c:/CVSSource/Libraries/GNU/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/mingw32-make.exe
  set CMAKE_EXE=c:/CVSSource/Libraries/CMake/3.18.3/bin/cmake.exe
::-------------------------------------
:: Create clean build space
::-------------------------------------
  rmdir %BUILD_DIR% /s/q
  mkdir %BUILD_DIR%
  cd    %BUILD_DIR%
::-------------------------------------
:: Generate Makefile using -G <generator>
::-------------------------------------
  %CMAKE_EXE% -G "MinGW Makefiles" ..
::-------------------------------------
:: Build Executable
::-------------------------------------
  %MAKE_EXE%
  dir *.exe /od
