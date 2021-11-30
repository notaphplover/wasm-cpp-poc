#pragma once

#include "../command/TurnResolveCommand.h"

class ResolveTurnInteractor {
  public:

    ResolveTurnInteractor();

    void interact(TurnResolveCommand turnResolveCommand);
};
