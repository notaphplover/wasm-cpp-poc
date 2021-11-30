#!/usr/bin/env bash
emcc \
    -std=c++14 \
    -lGL \
    -pthread \
    -s MIN_WEBGL_VERSION=2 \
    -s MAX_WEBGL_VERSION=2 \
    -s PROXY_TO_PTHREAD \
    -s USE_SDL_IMAGE=2 \
    -s SDL2_IMAGE_FORMATS='["png"]' \
    src/common/domain/exception/BaseException.cpp \
    src/flight/domain/model/Flight.cpp \
    src/main.cpp \
    src/planet/domain/model/Planet.cpp \
    src/player/domain/model/Player.cpp \
    src/universe/domain/command/FlightCreateCommand.cpp \
    src/universe/domain/command/PlayerTurnProcessCommand.cpp \
    src/universe/domain/command/TurnResolveCommand.cpp \
    src/universe/domain/interactor/ProcessPlayerTurnInteractor.cpp \
    src/universe/domain/model/Universe.cpp \
    -o dist/main.html
