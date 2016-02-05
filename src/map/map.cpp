#include "map.h"

Map::Map( sf::Texture *tex )
{
    for( int i = 0; i < PIPE_AMOUNT; i++ )
    {
        pipeTop[i].setTexture( *tex );
        pipeBottom[i].setTexture( *tex );

        pipeTop[i].setTextureRect( sf::IntRect( 49,474,48,300 ) );
        pipeBottom[i].setTextureRect( sf::IntRect( 49,474,48,300 ) );

        positionPipes( i, i * x_spacing );
    }

    ground[0].setTexture( *tex );
    ground[1].setTexture( *tex );

    ground[0].setTextureRect( sf::IntRect( 0, 0, 48, 774 ) );
    ground[1].setTextureRect( sf::IntRect( 0, 0, 48, 774 ) );

    ground[0].rotate( 90 );
    ground[1].rotate( 90 );

    ground[0].setPosition( 0, 440 );
    ground[1].setPosition( 768, 440 );
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
}

void Map::positionPipes( int pipe )
{
    if( pipe > PIPE_AMOUNT || pipe < 0 )
        return;

    int y = rand() % 250 - 260;

    pipeTop[pipe].setPosition(460 + x_spacing, y);
    pipeBottom[pipe].setPosition(460 + x_spacing, y + 300 + v_spacing);
}

void Map::positionPipes( int pipe, int spacing )
{
    if( pipe > PIPE_AMOUNT || pipe < 0 )
        return;

    int y = rand() % 250 - 260;

    pipeTop[pipe].setPosition(460 + x_spacing + spacing, y);
    pipeBottom[pipe].setPosition(460 + x_spacing + spacing, y + 300 + v_spacing);
}

bool Map::update( Player &player )
{
    ground[0].move(-speed,0);
    ground[1].move(-speed,0);

    if(ground[0].getPosition().x < -768)
        ground[0].setPosition(0,440);
    else if(ground[1].getPosition().x < 0)
        ground[1].setPosition(768,440);

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
            //return true;
        }

        if(pipeTop[i].getPosition().x < -48)
        {
            positionPipes(i, -( x_spacing / 2 ));
            collected[i] = false;
        }
    }

    return false;
}
