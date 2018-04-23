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
// #include "smartSprite.h"
#include "smartMultiSprite.h"
#include "bullet.h"
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

    for(MultiSprite* cloud : cloudsLayer1) {
        delete cloud;
    }

    for(MultiSprite* cloud : cloudsLayer2) {
        delete cloud;
    }

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
    player( new Player("XCheng", "Sword") ),
    clouds(),
    swords(),
    cloudsLayer1(),
    cloudsLayer2(),
    strategies(),
    currentStrategy( 1 ),
    collision( false ),
    makeVideo( false ),
    hud_on( true ),
    hud( HUD::getInstance() ),
    infoHUD( InfoHUD::getInstance() )
{
    Vector2f pos = player->getPosition();
    int w = player->getScaledWidth();
    int h = player->getScaledHeight();

    int n = Gamedata::getInstance().getXmlInt("Cloud/number");
    for(int i = 0; i < n; i++) {
        clouds.push_back(new SmartMultiSprite("Cloud", pos, w, h));
        player->attach(clouds[i]);
    }

    for(int i = 0; i < 4 * n; i++)
    {
        MultiSprite* cloud1 = new MultiSprite("Cloud", 50);
        cloud1->setScale(0.3);
        cloud1->setVelocity(0.3 * cloud1->getVelocity());
        cloudsLayer1.push_back(cloud1);
    }

    for(int i = 0; i < 1 * n; i++)
    {
        MultiSprite* cloud2 = new MultiSprite("Cloud", 50);
        cloud2->setScale(0.5);
        cloud2->setVelocity(0.5 * cloud2->getVelocity());
        cloudsLayer2.push_back(cloud2);
    }

    strategies.push_back(new RectangularCollisionStrategy);
    strategies.push_back(new PerPixelCollisionStrategy);
    strategies.push_back(new MidPointCollisionStrategy);

    Viewport::getInstance().setObjectToTrack(player);
    std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
    sky.draw();

    for(auto cloud : cloudsLayer1) {
        cloud->draw();
    }

    mountain.draw();

    for(auto cloud : cloudsLayer2) {
        cloud->draw();
    }

    ground.draw();

    for(auto cloud : clouds) {
        cloud->draw();
    }
    // for(auto sword : swords) {
    //     sword->draw();
    // }

    player->draw();

    viewport.draw();
    strategies[currentStrategy]->draw();
    if(hud_on) {
        hud.draw();
        infoHUD.draw();
    }

    SDL_RenderPresent(renderer);
}

void Engine::checkForCollisions() {
    auto it = clouds.begin();
    while ( it != clouds.end() ) {
        if ( strategies[currentStrategy]->execute(*player, **it) ) {
            if(!(player->isCrouch()) && !((*it)->isExplode())) {
                player->explode();
                break;
            }
            else it++;
        }
        else it++;
    }
    std::list<Bullet*>& bulletList = player->getBullets().getBulletList();

    auto it1 = clouds.begin();
    while ( it1 != clouds.end() ) {
        auto it2 = bulletList.begin();
        while ( it2 != bulletList.end() ) {
            if ( strategies[currentStrategy]->execute(**it1, **it2) ) {
                if(!((*it1)->isExplode()) && !((*it2)->isExplode())) {
                    (*it2)->explode();
                    (*it1)->explode();
                    break;
                }
                else it2++;
            }
            else it2++;
        }
        it1++;
    }
}

void Engine::update(Uint32 ticks) {
    collision = false;
    checkForCollisions();

    player->update(ticks);

    for(auto cloud : clouds) {
        cloud->update(ticks);
    }
    // for(auto sword : swords) {
    //     sword->update(ticks);
    // }
    for(auto cloud : cloudsLayer1) {
        cloud->update(ticks);
    }
    for(auto cloud : cloudsLayer2) {
        cloud->update(ticks);
    }

    ground.update();
    mountain.update();
    sky.update();

    viewport.update(); // always update viewport last
    hud.update();
    infoHUD.update();
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
                if (keystate[SDL_SCANCODE_SPACE]) {
                    player->shoot();
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
            if (keystate[SDL_SCANCODE_E]) {
                // static_cast<Player*>(player)->down();
                static_cast<Player*>(player)->explode();
            }

            draw();
            update(ticks);
            if ( makeVideo ) {
                frameGen.makeFrame();
            }
        }
    }
}
