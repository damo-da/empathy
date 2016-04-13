#!/usr/bin/env bash

mkdir -p dist

cd dist

if [ "$1" = "release" ]; then
   cmake -DCMAKE_BUILD_TYPE=Release .. && make
else
  cmake .. && make
fi

