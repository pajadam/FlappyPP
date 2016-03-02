/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "game.hpp"

void Game::render()
{
    window.clear();
    window.draw( *level );
    window.draw( *player );
    for( int i = 0; i < 3; i++ )
        window.draw( level->ground[i] );
    if( gameMenu->isReadyToDraw( isPaused, isPlaying ) )
        window.draw( *gameMenu );
    window.display();
}
