/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "game.hpp"

Game::Game():
window( sf::VideoMode( 380, 480 ),"Flappy++", sf::Style::Close )
{
    icon.loadFromFile( "data/icon.png" );
    window.setVerticalSyncEnabled( false );
    window.setIcon( icon.getSize().x, icon.getSize().y, icon.getPixelsPtr() );
    window.setActive( true );

    atlas.loadFromFile( "data/atlas.png" );

    level  = new Map( &atlas );
    player = new Player( &atlas );

    player->reset();
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
