/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "game.hpp"

void Game::render()
{
    window.clear();
    //window.draw( cusik :D );
    window.draw( *level );
    window.draw( *player );
    window.display();
}
