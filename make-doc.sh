#!/usr/bin/env bash

if [ ! -d docs ]; then
    echo "PLEASE CLONE THE DOCUMENTATION OVER HERE FIRST!";
else
    bash build.sh
    cd dist
    make doc
fi


