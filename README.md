# otfcc-quad2cubic

## How to Build

```bash
cmake -H. -Bbuild
cmake --build build
```

## Usage

```bash
otfccdump input.ttf | otfcc-q2c | otfccbuild -o output.otf
```
