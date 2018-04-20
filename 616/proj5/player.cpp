#include "gamedata.h"
#include "player.h"
#include "smartSprite.h"
// #include "smartMultiSprite.h"
#include "bullet.h"
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

Player::Player( const std::string& name, const std::string& bullet) :
    Drawable(name,
             Vector2f(Gamedata::getInstance().getXmlInt(name+"/startLoc/x"),
                      Gamedata::getInstance().getXmlInt(name+"/startLoc/y")),
             Vector2f(Gamedata::getInstance().getXmlInt(name+"/speedX"),
                      Gamedata::getInstance().getXmlInt(name+"/speedY"))
             ),
    walkFrames( ImageFactory::getInstance().getImages(name) ),
    idleFrame(ImageFactory::getInstance().getImage(name+"/idle")),
    jumpFrame(ImageFactory::getInstance().getImage(name+"/jump")),
    crouchFrame(ImageFactory::getInstance().getImage(name+"/crouch")),
    motionState(0),
    currentFrame(0),
    numberOfFrames( Gamedata::getInstance().getXmlInt(name+"/frames") ),
    frameInterval( Gamedata::getInstance().getXmlInt(name+"/frameInterval")),
    timeSinceLastFrame( 0 ),
    worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
    worldHeight(Gamedata::getInstance().getXmlInt("world/height")),
    initialVelocity(getVelocity()),
    initialPos(getPosition()),
    jumpHeight(Gamedata::getInstance().getXmlInt(name+"/jump/height")),
    acceleration((getVelocityY() * getVelocityY()) / (2 * jumpHeight)),
    observers(),
    explosion(nullptr),
    bulletName(bullet),
    bullets(bulletName)
{
    setVelocity(Vector2f(0, 0));
}

// Player::Player(const Player& s) :
//     Drawable(s),
//     walkFrames(s.walkFrames),
//     idleFrame(s.idleFrame),
//     jumpFrame(s.jumpFrame),
//     crouchFrame(s.crouchFrame),
//     motionState(s.motionState),
//     currentFrame(s.currentFrame),
//     numberOfFrames( s.numberOfFrames ),
//     frameInterval( s.frameInterval ),
//     timeSinceLastFrame( s.timeSinceLastFrame ),
//     worldWidth( s.worldWidth ),
//     worldHeight( s.worldHeight ),
//     initialVelocity( s.initialVelocity ),
//     initialPos( s.initialPos ),
//     jumpHeight( s.jumpHeight ),
//     acceleration( s.acceleration),
//     observers( s.observers ),
//     explosion( s.explosion ),
//     bulletName( s.bulletName ),
//     bullets( s.bullets )
// {
// }

Player::~Player() {
    if(explosion) delete explosion;
}

// Player& Player::operator=(const Player& s) {
//     Drawable::operator=(s);
//     walkFrames = s.walkFrames;
//     idleFrame = s.idleFrame;
//     jumpFrame = s.jumpFrame;
//     crouchFrame = s.crouchFrame;
//     motionState = s.motionState;
//     currentFrame = (s.currentFrame);
//     numberOfFrames = ( s.numberOfFrames );
//     frameInterval = ( s.frameInterval );
//     timeSinceLastFrame = ( s.timeSinceLastFrame );
//     worldWidth = ( s.worldWidth );
//     worldHeight = ( s.worldHeight );
//     initialVelocity = ( s.initialVelocity );
//     initialPos = s.initialPos;
//     jumpHeight = s.jumpHeight;
//     acceleration = s.acceleration;
//     explosion = s.explosion;
//     bulletName = s.bulletName;
//     //bullets = s.bullets;
//     return *this;
// }

void Player::draw() const {
    bullets.draw();

    if ( explosion ) {
        explosion->draw();
        return;
    }

    // walkFrames[currentFrame]->draw(getX(), getY(), getScale());
    // if(getVelocityX() >= 0) {
    if((motionState & 1) == 0) { //0b00000001, right
        if(motionState < 2) {
            idleFrame->draw(getX(), getY(), getScale());
        }
        else if(isJump()) {
            jumpFrame->draw(getX(), getY(), getScale());
        }
        else if(motionState & 8) {
            crouchFrame->draw(getX(), getY(), getScale());
        }
        else {
            walkFrames[currentFrame]->draw(getX(), getY(), getScale());
        }
    }
    else { //left
        SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
        if(motionState < 2) {
            idleFrame->draw(getX(), getY(), getScale(), flip);
        }
        else if(isJump()) {
            jumpFrame->draw(getX(), getY(), getScale(), flip);
        }
        else if(motionState & 8) {
            crouchFrame->draw(getX(), getY(), getScale(), flip);
        }
        else {
            walkFrames[currentFrame]->draw(getX(), getY(), getScale(), flip);
        }
    }
    std::string vel_str = "Player Velocity: " + \
                          std::to_string(int(getVelocityX()))+ \
                          ", " + std::to_string(int(getVelocityY()));
    //HUD::getInstance().addLine(vel_str, -2);
    InfoHUD::getInstance().addLine(vel_str);
    std::string pos_str = "Player Position: " + \
                          std::to_string(int(getX()))+ \
                          ", " + std::to_string(int(getY()));
    //HUD::getInstance().addLine(pos_str, -3);
    InfoHUD::getInstance().addLine(pos_str);
    std::string motionStr;
    if(isJump()) {
        motionStr = "Jump";
    }
    else if(motionState & 8) {
        motionStr = "Crouch";
    }
    else if(motionState & 2) {
        motionStr = "Walk";
    }
    else {
        motionStr = "Idle";
    }
    //HUD::getInstance().addLine("Motion: " + motionStr, -4);
    InfoHUD::getInstance().addLine("Motion: " + motionStr);
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
                      walkFrames[currentFrame]);
        explosion = new ExplodingSprite(sprite);
    }
}

void Player::reset() {
    setPosition(initialPos);
    setVelocity(Vector2f(0, 0));
}

void Player::shoot() {
    Vector2f target;
    if(isRight()) {
        target = Vector2f(
            getX() +
            Gamedata::getInstance().getXmlInt(getName()+"/attackRange"),
            getY()
            );
    }
    else {
        target = Vector2f(
            getX() -
            Gamedata::getInstance().getXmlInt(getName()+"/attackRange"),
            getY()
            );
    }
    bullets.shoot(getPosition(), target,
                  Gamedata::getInstance().getXmlInt(bulletName+"/speed"));
}

void Player::update(Uint32 ticks) {
    bullets.update(ticks);

    if ( explosion ) {
        explosion->update(ticks);
        if ( explosion->chunkCount() == 0 ) {
            delete explosion;
            explosion = NULL;
            reset();
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

        // if(dynamic_cast<SmartMultiSprite*>(*iter)) {
        //     dynamic_cast<SmartMultiSprite*>(*iter)->setPlayerPos( getPosition() );
        // }

        if(dynamic_cast<Bullet*>(*iter)) {
            dynamic_cast<Bullet*>(*iter)->setPlayerPos( getPosition() );
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
