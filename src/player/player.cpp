#include "player.hpp"

Player::Player( sf::Texture *tex )
{
    flappy.setTexture( *tex );
    flappy.setTextureRect( sf::IntRect( 49, 426, 34, 24) );
}

void Player::update( bool mouseClick, Map *map )
{
    animation_timer++;

    if( animation_timer == ANIMATION_TICKS )
    {
        flappy.setTextureRect( sf::IntRect( 49, 450, 34, 24) );
    }else
    if( animation_timer == ANIMATION_TICKS * 2 )
    {
        flappy.setTextureRect( sf::IntRect( 49, 426, 34, 24) );
        animation_timer = 0;
    }
}

void Player::reset()
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw( flappy );
}
