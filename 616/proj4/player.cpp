#include "gamedata.h"
#include "player.h"
#include "smartSprite.h"
#include "imageFactory.h"

#include <iostream>

void Player::advanceFrame(Uint32 ticks) {
    timeSinceLastFrame += ticks;
    if (timeSinceLastFrame > frameInterval) {
        currentFrame = (currentFrame+1) % numberOfFrames;
        timeSinceLastFrame = 0;
    }
}

Player::Player( const std::string& name) :
    Drawable(name,
             Vector2f(Gamedata::getInstance().getXmlInt(name+"/startLoc/x"),
                      Gamedata::getInstance().getXmlInt(name+"/startLoc/y")),
             Vector2f(Gamedata::getInstance().getXmlInt(name+"/speedX"),
                      Gamedata::getInstance().getXmlInt(name+"/speedY"))
             ),
    images( ImageFactory::getInstance().getImages(name) ),
    idle_frames(ImageFactory::getInstance().getImages(name+"/idle")),
    motion_state(0),

    currentFrame(0),
    numberOfFrames( Gamedata::getInstance().getXmlInt(name+"/frames") ),
    frameInterval( Gamedata::getInstance().getXmlInt(name+"/frameInterval")),
    timeSinceLastFrame( 0 ),
    worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
    worldHeight(Gamedata::getInstance().getXmlInt("world/height")),
    initialVelocity(getVelocity()),
    observers()
{
}

Player::Player(const Player& s) :
    Drawable(s),
    images(s.images),
    idle_frames(s.idle_frames),
    motion_state(s.motion_state),
    currentFrame(s.currentFrame),
    numberOfFrames( s.numberOfFrames ),
    frameInterval( s.frameInterval ),
    timeSinceLastFrame( s.timeSinceLastFrame ),
    worldWidth( s.worldWidth ),
    worldHeight( s.worldHeight ),
    initialVelocity( s.initialVelocity ),
    observers( s.observers )
{
}

Player& Player::operator=(const Player& s) {
    Drawable::operator=(s);
    images = s.images;
    idle_frames = s.idle_frames;
    motion_state = s.motion_state;
    currentFrame = (s.currentFrame);
    numberOfFrames = ( s.numberOfFrames );
    frameInterval = ( s.frameInterval );
    timeSinceLastFrame = ( s.timeSinceLastFrame );
    worldWidth = ( s.worldWidth );
    worldHeight = ( s.worldHeight );
    initialVelocity = ( s.initialVelocity );
    return *this;
}

void Player::draw() const {
    // images[currentFrame]->draw(getX(), getY(), getScale());
    // if(getVelocityX() >= 0) {
    if((motion_state & 1) == 0) {
        if(motion_state < 2) { //14: 0b1110
            idle_frames[0]->draw(getX(), getY(), getScale());
        }
        else {
            images[currentFrame]->draw(getX(), getY(), getScale());
        }
    }
    else {
        SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
        if(motion_state < 2) {
            idle_frames[0]->draw(getX(), getY(), getScale(), flip);
        }
        else {
            images[currentFrame]->draw(getX(), getY(), getScale(), flip);
        }
    }
}

void Player::stop() {
    // if(getVelocityX() >= 0) {
    //     motion_state = 0; // 0b0000
    // }
    // else {
    //     motion_state = 1; // 0b0001
    // }
    motion_state &= 1;
    setVelocity( Vector2f(0, 0) );
    //currentFrame = 0;
}

void Player::right() {
    if ( getX() < worldWidth-getScaledWidth()) {
        setVelocityX(initialVelocity[0]);
    }
    motion_state = 2; //0b0010
}
void Player::left()  {
    if ( getX() > 0) {
        setVelocityX(-initialVelocity[0]);
    }
    motion_state = 3; //0b0011
}
void Player::up()    {
    if ( getY() > 0) {
        setVelocityY( -initialVelocity[1] );
    }
    motion_state |= 4; //0b0100;
}
void Player::down()  {
    if ( getY() < worldHeight-getScaledHeight()) {
        setVelocityY( initialVelocity[1] );
    }
    motion_state |= 8; //0b1000;
}

void Player::update(Uint32 ticks) {
    advanceFrame(ticks);

    Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
    setPosition(getPosition() + incr);

    if ( getY() < 0) {
        setVelocityY( fabs( getVelocityY() ) );
    }
    if ( getY() > worldHeight-getScaledHeight()) {
        setVelocityY( -fabs( getVelocityY() ) );
    }

    if ( getX() < 0) {
        setVelocityX( fabs( getVelocityX() ) );
    }
    if ( getX() > worldWidth-getScaledWidth()) {
        setVelocityX( -fabs( getVelocityX() ) );
    }

    stop();

    //update attached smart sprites
    std::list<SmartSprite*>::iterator iter = observers.begin();
    while ( iter != observers.end() ) {
        (*iter)->setPlayerPos( getPosition() );
        ++iter;
    }

}

void Player::detach( SmartSprite* o ) {
    std::list<SmartSprite*>::iterator iter = observers.begin();
    while ( iter != observers.end() ) {
        if ( *iter == o ) {
            iter = observers.erase(iter);
            return;
        }
        ++iter;
    }
}
