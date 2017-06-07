/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "game.hpp"

void Game::update()
{
    if( isPlaying )
    {
        if( isFocused )
        {
            if( isPaused )
            {
                switch( gameMenu->updatePause( mouseLeftClick ) )
                {
                case ACTION::RESUME:
                        isPaused = false;
                    break;

                case ACTION::TO_MAIN_MENU:
                        player->reset();
                        level->reset();
                        isPlaying = false;
                    break;
                default:
                    break;
                }
            }else
            {
                player->update( mouseLeftClick );
                if( player->isAlive )
                    level->update( *player );
                if( player->isReadyUp )
                {
                    // get scores from level->score
                    player->reset();
                    level->reset();
                    isPlaying = false;
                    return;
                }
            }
        }
    }else
    {
        player->update( mouseLeftClick );
        level->updateGround();
        switch( gameMenu->updateMain( mouseLeftClick ) )
        {
        case ACTION::PLAY:
                player->Spawn();
                level->reset();
                isPlaying = true;
            break;

        case ACTION::EXIT_GAME:
                window.close();
            break;

        default:
            break;
        }
    }
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
            //window.setFramerateLimit( 15 ); Save some GPU time while in background
            break;
        case sf::Event::GainedFocus:
            isFocused = true;
            isPaused  = false;
            //window.setFramerateLimit( ReadFromSettings );
            //window.setVerticalSyncEnabled( ReadFromSettings );
            break;

        default:
            if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
                mouseLeftClick = true;
            else
            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape )
                isPaused = !isPaused;
            else
            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space )
                mouseLeftClick = true;
            break;
        }
    }
}
