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
    if( gameMenu->isReadyToDraw( isPaused, isPlaying ) )
        window.draw( *gameMenu );
    window.display();
}
