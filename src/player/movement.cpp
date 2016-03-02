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
    velocity += MAP_GRAVITY;
    rotation += ROTATION_AMOUNT;

    if( flappy.getPosition().x > GAME_POS_X && isAlive )
        flappy.move( -1, 0 );

    if( isReadyUp )
        if( flappy.getPosition().y > MIN_Y )
            tap( true );

    if( !isReadyUp && !isAlive ){
        //death animation
        if( flappy.getPosition().y >= GROUND_FALLING_Y )
        {
            death_timer--;
            animation_timer = 0;
        }
        if( death_timer == 0 )
        {
            death_timer = DEATH_COOLDOWN;
            isAlive = false;
            isReadyUp = true;
            return;
        }
    }
    if( flappy.getPosition().y < GROUND_FALLING_Y  )
    {
        flappy.move( 0, velocity );
        flappy.setRotation( rotation );
    }else
    {
        hit();
    }

}
