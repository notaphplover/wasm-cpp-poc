#include <math.h>
#include <sstream>
#include <stdexcept>

#include "../command/PlayerTurnProcessCommand.h"
#include "ProcessPlayerTurnInteractor.h"

#define FLIGHT_INITIAL_DURATION 0

ProcessPlayerTurnInteractor::ProcessPlayerTurnInteractor() {}

void ProcessPlayerTurnInteractor::interact(PlayerTurnProcessCommand playerTurnProcessCommand) {
  std::size_t flightCreateCommandsLenght =
    playerTurnProcessCommand.flightCreateCommands.size();
  const FlightCreateCommand * flightCreateCommands =
    playerTurnProcessCommand.flightCreateCommands.data();

  for (std::size_t i = 0; i < flightCreateCommandsLenght; ++i) {
    const FlightCreateCommand flightCreateCommand = flightCreateCommands[i];

    bool isFlightCreateCommandValid =
      this->isFlightCreateCommandValid(&flightCreateCommand);

      if (isFlightCreateCommandValid) {
        flightCreateCommand.source->ships -= flightCreateCommand.ships;

      int flightDuration = this->calculateFlightDuration(
        flightCreateCommand.source,
        flightCreateCommand.destination
      );

      Flight* flight = new Flight(
        flightDuration,
        flightCreateCommand.destination,
        flightCreateCommand.owner,
        flightCreateCommand.ships,
        flightCreateCommand.source,
        FLIGHT_INITIAL_DURATION
      );

      playerTurnProcessCommand.universe->flights.push_back(*flight);
    } else {
      this->handleInvalidFlightCreateCommand(&flightCreateCommand);
    }
  }
}

int ProcessPlayerTurnInteractor::calculateFlightDuration(Planet* source, Planet* destination) {
  float diffX = destination->x - source->x;
  float diffY = destination->y - source->y;

  float euclideanDistance = sqrtf(diffX * diffX + diffY * diffY);
  int flightDuration = static_cast<int>(ceilf(euclideanDistance));

  return flightDuration;
}

bool ProcessPlayerTurnInteractor::isFlightCreateCommandValid(
  const FlightCreateCommand* flightCreateCommand
) {
  bool isSourcePlanetOwner =
    flightCreateCommand->owner
    && flightCreateCommand->owner->id == flightCreateCommand->source->owner->id
  ;

  bool planetHasEnoughShips =
    flightCreateCommand->source->ships >= flightCreateCommand->ships;

  return isSourcePlanetOwner && planetHasEnoughShips;
}

void ProcessPlayerTurnInteractor::handleInvalidFlightCreateCommand(
  const FlightCreateCommand* flightCreateCommand
) {
  std::string sourcePlanetPlayerId = std::to_string(flightCreateCommand->source->owner->id);

  std::stringstream ss;

  ss
    << "Invalid flight create command! Player id: "
    << sourcePlanetPlayerId;

  throw new std::invalid_argument(ss.str());
}
