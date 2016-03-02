/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

enum ACTION
{
    ZERO,
    PLAY,
    RESUME,
    EXIT_GAME,
    TO_MAIN_MENU
};

enum BUTTON
{
    START,
    EXIT,
    OPTIONS,
    VOLUP,
    VOLDOWN,
    MUSICUP,
    MUSICDOWN,
    DIFFICULTYUP,
    DIFFICULTYDOWN,
    VSYNC,
    BACK,
    LAST
};

class Menu : public sf::Drawable
{
public:
    Menu( sf::Font *font);
    ~Menu();

    short updatePause( bool mouseLeftClick ); // Update Pause Menu
    short updateMain( bool mouseLeftClick );  // Update Main Menu

    bool isReadyToDraw( bool isPaused, bool isPlaying );

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void refresh(); // Refresh Menu Animations

    sf::Font *mFont;

    bool drawMain = true;
    bool drawPause = false;
};

#endif // MENU_HPP
