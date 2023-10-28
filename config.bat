@echo off
ECHO ======building ... [50%]
mkdir build
ECHO ======building ... [100%]
ECHO ======running cmake configuration
cmake -G "MinGW Makefiles" -S src -B build
cd build
ECHO ======running make
make
Tema1.exe