# BLINKplus
BLINK+, UC Berkeley CS 267 Final Project

## Building

```
mkdir build && cd build
cmake ../
make
```
The `libblinkplus.so` file is in `build/src/`. TODO: write a install routine

## Running

To run a nccl application with blinkplus, just do this:
```
LD_PRELOAD=/path/to/libblinkplus.so /path/to/binary
```

There's a example in `tests`. Try running with and without `LD_PRELOAD`

## Developing

See `src/allReduce.cu` for a toy example


