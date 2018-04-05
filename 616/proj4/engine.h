#include <vector>
#include <SDL.h>
#include "ioMod.h"
#include "renderContext.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"

class Engine {
public:
    Engine ();
    ~Engine ();
    void play();
    void switchSprite();

private:
    const RenderContext* rc;
    const IoMod& io;
    Clock& clock;

    SDL_Renderer * const renderer;
    World back_layer1;
    World back_layer2;
    World back_layer3;
    Viewport& viewport;

    // Drawable* star;
    // Drawable* spinningStar;
    std::vector<Drawable*> sprites_vec;

    int currentSprite;

    bool makeVideo;

    void draw() const;
    void update(Uint32);

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    void printScales() const;
    void checkForCollisions();
};
