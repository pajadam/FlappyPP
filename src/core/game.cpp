#include "game.hpp"

Game::Game():
window( sf::VideoMode( 380, 480 ),"Flappy++", sf::Style::Close )
{
    // Inits
    window.setVerticalSyncEnabled( false );
    window.setActive( true );

    atlas.loadFromFile( "data/atlas.png" );

    level = new Map( &atlas );
    player = new Player( &atlas );
}

Game::~Game()
{
    // Destructor
}

void Game::Run()
{
    //init
    gameloop(); //main loop
    //handle exit
}
