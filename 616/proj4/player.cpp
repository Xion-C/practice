#include "gamedata.h"
#include "player.h"
#include "smartSprite.h"
#include "smartMultiSprite.h"
#include "imageFactory.h"
#include "hud.h"

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
    idle_frame(ImageFactory::getInstance().getImage(name+"/idle")),
    jump_frame(ImageFactory::getInstance().getImage(name+"/jump")),
    crouch_frame(ImageFactory::getInstance().getImage(name+"/crouch")),
    motion_state(0),
    currentFrame(0),
    numberOfFrames( Gamedata::getInstance().getXmlInt(name+"/frames") ),
    frameInterval( Gamedata::getInstance().getXmlInt(name+"/frameInterval")),
    timeSinceLastFrame( 0 ),
    worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
    worldHeight(Gamedata::getInstance().getXmlInt("world/height")),
    initialVelocity(getVelocity()),
    initialY(getY()),
    jump_height(Gamedata::getInstance().getXmlInt(name+"/jump/height")),
    acceleration((getVelocityY() * getVelocityY()) / (2 * jump_height)),
    observers()
{
}

Player::Player(const Player& s) :
    Drawable(s),
    images(s.images),
    idle_frame(s.idle_frame),
    jump_frame(s.jump_frame),
    crouch_frame(s.crouch_frame),
    motion_state(s.motion_state),
    currentFrame(s.currentFrame),
    numberOfFrames( s.numberOfFrames ),
    frameInterval( s.frameInterval ),
    timeSinceLastFrame( s.timeSinceLastFrame ),
    worldWidth( s.worldWidth ),
    worldHeight( s.worldHeight ),
    initialVelocity( s.initialVelocity ),
    initialY( s.initialY ),
    jump_height( s.jump_height ),
    acceleration( s.acceleration),
    observers( s.observers )
{
}

Player& Player::operator=(const Player& s) {
    Drawable::operator=(s);
    images = s.images;
    idle_frame = s.idle_frame;
    jump_frame = s.jump_frame;
    crouch_frame = s.crouch_frame;
    motion_state = s.motion_state;
    currentFrame = (s.currentFrame);
    numberOfFrames = ( s.numberOfFrames );
    frameInterval = ( s.frameInterval );
    timeSinceLastFrame = ( s.timeSinceLastFrame );
    worldWidth = ( s.worldWidth );
    worldHeight = ( s.worldHeight );
    initialVelocity = ( s.initialVelocity );
    initialY = s.initialY;
    jump_height = s.jump_height;
    acceleration = s.acceleration;
    return *this;
}

void Player::draw() const {
    // images[currentFrame]->draw(getX(), getY(), getScale());
    // if(getVelocityX() >= 0) {
    if((motion_state & 1) == 0) { //0b00000001
        if(motion_state < 2) {
            idle_frame->draw(getX(), getY(), getScale());
        }
        else if(isJump()) {
            jump_frame->draw(getX(), getY(), getScale());
        }
        else if(motion_state & 8) {
            crouch_frame->draw(getX(), getY(), getScale());
        }
        else {
            images[currentFrame]->draw(getX(), getY(), getScale());
        }
    }
    else {
        SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
        if(motion_state < 2) {
            idle_frame->draw(getX(), getY(), getScale(), flip);
        }
        else if(isJump()) {
            jump_frame->draw(getX(), getY(), getScale(), flip);
        }
        else if(motion_state & 8) {
            crouch_frame->draw(getX(), getY(), getScale(), flip);
        }
        else {
            images[currentFrame]->draw(getX(), getY(), getScale(), flip);
        }
    }
    std::string vel_str = "Player Velocity: " + \
                          std::to_string(int(getVelocityX()))+ \
                          ", " + std::to_string(int(getVelocityY()));
    HUD::getInstance().addLine(vel_str, -2);
    std::string motion_str;
    if(isJump()) {
        motion_str = "Jump";
    }
    else if(motion_state & 8) {
        motion_str = "Crouch";
    }
    else if(motion_state & 2) {
        motion_str = "Walk";
    }
    else {
        motion_str = "Idle";
    }
    HUD::getInstance().addLine("Motion: " + motion_str, -3);
}

void Player::stop() {
    motion_state &= 5; //0b00000101
    if(!isJump()) {
        setVelocity( Vector2f(0, 0) );
    }
    else {
        setVelocityX(0);
    }
    //currentFrame = 0;
}

void Player::right() {
    if(!(motion_state & 8)) {
        if ( getX() < worldWidth-getScaledWidth()) {
            setVelocityX(initialVelocity[0]);
        }
        motion_state |= 2; //walk
    }
    motion_state &= ~1;  //0b11111110
}
void Player::left() {
    if(!(motion_state & 8)) {
        if ( getX() > 0 ) {
            setVelocityX(-initialVelocity[0]);
        }
        motion_state |= 2; //walk
    }
    motion_state |= 1; //0b00000001
}
void Player::up() {
    if ( getY() > 0) {
        setVelocityY( -initialVelocity[1] );
    }
    motion_state |= 4; //0b0100
}
void Player::down() {
    if ( getY() < worldHeight-getScaledHeight()) {
        setVelocityY( initialVelocity[1] );
    }
    motion_state |= 8; //0b1000;
}

void Player::jump() {
    if(!isJump()) {
        if ( getY() > 0) {
            setVelocityY( -initialVelocity[1] );
        }
        motion_state |= 4; //0b0100
    }
}

void Player::crouch() {
    if(!isJump()) {
        motion_state |= 8; //Crouch
        motion_state &= ~2; //stop walk
        setVelocityX(0);
    }
}

void Player::update(Uint32 ticks) {
    advanceFrame(ticks);
    float t = static_cast<float>(ticks) * 0.001;
    Vector2f incr = getVelocity() * t;
    setPosition(getPosition() + incr);

    if(isJump()) {
        if(getY()>=initialY) {
            setY(initialY);
            setVelocityY(0);
            motion_state &= ~4;
        }
        else {
            setVelocityY(getVelocityY() + acceleration * t);
        }
    }

    if(!(motion_state & 2)) {
        currentFrame = 0;
    }

    stop();

    //update attached smart sprites
    std::list<Drawable*>::iterator iter = observers.begin();
    while ( iter != observers.end() ) {
        if(dynamic_cast<SmartSprite*>(*iter)) {
            dynamic_cast<SmartSprite*>(*iter)->setPlayerPos( getPosition() );
        }
        if(dynamic_cast<SmartMultiSprite*>(*iter)) {
            dynamic_cast<SmartMultiSprite*>(*iter)->setPlayerPos( getPosition() );
        }
        // (*iter)->setPlayerPos( getPosition() );
        ++iter;
    }

}

void Player::detach( Drawable* o ) {
    std::list<Drawable*>::iterator iter = observers.begin();
    while ( iter != observers.end() ) {
        if ( *iter == o ) {
            iter = observers.erase(iter);
            return;
        }
        ++iter;
    }
}
