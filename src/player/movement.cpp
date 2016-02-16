/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "player.hpp"

#define MAP_GRAVITY 0.5
#define ROTATION_AMOUNT 1

void Player::movement()
{
    if( flappy.getPosition().x > GAME_POS_X && isAlive )
        flappy.move( -1, 0 );
    if( isReadyUp )
        if( flappy.getPosition().y > MIN_Y )
            tap( true );

    velocity += MAP_GRAVITY;
    rotation += ROTATION_AMOUNT;

    flappy.setRotation( rotation );
    flappy.move( 0, velocity );
}
