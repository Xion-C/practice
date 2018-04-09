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
    virtual const SDL_Surface* getSurface() const {
        return images[currentFrame]->getSurface();
    }

    bool isJump() const {
        return (motion_state & 4);
    }

    void setMotion(int s) {
        motion_state = s;
    }


    void right();
    void left();
    void up();
    void down();
    void jump();
    void crouch();
    void stop();


    void attach( SmartSprite* o ) {
        observers.push_back(o);
    }
    void detach( SmartSprite* o );

private:
    std::vector<Image *> images;
    Image* idle_frame;
    Image* jump_frame;
    Image* crouch_frame;
    // 0b0000 (down, up, walk, oirentation)
    Uint8 motion_state;

    unsigned currentFrame;
    unsigned numberOfFrames;
    unsigned frameInterval;
    float timeSinceLastFrame;
    int worldWidth;
    int worldHeight;

    Vector2f initialVelocity;
    float initialY;
    float jump_height;
    float acceleration;

    void advanceFrame(Uint32 ticks);

    Player& operator=(const Player&);

    std::list<SmartSprite*> observers;

};

#endif
