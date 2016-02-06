/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "game.hpp"

Game::Game():
window( sf::VideoMode( 380, 480 ),"Flappy++", sf::Style::Close )
{
    // Inits
    window.setVerticalSyncEnabled( false );
    //window.setFramerateLimit( 60 );
    window.setActive( true );

    atlas.loadFromFile( "data/atlas.png" );

    level = new Map( &atlas );
    player = new Player( &atlas );
}

Game::~Game()
{
    if( level != nullptr )
        delete level;
    if( player != nullptr )
        delete player;
}

void Game::Run()
{
    // TODO Loading options from file
    gameloop(); //main game loop
    //handle exit
}
