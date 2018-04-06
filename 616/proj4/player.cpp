#include "gamedata.h"
#include "player.h"
#include "smartSprite.h"
#include <iostream>

Player::Player( const std::string& name) :
    player(name),
    initialVelocity(player.getVelocity()),
    worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
    worldHeight(Gamedata::getInstance().getXmlInt("world/height")),
    observers()
{
    std::cout << "volocity: " << initialVelocity << std::endl;
}

void Player::stop() {
    player.setVelocity( Vector2f(0, 0) );
}

void Player::right() {
    if ( player.getX() < worldWidth-getScaledWidth()) {
        player.setVelocityX(initialVelocity[0]);
    }
}
void Player::left()  {
    if ( player.getX() > 0) {
        player.setVelocityX(-initialVelocity[0]);
    }
}
void Player::up()    {
    if ( player.getY() > 0) {
        player.setVelocityY(-initialVelocity[1]);
    }
}
void Player::down()  {
    if ( player.getY() < worldHeight-getScaledHeight()) {
        player.setVelocityY(initialVelocity[1]);
    }
}

void Player::update(Uint32 ticks) {
    player.update(ticks);
    stop();
    std::list<SmartSprite*>::iterator iter = observers.begin();
    while ( iter != observers.end() ) {
        (*iter)->setPlayerPos( getPosition() );
        ++iter;
    }
}

void SubjectSprite::detach( SmartSprite* o ) {
    std::list<SmartSprite*>::iterator iter = observers.begin();
    while ( iter != observers.end() ) {
        if ( *iter == o ) {
            iter = observers.erase(iter);
            return;
        }
        ++iter;
    }
}
