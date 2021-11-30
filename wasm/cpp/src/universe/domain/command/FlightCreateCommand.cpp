#include "../../../planet/domain/model/Planet.h"
#include "../../../player/domain/model/Player.h"
#include "FlightCreateCommand.h"

FlightCreateCommand::FlightCreateCommand():
  FlightCreateCommand(nullptr, nullptr, 0, nullptr) {}

FlightCreateCommand::FlightCreateCommand(
  Planet* destination,
  Player* owner,
  int ships,
  Planet* source
) {
  this->destination = destination;
  this->owner = owner;
  this->ships = ships;
  this->source = source;
}
