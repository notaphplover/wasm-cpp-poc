#include <emscripten/emscripten.h>
#include <stdio.h>
#include <vector>

#include "flight/domain/model/Flight.h"
#include "planet/domain/model/Planet.h"
#include "universe/domain/model/Universe.h"

int main() {

  std::vector<Flight> flightsVector(10);

  Player* player = new Player(1);

  Planet* planet = new Planet(player, 0, 0, 0, 1, 1);

  std::vector<Planet> planetsVector(1);
  planetsVector.push_back(*planet);

  Universe* universe = new Universe(5, flightsVector, planetsVector);

  return 0;
}
