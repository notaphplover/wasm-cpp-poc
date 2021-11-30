#pragma once

#include <vector>

#include "../model/Universe.h"
#include "FlightCreateCommand.h"

class PlayerTurnProcessCommand {
  public:
    std::vector<FlightCreateCommand> flightCreateCommands;
    Universe* universe;

  PlayerTurnProcessCommand();
  PlayerTurnProcessCommand(
    std::vector<FlightCreateCommand> flightCreateCommands,
    Universe* universe
  );
};
