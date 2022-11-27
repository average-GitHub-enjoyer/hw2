#! /usr/bin/bash

build_dir="build"
rm -rf $build_dir
cmake -S . -B $build_dir
cd $build_dir
make -j
cd src
./bmstu_string
cd ../tests
./bmstu_string_test
