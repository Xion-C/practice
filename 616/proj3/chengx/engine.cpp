#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <iomanip>
#include "sprite.h"
#include "multisprite.h"
#include "twowayMultisprite.h"
#include "gamedata.h"
#include "engine.h"
#include "frameGenerator.h"

Engine::~Engine() {
    // delete star;
    // delete spinningStar;
    for(auto sprite : sprites_vec) {
        if(sprite != nullptr) {
            delete sprite;
        }
        else {
            throw std::string("null sprite pointer");
        }
    }
    std::cout << "Terminating program" << std::endl;
}

Engine::Engine() :
    rc( RenderContext::getInstance() ),
    io( IoMod::getInstance() ),
    clock( Clock::getInstance() ),
    renderer( rc->getRenderer() ),
    back_layer1("layer1", Gamedata::getInstance().getXmlInt("layer1/factor") ),
    back_layer2("layer2", Gamedata::getInstance().getXmlInt("layer2/factor") ),
    back_layer3("layer3", Gamedata::getInstance().getXmlInt("layer3/factor") ),
    viewport( Viewport::getInstance() ),
    // star(new Sprite("YellowStar")),
    // spinningStar(new MultiSprite("SpinningStar")),
    sprites_vec(),
    currentSprite(0),
    makeVideo( false )
{
    for(int i = 0;
        i < Gamedata::getInstance().getXmlInt("Cloud/number");
        i++) {
        sprites_vec.emplace_back(new Sprite("Cloud"));
    }
    for(int i = 0;
        i < Gamedata::getInstance().getXmlInt("Sword/number");
        i++) {
        sprites_vec.emplace_back(new MultiSprite("Sword"));
    }

    for(int i = 0;
        i < Gamedata::getInstance().getXmlInt("XCheng/number");
        i++) {
        sprites_vec.emplace_back(new TwoWayMultiSprite("XCheng"));
    }

    // Viewport::getInstance().setObjectToTrack(sprites_vec[0]);
    Viewport::getInstance().setObjectToTrack(sprites_vec[sprites_vec.size() - 1]);
    std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
    back_layer3.draw();
    back_layer2.draw();
    back_layer1.draw();

    // star->draw();
    // spinningStar->draw();

    for(auto sprite : sprites_vec) {
        sprite->draw();
    }

    viewport.draw();
    SDL_RenderPresent(renderer);
}

void Engine::update(Uint32 ticks) {
    // star->update(ticks);
    // spinningStar->update(ticks);
    for(auto sprite : sprites_vec) {
        sprite->update(ticks);
    }
    back_layer1.update();
    back_layer2.update();
    back_layer3.update();
    viewport.update(); // always update viewport last
}

void Engine::switchSprite(){
    ++currentSprite;
    if(currentSprite >= sprites_vec.size()) {
        currentSprite = 0;
    }
    Viewport::getInstance().setObjectToTrack(sprites_vec[currentSprite]);
    // currentSprite = currentSprite % 3;
    // if ( currentSprite ) {
    //     Viewport::getInstance().setObjectToTrack(spinningStar);
    // }
    // else {
    //     Viewport::getInstance().setObjectToTrack(star);
    // }
}

void Engine::play() {
    SDL_Event event;
    const Uint8* keystate;
    bool done = false;
    Uint32 ticks = clock.getElapsedTicks();
    FrameGenerator frameGen;

    while ( !done ) {
        // The next loop polls for events, guarding against key bounce:
        while ( SDL_PollEvent(&event) ) {
            keystate = SDL_GetKeyboardState(NULL);
            if (event.type ==  SDL_QUIT) { done = true; break; }
            if(event.type == SDL_KEYDOWN) {
                if (keystate[SDL_SCANCODE_ESCAPE] || keystate[SDL_SCANCODE_Q]) {
                    done = true;
                    break;
                }
                if ( keystate[SDL_SCANCODE_P] ) {
                    if ( clock.isPaused() ) clock.unpause();
                    else clock.pause();
                }
                if ( keystate[SDL_SCANCODE_T] ) {
                    switchSprite();
                }
                if (keystate[SDL_SCANCODE_F4] && !makeVideo) {
                    std::cout << "Initiating frame capture" << std::endl;
                    makeVideo = true;
                }
                else if (keystate[SDL_SCANCODE_F4] && makeVideo) {
                    std::cout << "Terminating frame capture" << std::endl;
                    makeVideo = false;
                }
            }
        }

        // In this section of the event loop we allow key bounce:

        ticks = clock.getElapsedTicks();
        if ( ticks > 0 ) {
            clock.incrFrame();
            draw();
            update(ticks);
            if ( makeVideo ) {
                frameGen.makeFrame();
            }
        }
    }
}
