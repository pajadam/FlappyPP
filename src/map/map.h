/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "../player/player.hpp"

#define PIPE_AMOUNT 3

class Player;

class Map : public sf::Drawable
{
public:
    Map( sf::Texture *textureAtlas ); // Constructor
    void update( Player &player );    // Logic update per tick

    void positionPipe( int pipeNumber, int x_offsets );// setting pipe position
    void positionPipe( int pipeNumber );               // Overloaded function,

    void updateGround();
    void reset();

    unsigned int score = 0;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const int x_spacing = 200; // Pipe spacing
          int y_spacing = 150; // May be changed during runtime ( difficulty )
          int speed     = 2;   // @up

    sf::Sprite backgroundSprite;
    sf::Sprite pipeBottom[ PIPE_AMOUNT ];
    sf::Sprite pipeTop[ PIPE_AMOUNT ];
    sf::Sprite ground[3];
    bool collected[ PIPE_AMOUNT ];
};

#endif // MAP_H
