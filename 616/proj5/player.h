#ifndef PLAYER__H
#define PLAYER__H

#include <SDL.h>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include "drawable.h"
#include "vector2f.h"

class SmartSprite;
class ExplodingSprite;

class Player : public Drawable {
public:
    Player(const std::string&);
    Player(const Player&);

    virtual void draw() const;
    virtual void update(Uint32 ticks);

    virtual const Image* getImage() const {
        return images[currentFrame];
    }
    int getScaledWidth()  const {
        return getScale()*images[currentFrame]->getWidth();
    }
    int getScaledHeight()  const {
        return getScale()*images[currentFrame]->getHeight();
    }
    // const Vector2f getCenterPosition() const {
    //     return
    // }
    virtual const SDL_Surface* getSurface() const {
        return images[currentFrame]->getSurface();
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
    void resetPlayer();

    void attach( Drawable* o ) {
        observers.push_back(o);
    }
    void detach( Drawable* o );


private:
    std::vector<Image *> images;
    Image* idle_frame;
    Image* jump_frame;
    Image* crouch_frame;
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
    float jump_height;
    float acceleration;
    std::list<Drawable*> observers;
    ExplodingSprite* explosion;

    void advanceFrame(Uint32 ticks);

    Player& operator=(const Player&);
};

#endif
