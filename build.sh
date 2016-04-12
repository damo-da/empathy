#!/usr/bin/env bash

mkdir -p dist/docs

cd dist

cmake .. && make
