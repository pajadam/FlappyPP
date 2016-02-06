/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "player.hpp"

#define ATLAS_FLAPPY_0 sf::IntRect( 49, 446, 34, 24)
#define ATLAS_FLAPPY_1 sf::IntRect( 49, 470, 34, 24)

Player::Player( sf::Texture *textureAtlas )
{
    flappy.setTexture( *textureAtlas );
    flappy.setTextureRect( ATLAS_FLAPPY_0 );
}

void Player::update( bool mouseClick )
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

    if( mouseClick )
    {
        // handle tap
    }
}

void Player::reset()
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw( flappy, states );
}
