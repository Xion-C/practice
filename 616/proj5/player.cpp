#include "gamedata.h"
#include "player.h"
#include "smartSprite.h"
#include "smartMultiSprite.h"
#include "imageFactory.h"
#include "hud.h"
#include "infoHUD.h"
#include "explodingSprite.h"

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
    motionState(0),
    currentFrame(0),
    numberOfFrames( Gamedata::getInstance().getXmlInt(name+"/frames") ),
    frameInterval( Gamedata::getInstance().getXmlInt(name+"/frameInterval")),
    timeSinceLastFrame( 0 ),
    worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
    worldHeight(Gamedata::getInstance().getXmlInt("world/height")),
    initialVelocity(getVelocity()),
    initialPos(getPosition()),
    jump_height(Gamedata::getInstance().getXmlInt(name+"/jump/height")),
    acceleration((getVelocityY() * getVelocityY()) / (2 * jump_height)),
    observers(),
    explosion(nullptr)
{
    setVelocity(Vector2f(0, 0));
}

Player::Player(const Player& s) :
    Drawable(s),
    images(s.images),
    idle_frame(s.idle_frame),
    jump_frame(s.jump_frame),
    crouch_frame(s.crouch_frame),
    motionState(s.motionState),
    currentFrame(s.currentFrame),
    numberOfFrames( s.numberOfFrames ),
    frameInterval( s.frameInterval ),
    timeSinceLastFrame( s.timeSinceLastFrame ),
    worldWidth( s.worldWidth ),
    worldHeight( s.worldHeight ),
    initialVelocity( s.initialVelocity ),
    initialPos( s.initialPos ),
    jump_height( s.jump_height ),
    acceleration( s.acceleration),
    observers( s.observers ),
    explosion( s.explosion )
{
}

Player& Player::operator=(const Player& s) {
    Drawable::operator=(s);
    images = s.images;
    idle_frame = s.idle_frame;
    jump_frame = s.jump_frame;
    crouch_frame = s.crouch_frame;
    motionState = s.motionState;
    currentFrame = (s.currentFrame);
    numberOfFrames = ( s.numberOfFrames );
    frameInterval = ( s.frameInterval );
    timeSinceLastFrame = ( s.timeSinceLastFrame );
    worldWidth = ( s.worldWidth );
    worldHeight = ( s.worldHeight );
    initialVelocity = ( s.initialVelocity );
    initialPos = s.initialPos;
    jump_height = s.jump_height;
    acceleration = s.acceleration;
    explosion = s.explosion;
    return *this;
}

void Player::draw() const {
    if ( explosion ) {
        explosion->draw();
        return;
    }

    // images[currentFrame]->draw(getX(), getY(), getScale());
    // if(getVelocityX() >= 0) {
    if((motionState & 1) == 0) { //0b00000001, right
        if(motionState < 2) {
            idle_frame->draw(getX(), getY(), getScale());
        }
        else if(isJump()) {
            jump_frame->draw(getX(), getY(), getScale());
        }
        else if(motionState & 8) {
            crouch_frame->draw(getX(), getY(), getScale());
        }
        else {
            images[currentFrame]->draw(getX(), getY(), getScale());
        }
    }
    else { //left
        SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
        if(motionState < 2) {
            idle_frame->draw(getX(), getY(), getScale(), flip);
        }
        else if(isJump()) {
            jump_frame->draw(getX(), getY(), getScale(), flip);
        }
        else if(motionState & 8) {
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
    InfoHUD::getInstance().addLine(vel_str);
    std::string pos_str = "Player Position: " + \
                          std::to_string(int(getX()))+ \
                          ", " + std::to_string(int(getY()));
    HUD::getInstance().addLine(pos_str, -3);
    InfoHUD::getInstance().addLine(pos_str);
    std::string motion_str;
    if(isJump()) {
        motion_str = "Jump";
    }
    else if(motionState & 8) {
        motion_str = "Crouch";
    }
    else if(motionState & 2) {
        motion_str = "Walk";
    }
    else {
        motion_str = "Idle";
    }
    HUD::getInstance().addLine("Motion: " + motion_str, -4);
}

void Player::stop() {
    motionState &= 5; //0b00000101
    if(!isJump()) {
        setVelocity( Vector2f(0, 0) );
    }
    else {
        setVelocityX(0);
    }
    //currentFrame = 0;
}

void Player::right() {
    if(!(motionState & 8)) {
        if ( getX() < worldWidth-getScaledWidth()) {
            setVelocityX(initialVelocity[0]);
        }
        motionState |= 2; //walk
    }
    motionState &= ~1;  //0b11111110
}
void Player::left() {
    if(!(motionState & 8)) {
        if ( getX() > 0 ) {
            setVelocityX(-initialVelocity[0]);
        }
        motionState |= 2; //walk
    }
    motionState |= 1; //0b00000001
}
void Player::up() {
    if ( getY() > 0) {
        setVelocityY( -initialVelocity[1] );
    }
    motionState |= 4; //0b0100
}
void Player::down() {
    if ( getY() < worldHeight-getScaledHeight()) {
        setVelocityY( initialVelocity[1] );
    }
    motionState |= 8; //0b1000;
}

void Player::jump() {
    if(!isJump()) {
        if ( getY() > 0) {
            setVelocityY( -initialVelocity[1] );
        }
        motionState |= 4; //0b0100
    }
}

void Player::crouch() {
    if(!isJump()) {
        motionState |= 8; //Crouch
        motionState &= ~2; //stop walk
        setVelocityX(0);
    }
}

void Player::explode() {
    if ( !explosion ) {
        Sprite sprite(getName(),
                      getPosition(), 0.2f * initialVelocity,
                      images[currentFrame]);
        explosion = new ExplodingSprite(sprite);
    }
}

void Player::resetPlayer() {
    setPosition(initialPos);
    setVelocity(initialVelocity);
}

void Player::update(Uint32 ticks) {
    if ( explosion ) {
        explosion->update(ticks);
        if ( explosion->chunkCount() == 0 ) {
            delete explosion;
            explosion = NULL;
            resetPlayer();
        }
        return;
    }

    advanceFrame(ticks);
    float t = static_cast<float>(ticks) * 0.001;
    Vector2f incr = getVelocity() * t;
    setPosition(getPosition() + incr);

    if(isJump()) {
        if(getY()>=initialPos[1]) {
            setY(initialPos[1]);
            setVelocityY(0);
            motionState &= ~4;
        }
        else {
            setVelocityY(getVelocityY() + acceleration * t);
        }
    }

    if(!(motionState & 2)) {
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
