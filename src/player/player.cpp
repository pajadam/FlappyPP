/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "player.hpp"

Player::Player( sf::Texture *textureAtlas )
{
    flappy.setTexture( *textureAtlas );
    flappy.setTextureRect( ATLAS_FLAPPY_0 );
    flappy.setPosition( MENU_POS_X, MENU_POS_Y );
}

void Player::update( bool jumpButtonClick )
{
    animation_timer++;

    if( animation_timer == ANIMATION_TICKS )
    {
        flappy.setTextureRect( ATLAS_FLAPPY_1 );
    }else
    if( animation_timer == ANIMATION_TICKS * 2 )
    {
        flappy.setTextureRect( ATLAS_FLAPPY_0 );
        animation_timer = 0;
    }

    if( jumpButtonClick )
    {
        tap( false );
    }

    movement();
}

void Player::reset()
{
    flappy.setPosition( MENU_POS_X, MENU_POS_Y );
    isAlive = false;
    isReadyUp = true;
    rotation = 0;
}

void Player::Spawn()
{
    isAlive = true;
    isReadyUp = false;
    rotation = 0;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw( flappy, states );
}
