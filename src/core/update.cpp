/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "game.hpp"

void Game::update()
{
    /*
     handle Game Menu
     We need to handle Player::Spawn()
     and we need create some Main Menu.

     if gameShouldBegin
     {
        player->Spawn()
        map->Reset()
        set flag to isPlaying = true
        Wait until player's death or exit button :)

        * We need to keep moving ground without moving pipes... #TODO *
     }
     */

    player->update( mouseLeftClick );
    level->update( *player );
}

void Game::events()
{
    while ( window.pollEvent( event ) )
    {
        switch ( event.type )
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::LostFocus:
            isFocused = false;
            isPaused = true;
            //window.setFramerateLimit( 15 ); Save some GPU Time when in background
            break;
        case sf::Event::GainedFocus:
            isFocused = true;
            isPaused  = false;
            //window.setFramerateLimit( ReadSettings );
            //window.setVerticalSyncEnabled( ReadSettings );
            break;

        default:
            if( event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left )
                mouseLeftClick = true;
            else
            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape )
            {
                if( isPaused == true )
                    isPaused = false;
                else isPaused = true;
            }
            break;
        }
    }
}
