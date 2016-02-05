#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "../player/player.hpp"

#define PIPE_AMOUNT 3

class Player;

class Map : public sf::Drawable
{
public:
    Map( sf::Texture *tex );

    bool update( Player &player );
    void positionPipes( int pipe );
    void positionPipes( int pipe, int spacing );

    unsigned int score = 0;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const int x_spacing = 200;
    int v_spacing = 150;
    int speed = 3;

    bool collected[ PIPE_AMOUNT ];

    sf::Sprite pipeTop[ PIPE_AMOUNT ];
    sf::Sprite pipeBottom[ PIPE_AMOUNT ];
    sf::Sprite ground[2];
    sf::Sprite backgroundSprite;
};

#endif // MAP_H
