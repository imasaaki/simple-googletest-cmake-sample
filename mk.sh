#!/bin/sh
rm build -fr
mkdir build
cd build
cmake ..
make -j8

