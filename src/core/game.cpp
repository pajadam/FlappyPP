/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "game.hpp"

Game::Game():
window( sf::VideoMode( 380, 480 ), "Flappy++", sf::Style::Close )
{
    icon.loadFromFile( "data/icon.png" );
    window.setVerticalSyncEnabled( false );
    window.setIcon( icon.getSize().x, icon.getSize().y, icon.getPixelsPtr() );
    window.setActive( true );

    atlas.loadFromFile( "data/atlas.png" );
    font.loadFromFile( "data/f1.ttf" );

    level  =   new Map( &atlas, &font );
    player =   new Player( &atlas );
    gameMenu = new Menu( &font );

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
    //handle saves, exit etc
 }
