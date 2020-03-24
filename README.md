# otfcc-quad2cubic

## How to Build

Dependency: [Boost](https://www.boost.org/).

```bash
# configure
# you may specify Boost installation dir by `-DBOOST_ROOT=path/to/boost`
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Release

# then build
cmake --build build
```

## Usage

```bash
otfccdump input.ttf | otfcc-q2c | otfccbuild -o output.otf
```
