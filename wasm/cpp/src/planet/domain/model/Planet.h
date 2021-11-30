#pragma once

#include "../../../player/domain/model/Player.h"

class Planet {
  public:
    Player* owner;
    int ships;
    int shipsPerTurn;
    int size;
    int x;
    int y;

    Planet();

    Planet(
      Player* owner,
      int ships,
      int shipsPerTurn,
      int size,
      int x,
      int y
    );
};
