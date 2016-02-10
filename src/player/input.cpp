/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "player.hpp"

void Player::tap( bool force )
{
    if( isReadyUp && force == true )
    {
        rotation -= rotation + ROTATE_LEFT;
        velocity -= velocity + V_MAX;
    }else
    if( !isReadyUp && isAlive )
    {
        rotation -= rotation + ROTATE_LEFT;
        velocity -= velocity + V_MAX;
    }
}
