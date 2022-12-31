# Cuistax
A proto game engine on top of SDL2, made in the style of libGDX with an aim to teach myself good C++ coding practices.
## Currently supported features
* Text rendering using bitmap renders of fonts.
* Image rendering.
* Timers.
* Dynamic entities.
* FPS counter.
## Build
### Requirements
* libSDL2-dev
* Cmake
* Cmake's pkg config
### Instructions
Create a directory alongside the CmakeLists.txt file then cd inside it.
```bash
mkdir cmake-build && cd cmake-build
```
Run the cmake generation
```bash
cmake ..
```
Compile the example
```bash
make -j
```
Run the main executable
```bash
./main
```
I managed to build it on Windows with no adaptation needed using MSYS2's packages.
But please, do not harm yourself and do C/C++ development on Windows.


