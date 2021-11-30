#include <vector>

#include "../../../flight/domain/model/Flight.h"
#include "../../../planet/domain/model/Planet.h"
#include "Universe.h"

Universe::Universe(): Universe(0, std::vector<Flight>(), std::vector<Planet>()) {}

Universe::Universe(
  int flightVelocity,
  std::vector<Flight> flights,
  std::vector<Planet> planets
) {
  this->flightVelocity = flightVelocity;
  this->flights = flights;
  this->planets = planets;
}
