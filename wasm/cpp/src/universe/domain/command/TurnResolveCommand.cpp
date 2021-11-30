#include "../model/Universe.h"
#include "TurnResolveCommand.h"

TurnResolveCommand::TurnResolveCommand(): TurnResolveCommand(nullptr) {}

TurnResolveCommand::TurnResolveCommand(Universe* universe) {
  this->universe = universe;
}
