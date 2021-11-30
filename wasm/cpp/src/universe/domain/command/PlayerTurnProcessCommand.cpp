#include <vector>

#include "../model/Universe.h"
#include "FlightCreateCommand.h"
#include "PlayerTurnProcessCommand.h"

PlayerTurnProcessCommand::PlayerTurnProcessCommand():
  PlayerTurnProcessCommand(std::vector<FlightCreateCommand>(), nullptr) {}

PlayerTurnProcessCommand::PlayerTurnProcessCommand(
  std::vector<FlightCreateCommand> flightCreateCommands,
  Universe* universe
) {
  this->flightCreateCommands = flightCreateCommands;
  this->universe = universe;
}
