#!/usr/bin/env bash
docker run \
    --rm \
    -v $(pwd):/src \
    -u $(id -u):$(id -g) \
    emscripten/emsdk \
    emcc \
        -std=c++11 \
        -pthread -s PROXY_TO_PTHREAD \
        src/main.cpp \
        -o src/main.html
