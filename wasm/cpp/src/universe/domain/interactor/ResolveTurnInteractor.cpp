#include "../command/TurnResolveCommand.h"
#include "ResolveTurnInteractor.h"

ResolveTurnInteractor::ResolveTurnInteractor() {}

void ResolveTurnInteractor::interact(TurnResolveCommand turnResolveCommand) {
  Flight* flights = turnResolveCommand.universe->flights.data();
  std::size_t flightsLenght = turnResolveCommand.universe->flights.size();

  for (size_t i = 0; i < flightsLenght; ++i) {
    Flight flight = flights[i];

    ++flight.currentFlightDuration;

    if (flight.currentFlightDuration >= flight.totalFlightDuration) {
      Planet* flightDestination = flight.destination;

      if (flightDestination->owner->id == flight.owner->id) {
        flightDestination->ships += flight.ships;
      } else {
        if(flightDestination->ships >= flight.ships) {
          flightDestination->ships -= flight.ships;
        } else {
          flightDestination->owner = flight.owner;
          flightDestination->ships = flight.ships - flightDestination->ships;
        }
      }
    }
  }
}
