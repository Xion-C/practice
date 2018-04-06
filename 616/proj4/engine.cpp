#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <iomanip>
#include "gamedata.h"
#include "engine.h"
#include "frameGenerator.h"
#include "sprite.h"
#include "multisprite.h"
#include "twowayMultisprite.h"
#include "smartSprite.h"
#include "player.h"
#include "collisionStrategy.h"


Engine::~Engine() {
    delete player;
    for(Drawable* cloud : clouds) {
        delete cloud;
    }
    for(CollisionStrategy* strategy : strategies) {
        delete strategy;
    }
    std::cout << "Terminating program" << std::endl;
}

Engine::Engine() :
    rc( RenderContext::getInstance() ),
    io( IOMod::getInstance() ),
    clock( Clock::getInstance() ),
    renderer( rc->getRenderer() ),
    back_layer1("layer1", Gamedata::getInstance().getXmlInt("layer1/factor") ),
    back_layer2("layer2", Gamedata::getInstance().getXmlInt("layer2/factor") ),
    back_layer3("layer3", Gamedata::getInstance().getXmlInt("layer3/factor") ),
    viewport( Viewport::getInstance() ),
    player(new Player("XCheng")),
    clouds(),
    strategies(),
    currentStrategy(0),
    collision(false),
    makeVideo( false ),
    hud(renderer),
    hud_on(true)
{
    int n = Gamedata::getInstance().getXmlInt("Cloud/number");
    //clouds.reserve(n);
    Vector2f pos = player->getPosition();
    int w = player->getScaledWidth();
    int h = player->getScaledHeight();
    for(int i = 0; i < n; i++) {
        clouds.push_back(new SmartSprite("Cloud", pos, w, h));
        player->attach(clouds[i]);
    }

    strategies.push_back(new RectangularCollisionStrategy);
    strategies.push_back(new PerPixelCollisionStrategy);
    strategies.push_back(new MidPointCollisionStrategy);

    Viewport::getInstance().setObjectToTrack(player);
    std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
    back_layer3.draw();
    back_layer2.draw();
    back_layer1.draw();

    for(auto cloud : clouds) {
        cloud->draw();
    }
    // if ( collision ) {
    //     IOMod::getInstance().writeText("Oops: Collision", 500, 90);
    // }

    player->draw();

    if(hud_on) hud.display();

    viewport.draw();
    SDL_RenderPresent(renderer);
}

void Engine::checkForCollisions() {
    auto it = clouds.begin();
    while ( it != clouds.end() ) {
        // if ( strategies[currentStrategy]->execute(*player, **it) ) {
        //     SmartSprite* doa = *it;
        //     player->detach(doa);
        //     delete doa;
        //     it = clouds.erase(it);
        //     collision = true;
        // }
        // else ++it;

        // ai
        if ( strategies[currentStrategy]->execute(*player, **it) ) {
            // SmartSprite* doa = *it;
            // // int player_signX = player->getVelocityX() > 0 ? 1 : -1;
            // // int cloud_singX = doa->getVelocityX() >0 ? 1 : -1;
            // doa->setVelocity(-2 * (doa->getVelocity()));
        }
        it++;

    }
}

void Engine::update(Uint32 ticks) {
    collision = false;
    checkForCollisions();

    player->update(ticks);

    for(auto cloud : clouds) {
        cloud->update(ticks);
    }

    back_layer1.update();
    back_layer2.update();
    back_layer3.update();

    viewport.update(); // always update viewport last
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
                if ( keystate[SDL_SCANCODE_M] ) {
                    currentStrategy = (1 + currentStrategy) % strategies.size();
                }
                if (keystate[SDL_SCANCODE_F4] && !makeVideo) {
                    std::cout << "Initiating frame capture" << std::endl;
                    makeVideo = true;
                }
                else if (keystate[SDL_SCANCODE_F4] && makeVideo) {
                    std::cout << "Terminating frame capture" << std::endl;
                    makeVideo = false;
                }
                if (keystate[SDL_SCANCODE_F1]) {
                    hud_on = !hud_on;
                }
            }
        }

        // In this section of the event loop we allow key bounce:

        ticks = clock.getElapsedTicks();
        if ( ticks > 0 ) {
            clock.incrFrame();

            // movement control
            // bool stop = true;
            if (keystate[SDL_SCANCODE_A]) {
                static_cast<Player*>(player)->left();
                // stop = false;
            }
            if (keystate[SDL_SCANCODE_D]) {
                static_cast<Player*>(player)->right();
                // stop = false;
            }
            if (keystate[SDL_SCANCODE_W]) {
                static_cast<Player*>(player)->up();
                // stop = false;
            }
            if (keystate[SDL_SCANCODE_S]) {
                static_cast<Player*>(player)->down();
                // stop = false;
            }
            // if(stop) {
            //     static_cast<Player*>(player)->stop();
            // }
            draw();
            update(ticks);
            if ( makeVideo ) {
                frameGen.makeFrame();
            }
        }
    }
}
