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
#include "smartSprite.h"
#include "smartMultiSprite.h"
#include "player.h"
#include "collisionStrategy.h"


Engine::~Engine() {
    delete player;
    for(auto cloud : clouds) {
        delete cloud;
    }
    // for(auto sword : swords) {
    //     delete sword;
    // }
    for(CollisionStrategy* strategy : strategies) {
        delete strategy;
    }
    // delete player;
    std::cout << "Terminating program" << std::endl;
}

Engine::Engine() :
    rc( RenderContext::getInstance() ),
    io( IOMod::getInstance() ),
    clock( Clock::getInstance() ),
    renderer( rc->getRenderer() ),
    ground("Ground", Gamedata::getInstance().getXmlInt("Ground/factor") ),
    mountain("Mountain", Gamedata::getInstance().getXmlInt("Mountain/factor") ),
    sky("Sky", Gamedata::getInstance().getXmlInt("Sky/factor") ),
    viewport( Viewport::getInstance() ),
    player( new Player("XCheng") ),
    clouds(),
    swords(),
    strategies(),
    currentStrategy( 0 ),
    collision( false ),
    makeVideo( false ),
    hud_on( true ),
    hud( HUD::getInstance() )
{
    Vector2f pos = player->getPosition();
    int w = player->getScaledWidth();
    int h = player->getScaledHeight();

    int n = Gamedata::getInstance().getXmlInt("Cloud/number");
    for(int i = 0; i < n; i++) {
        clouds.push_back(new SmartSprite("Cloud", pos, w, h));
        player->attach(clouds[i]);
    }
    n = Gamedata::getInstance().getXmlInt("Sword/number");
    for(int i = 0; i < n; i++) {
        swords.push_back(new SmartMultiSprite("Sword", pos, w, h));
        // swords[i]->setVelocityY(0);
        player->attach(swords[i]);
    }

    strategies.push_back(new RectangularCollisionStrategy);
    strategies.push_back(new PerPixelCollisionStrategy);
    strategies.push_back(new MidPointCollisionStrategy);

    Viewport::getInstance().setObjectToTrack(player);
    std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
    sky.draw();
    mountain.draw();
    ground.draw();

    for(auto cloud : clouds) {
        cloud->draw();
    }
    for(auto sword : swords) {
        sword->draw();
    }

    player->draw();

    viewport.draw();
    strategies[currentStrategy]->draw();
    std::stringstream strm;
    strm << "Swords Remaining: " << swords.size();
    HUD::getInstance().addLine(strm.str(), -4);
    if(hud_on) hud.draw();

    SDL_RenderPresent(renderer);
}

void Engine::checkForCollisions() {
    auto it = swords.begin();
    while ( it != swords.end() ) {
        if ( strategies[currentStrategy]->execute(*player, **it) ) {
            SmartMultiSprite* doa = *it;
            player->detach(dynamic_cast<Drawable*>(doa));
            delete doa;
            it = swords.erase(it);
        }
        else it++;

    }
}

void Engine::update(Uint32 ticks) {
    collision = false;
    checkForCollisions();

    player->update(ticks);

    for(auto cloud : clouds) {
        cloud->update(ticks);
    }
    for(auto sword : swords) {
        sword->update(ticks);
    }


    ground.update();
    mountain.update();
    sky.update();

    viewport.update(); // always update viewport last
    hud.update();
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
            if (keystate[SDL_SCANCODE_A]) {
                static_cast<Player*>(player)->left();
            }
            if (keystate[SDL_SCANCODE_D]) {
                static_cast<Player*>(player)->right();
            }
            if (keystate[SDL_SCANCODE_W]) {
                // static_cast<Player*>(player)->up();
                static_cast<Player*>(player)->jump();
            }
            if (keystate[SDL_SCANCODE_S]) {
                // static_cast<Player*>(player)->down();
                static_cast<Player*>(player)->crouch();
            }
            draw();
            update(ticks);
            if ( makeVideo ) {
                frameGen.makeFrame();
            }
        }
    }
}
