/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#include "menu.hpp"

Menu::Menu( sf::Font *font )
{
    mFont = font;
}

Menu::~Menu()
{

}

short Menu::updateMain( bool mouseLeftClick )
{
    if( mouseLeftClick )
        return 1;
    return 0;
}

short Menu::updatePause( bool mouseLeftClick )
{
    return 0;
}

void Menu::refresh()
{
    // Reset animations, we don't need any graphical artifacts
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if( drawMain )
    {
        // Draw Main Menu
    }else
    if( drawPause )
    {
        // Draw Pause Menu
    }
}

bool Menu::isReadyToDraw( bool isPaused, bool isPlaying )
{
    if( isPaused )
    {
        if( isPlaying )
        {
            drawPause = true;
            drawMain = false;
            return true;
        }else
        {
            return false;
        }
    }else
    if( !isPlaying )
    {
        drawPause = false;
        drawMain = true;
        return true;
    }
    return false;
}

