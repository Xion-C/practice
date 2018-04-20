#ifndef PLAYER__H
#define PLAYER__H

#include <SDL.h>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include "drawable.h"
#include "vector2f.h"
#include "bulletPool.h"

class ExplodingSprite;

class Player : public Drawable {
public:
    Player(const std::string&, const std::string&);
    // Player(const Player&);
    ~Player();
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    virtual void draw() const;
    virtual void update(Uint32 ticks);

    virtual const Image* getImage() const {
        return walkFrames[currentFrame];
    }
    int getScaledWidth()  const {
        return getScale()*walkFrames[currentFrame]->getWidth();
    }
    int getScaledHeight()  const {
        return getScale()*walkFrames[currentFrame]->getHeight();
    }
    // const Vector2f getCenterPosition() const {
    //     return
    // }
    BulletPool& getBullets() {
        return bullets;
    }
    virtual const SDL_Surface* getSurface() const {
        return walkFrames[currentFrame]->getSurface();
    }
    bool isRight() const {
        return ((motionState & 1) == 0);
    }
    bool isJump() const {
        return (motionState & 4);
    }

    void setMotion(int s) {
        motionState = s;
    }

    void right();
    void left();
    void up();
    void down();
    void jump();
    void crouch();
    void stop();

    void explode();
    void reset();

    void shoot();

    void attach( Drawable* o ) {
        observers.push_back(o);
    }
    void detach( Drawable* o );


private:
    std::vector<Image *> walkFrames;
    Image* idleFrame;
    Image* jumpFrame;
    Image* crouchFrame;
    // 0b0000 (down, up, walk, oirentation)
    Uint8 motionState;

    unsigned currentFrame;
    unsigned numberOfFrames;
    unsigned frameInterval;
    float timeSinceLastFrame;
    int worldWidth;
    int worldHeight;

    Vector2f initialVelocity;
    Vector2f initialPos;
    float jumpHeight;
    float acceleration;
    std::list<Drawable*> observers;
    ExplodingSprite* explosion;
    std::string bulletName;
    BulletPool bullets;

    void advanceFrame(Uint32 ticks);

    // Player& operator=(const Player&);
};

#endif
