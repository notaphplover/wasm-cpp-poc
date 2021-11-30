#include <emscripten/bind.h>

#include "Planet.h"

#include "../../../player/domain/model/Player.h"

Planet::Planet() : Planet(nullptr, 0, 0, 0, 0, 0) {}

Planet::Planet(
  Player* owner,
  int ships,
  int shipsPerTurn,
  int size,
  int x,
  int y
):
  owner(owner), 
  x(x),
  y(y),
  ships(ships),
  shipsPerTurn(shipsPerTurn),
  size(size)
  {}

EMSCRIPTEN_BINDINGS() {
  emscripten::class_<Planet>("Planet")
    .constructor<Player*, int, int, int, int, int>(emscripten::allow_raw_pointers())
    .property("owner", &Planet::owner)
    .property("x", &Planet::x)
    .property("y", &Planet::y)
    .property("ships", &Planet::ships)
    .property("shipsPerTurn", &Planet::shipsPerTurn)
    .property("size", &Planet::size)
  ;
