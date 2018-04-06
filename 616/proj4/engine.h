#include <vector>
#include <SDL.h>
#include "ioMod.h"
#include "renderContext.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"
#include "hud.h"

class CollisionStrategy;
class SmartSprite;
class Player;

class Engine {
public:
    Engine ();
    ~Engine ();
    void play();
    // void switchSprite();
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    const RenderContext* rc;
    const IOMod& io;
    Clock& clock;

    SDL_Renderer * const renderer;
    World back_layer1;
    World back_layer2;
    World back_layer3;
    Viewport& viewport;

    Player* player;
    std::vector<SmartSprite*> clouds;

    std::vector<CollisionStrategy*> strategies;
    int currentStrategy;
    bool collision;
    bool makeVideo;

    HUD hud;
    bool hud_on;


    void draw() const;
    void update(Uint32);

    void printScales() const;
    void checkForCollisions();
};
