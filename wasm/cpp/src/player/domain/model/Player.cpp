#include <emscripten/bind.h>

#include "Player.h"

Player::Player(): Player(0) {}

Player::Player(int id) {
  this->id = id;
}

EMSCRIPTEN_BINDINGS() {
  emscripten::class_<Player>("Planet")
    .constructor<int>(emscripten::allow_raw_pointers())
    .property("id", &Player::id)
  ;
