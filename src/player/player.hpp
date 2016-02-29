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
#define ROTATE_LEFT 25
#define MENU_POS_X 174
#define MENU_POS_Y 228
#define GAME_POS_X 80
#define MIN_Y 240
#define V_MAX 9

class Map;

class Player : public sf::Drawable
{
public:
    Player( sf::Texture *textureAtlas ); // Constructor

    void update( bool jumpButtonClick ); // Logic update per tick

    sf::Sprite getFlappy(); // Get Flappy Sprite

    void Spawn(); // Set flappy as alive with game starting position
    void reset(); // Reset position of player
    void hit();   // Flappy hits the pipe :C
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void tap( bool force = false ); // if force then ignore player state ( used for main menu AI simulation )
    void movement(); // calculate movement

    int animation_timer = 0;    // So simple... we don't need advanced animation handling :P
    bool isReadyUp      = true; // Is ready to start game?
    bool isAlive        = false;// Is alive?
    float rotation      = 0;    // Player Rotation
    float velocity      = 0;    // Player Y velocity

    sf::Texture *atlas; // Pointer to Texture Atlas
    sf::Sprite flappy;
};

#endif // PLAYER_HPP
