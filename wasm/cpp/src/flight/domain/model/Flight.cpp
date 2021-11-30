#include <emscripten/bind.h>

#include "Flight.h"

Flight::Flight()
  : Flight(0, nullptr, nullptr, 0, nullptr, 0) {}

Flight::Flight(
  int currentFlightDuration,
  Planet* destination,
  Player* owner,
  int ships,
  Planet* source,
  int totalFlightDuration
) : 
  currentFlightDuration(currentFlightDuration),
  destination(destination),
  owner(owner),
  ships(ships),
  source(source),
  totalFlightDuration(totalFlightDuration)
  {}

EMSCRIPTEN_BINDINGS() {
  emscripten::class_<Flight>("Flight")
    .constructor<int, Planet*, Player*, int, Planet*, int>(emscripten::allow_raw_pointers())
    .property("currentFlightDuration", &Flight::currentFlightDuration)
    .property("destination", &Flight::destination)
    .property("owner", &Flight::owner)
    .property("ships", &Flight::ships)
    .property("source", &Flight::source)
    .property("totalFlightDuration", &Flight::totalFlightDuration)
  ;
}
