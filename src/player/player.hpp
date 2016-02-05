#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "../map/map.h"

#define ANIMATION_TICKS 10

class Map;

class Player : public sf::Drawable
{
public:
    Player( sf::Texture *tex );

    void update( bool mouseClick, Map *map );
    void reset();
    sf::Sprite flappy;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture *atlas;
    int animation_timer = 0;
};

#endif // PLAYER_HPP
