#include "game.hpp"

void Game::update()
{
    level->update( *player );
    player->update( mouseLeftClick, level );
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
            window.setFramerateLimit( 15 );
            break;
        case sf::Event::GainedFocus:
            isFocused = true;
            isPaused  = false;
            window.setFramerateLimit( 0 );
            window.setVerticalSyncEnabled( true );
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
