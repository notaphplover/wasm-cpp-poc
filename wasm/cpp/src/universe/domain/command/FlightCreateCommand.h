#pragma once

#include "../../../planet/domain/model/Planet.h"
#include "../../../player/domain/model/Player.h"

class FlightCreateCommand {
  public:
    Planet* destination;
    Player* owner;
    int ships;
    Planet* source;

    FlightCreateCommand();

    FlightCreateCommand(
      Planet* destination,
      Player* owner,
      int ships,
      Planet* source
    );
};
