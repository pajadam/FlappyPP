/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  */

#define ATLAS_PIPE   sf::IntRect( 1, 194, 48, 300 )
#define ATLAS_GROUND sf::IntRect( 1, 0, 48, 194 )
#define ATLAS_BACKGR sf::IntRect( 0, 14, 1, 480)

#define GROUND_X_0 194
#define GROUND_X_1 388
#define GROUND_X_2 582
#define GROUND_Y 432

#include "map.h"

Map::Map( sf::Texture *textureAtlas )
{
    for( int i = 0; i < PIPE_AMOUNT; i++ )
    {
        pipeTop[i].setTexture( *textureAtlas );
        pipeBottom[i].setTexture( *textureAtlas );

        pipeTop[i].setTextureRect( ATLAS_PIPE );
        pipeBottom[i].setTextureRect( ATLAS_PIPE );

        positionPipe( i, i * x_spacing );
    }

    ground[0].setTexture( *textureAtlas );
    ground[1].setTexture( *textureAtlas );
    ground[2].setTexture( *textureAtlas );

    ground[0].setTextureRect( ATLAS_GROUND );
    ground[1].setTextureRect( ATLAS_GROUND );
    ground[2].setTextureRect( ATLAS_GROUND );

    ground[0].rotate( 90 );
    ground[1].rotate( 90 );
    ground[2].rotate( 90 );

    ground[0].setPosition( GROUND_X_0, GROUND_Y );
    ground[1].setPosition( GROUND_X_1, GROUND_Y );
    ground[2].setPosition( GROUND_X_2, GROUND_Y );

    backgroundSprite.setTexture( *textureAtlas );
    backgroundSprite.setTextureRect( ATLAS_BACKGR );
    backgroundSprite.scale(sf::Vector2f( 380, 1.f));
}


void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(backgroundSprite);

    for(int i = 0; i < PIPE_AMOUNT; i++)
    {
        target.draw(pipeTop[i]);
        target.draw(pipeBottom[i]);
    }

    target.draw(ground[0]);
    target.draw(ground[1]);
    target.draw(ground[2]);
}

void Map::positionPipe( int pipeNumber )
{
    if( pipeNumber > PIPE_AMOUNT || pipeNumber < 0 )
        return;

    int y = rand() % 250 - 260;

    pipeTop[pipeNumber].setPosition(460 + x_spacing, y);
    pipeBottom[pipeNumber].setPosition(460 + x_spacing, y + 300 + y_spacing);
}

void Map::positionPipe( int pipeNumber, int x_offsets )
{
    if( pipeNumber > PIPE_AMOUNT || pipeNumber < 0 )
        return;

    int y = rand() % 250 - 260;

    pipeTop[pipeNumber].setPosition(460 + x_spacing + x_offsets, y);
    pipeBottom[pipeNumber].setPosition(460 + x_spacing + x_offsets, y + 300 + y_spacing);
}

bool Map::update( Player &player )
{
    ground[0].move(-speed,0);
    ground[1].move(-speed,0);
    ground[2].move(-speed,0);

    if( ground[0].getPosition().x < 0 )
    {
        ground[0].setPosition( GROUND_X_0 + ground[0].getPosition().x , GROUND_Y);
        ground[1].setPosition( GROUND_X_1 + ground[0].getPosition().x - 194 , GROUND_Y);
        ground[2].setPosition( GROUND_X_2 + ground[0].getPosition().x - 194 , GROUND_Y);
    }

    for(int i = 0; i < PIPE_AMOUNT; i++)
    {
        pipeTop[i].move(-speed,0);
        pipeBottom[i].move(-speed,0);

        if(pipeTop[i].getPosition().x < 50 && !collected[i])
        {
            score++;
            collected[i] = true;
        }

        if(player.flappy.getGlobalBounds().intersects( pipeTop[i].getGlobalBounds()  ) ||
           player.flappy.getGlobalBounds().intersects( pipeBottom[i].getGlobalBounds() ))
        {
            //return true; // Don't check it for now, I'm working on it :D
        }

        if(pipeTop[i].getPosition().x < -48)
        {
            positionPipe(i, -( x_spacing / 2 ));
            collected[i] = false;
        }
    }

    return false;
}
