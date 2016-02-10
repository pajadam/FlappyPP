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
#define ATLAS_FLAPPY_0 sf::IntRect( 49, 446, 34, 24)
#define ATLAS_FLAPPY_1 sf::IntRect( 49, 470, 34, 24)
#define MENU_POS_X 174
#define MENU_POS_Y 228
#define GAME_POS_X 80
#define MIN_Y 240
#define V_MAX 9
#define ROTATE_LEFT 25

class Map;

class Player : public sf::Drawable
{
public:
    Player( sf::Texture *textureAtlas ); // Constructor

    void update( bool jumpButtonClick ); // Logic update per tick
    void Spawn(); // Set flappy as alive with game starting position
    void reset(); // Reset position of player
    sf::Sprite flappy; // public sprite, needed to check collisions by map
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void tap( bool force = false );
    void movement();

    bool isReadyUp = true;
    bool isAlive = false;
    float rotation = 0;
    float velocity = 0;

    sf::Texture *atlas;
    int animation_timer = 0; // So simple... we don't need advanced
                             // animation handling :P
};

#endif // PLAYER_HPP
