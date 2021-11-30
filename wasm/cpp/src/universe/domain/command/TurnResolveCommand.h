#pragma once

#include "../model/Universe.h"

class TurnResolveCommand {
  public:
    Universe* universe;

    TurnResolveCommand();

    TurnResolveCommand(Universe* universe);
};
