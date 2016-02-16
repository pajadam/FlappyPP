/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

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
    Game(); // Constructor
    ~Game();// Destructor

    void Run();// Start game

private:
    void gameloop();// Main game loop
    void update();  // Logic update per tick
    void render();  // Drawing on screen
    void events();  // Handling events

    sf::Time timeSinceLastUpdate;
    sf::RenderWindow window; // Game window
    sf::Texture atlas; // Texture atlas
    sf::Clock clock; // Game loop clock
    sf::Event event;
    sf::Image icon;

    Map     *level;
    Player  *player;

    bool mouseLeftClick = false;
    bool isPaused       = false;
    bool isFocused      = true;
    bool isPlaying      = false;

    const sf::Time TimePerFrame = sf::seconds( 1.f / 60.f ); // 60TPS
};

#endif // GAME_HPP
