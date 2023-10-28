@echo off
ECHO ============ creating build environment ...
mkdir build
ECHO ============ creating build environment ... OK
ECHO ============ running cmake configuration ...
cmake -G "MinGW Makefiles" -S src -B build
ECHO ============ running cmake configuration ... OK
cd build
ECHO ============ running make ...
make
ECHO ============ running make ... OK
Tema1.exe
cd ..

ECHO ============ application finished ============