/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "game.hpp"

void Game::gameloop()
{
    clock.restart();
    while( window.isOpen() )
    {
        events();
        timeSinceLastUpdate += clock.restart();
        while( timeSinceLastUpdate > TimePerFrame )
        {
            if( timeSinceLastUpdate >= sf::seconds( 2 ) )
            {
                cout << "Game looks overloaded. Holy moly... running so slooow." << endl;
                timeSinceLastUpdate = sf::seconds( 0 );
            }
            else
                timeSinceLastUpdate -= TimePerFrame;

            if( !isPaused )
            {
                update();
                mouseLeftClick = false;
            }
            else sf::sleep( sf::seconds( 0 ) );
        }
        render();
    }
}
