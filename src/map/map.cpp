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

Map::Map( sf::Texture *textureAtlas, sf::Font *font )
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

    points.setCharacterSize( 64 );
    points.setFont( *font );
    points.setString( "0" );
    points.setPosition( 190 - ( points.getGlobalBounds().width / 2 ), TEXT_HEIGHT );

}

void Map::reset()
{
    for( int i = 0; i < PIPE_AMOUNT; i++ )
    {
        positionPipe( i, i * x_spacing );
        collected[i] = false;
    }

    score = 0;
    points.setString( "0" );
    points.setPosition( 190 - ( points.getGlobalBounds().width / 2 ), TEXT_HEIGHT );
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw( backgroundSprite, states );
    target.draw( points, states );

    for(int i = 0; i < PIPE_AMOUNT; i++)
    {
        if( pipeTop[i].getPosition().x >= -pipeTop[i].getGlobalBounds().width &&
            pipeTop[i].getPosition().x <= 380 )
        {
            target.draw(pipeBottom[i], states );
            target.draw(pipeTop[i], states );
        }
    }
}

void Map::positionPipe( int pipeNumber )
{
    if( pipeNumber > PIPE_AMOUNT || pipeNumber < 0 )
        return;

    int y = rand() % 250 - 260;

    pipeBottom[pipeNumber].setPosition(460 + x_spacing, y + 300 + y_spacing);
    pipeTop[pipeNumber].setPosition(460 + x_spacing, y);
}

void Map::positionPipe( int pipeNumber, int x_offsets )
{
    if( pipeNumber > PIPE_AMOUNT || pipeNumber < 0 )
        return;

    int y = rand() % 250 - 260;

    pipeBottom[pipeNumber].setPosition(460 + x_spacing + x_offsets, y + 300 + y_spacing);
    pipeTop[pipeNumber].setPosition(460 + x_spacing + x_offsets, y);
}

void Map::update( Player &player )
{
    updateGround();

    for(int i = 0; i < PIPE_AMOUNT; i++)
    {
        pipeTop[i].move(-speed,0);
        pipeBottom[i].move(-speed,0);

        sf::FloatRect playerRect = player.getFlappy().getGlobalBounds();
        // Make collision rectangle smaller than sprite is.
        playerRect.left += 5;
        playerRect.width -= 10;
        playerRect.top += 3;
        playerRect.height -= 6;

        if(playerRect.intersects( pipeTop[i].getGlobalBounds()  ) ||
           playerRect.intersects( pipeBottom[i].getGlobalBounds() ))
        {
            player.hit();
            return;
        }

        if(pipeTop[i].getPosition().x < 80)
        {
            if( !collected[ i ] )
            {
                score++;
                points.setString( std::to_string( score ) );
                points.setPosition( 190 - ( points.getGlobalBounds().width / 2 ), TEXT_HEIGHT );
                collected[i] = true;
            }else
            if(pipeTop[i].getPosition().x < -48)
            {
                positionPipe(i, -( x_spacing / 2 ));
                collected[i] = false;
            }
        }
    }

    return;
}

void Map::updateGround()
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
}
