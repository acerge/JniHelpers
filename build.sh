#!/usr/bin/env bash
rm -fr ./build
mkdir -p build
cd build
cmake .. ; make
cp ./libFancyNative.dylib /opt/homebrew/lib/
ls -l /opt/homebrew/lib/libFancyNative.*