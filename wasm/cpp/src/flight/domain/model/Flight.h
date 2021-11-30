#pragma once

#include "../../../planet/domain/model/Planet.h"
#include "../../../player/domain/model/Player.h"

class Flight {
  public:
    int currentFlightDuration;
    Planet* destination;
    Player* owner;
    int ships;
    Planet* source;
    int totalFlightDuration;

    Flight();

    Flight(
      int currentFlightDuration,
      Planet* destination,
      Player* owner,
      int ships,
      Planet* source,
      int totalFlightDuration
    );
};
