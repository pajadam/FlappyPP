/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "../map/map.h"

#define ANIMATION_TICKS 10

class Map;

class Player : public sf::Drawable
{
public:
    Player( sf::Texture *textureAtlas ); // Constructor

    void update( bool mouseClick ); // Logic update per tick
    void reset(); // Reset position of player
    sf::Sprite flappy; // public sprite, needed to check collisions by map
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture *atlas;
    int animation_timer = 0; // So simple... we don't need advanced
                             // animation handling :P
};

#endif // PLAYER_HPP
