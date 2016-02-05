#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../map/map.h"
#include "../player/player.hpp"

using namespace std;

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:
    void gameloop();
    void update();
    void render();
    void events();

    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Event event;

    sf::Texture atlas;

    Map *level;
    Player *player;

    bool mouseLeftClick = false;
    bool isPaused = false;
    bool isFocused = true;

    const sf::Time TimePerFrame = sf::seconds( 1.f / 60.f ); //64TPS
};

#endif // GAME_HPP
