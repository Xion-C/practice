#include <vector>
#include <SDL.h>
#include "ioMod.h"
#include "renderContext.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"
#include "hud.h"
#include "infoHUD.h"

class CollisionStrategy;
class SmartSprite;
class Bullet;
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
    World ground;
    World mountain;
    World sky;
    Viewport& viewport; //note: &

    Player* player;
    std::vector<SmartSprite*> clouds;
    //std::vector<SmartMultiSprite*> swords;
    //std::vector<Bullet*> clouds;
    std::vector<Bullet*> swords;

    std::vector<CollisionStrategy*> strategies;
    int currentStrategy;
    bool collision;
    bool makeVideo;

    bool hud_on;
    HUD& hud; //note: &
    InfoHUD& infoHUD; //note: &



    void draw() const;
    void update(Uint32);

    void printScales() const;
    void checkForCollisions();
};
