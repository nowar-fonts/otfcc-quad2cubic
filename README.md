# otfcc-quad2cubic

## How to Build

Build with GCC or Clang:
```bash
g++ src/driver.cpp src/q2c.cpp -Iinclude/ -std=c++17 -O2 -o otfcc-q2c
```

By default, otfcc-quad2cubic use [WFM JSON library](https://github.com/nowar-fonts/WFM-JSON). If you want to build with [Nlohmann’s JSON library](https://github.com/nlohmann/json), modify include dir `-Ipath/to/nlohmann/json`.

Build with Visual C++ (not fully tested):
```cmd
cl src\driver.cpp src\q2c.cpp /Iinclude\ /std:c++17 /EHsc /O2 /Fe:otfcc-q2c.exe
```

## Usage

```bash
otfccdump input.ttf | otfcc-q2c | otfccbuild -o output.otf
```
