#pragma once

#include <vector>

#include "../../../flight/domain/model/Flight.h"
#include "../../../planet/domain/model/Planet.h"

class Universe {
  public:
    int flightVelocity;
    std::vector<Flight> flights;
    std::vector<Planet> planets;

    Universe();

    Universe(
      int flightVelocity,
      std::vector<Flight> flights,
      std::vector<Planet> planets
    );
};
