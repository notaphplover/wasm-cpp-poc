#pragma once

#include "../command/PlayerTurnProcessCommand.h"

class ProcessPlayerTurnInteractor {
  public:
    void interact(PlayerTurnProcessCommand playerTurnProcessCommand);

    ProcessPlayerTurnInteractor();

  private:
    int calculateFlightDuration(Planet* source, Planet* destination);
    bool isFlightCreateCommandValid(const FlightCreateCommand* flightCreateCommand);
    void handleInvalidFlightCreateCommand(const FlightCreateCommand* flightCreateCommand);
};
