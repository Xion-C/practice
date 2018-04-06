#include <SDL2/SDL.h>
#include <string>
#include "ioMod.h"
#include "gamedata.h"

class HUD {
public:
    HUD(SDL_Renderer* r) :
        renderer(r),
        posX(Gamedata::getInstance().getXmlInt("HUD/posX")),
        posY(Gamedata::getInstance().getXmlInt("HUD/posY")),
        width(Gamedata::getInstance().getXmlInt("HUD/width")),
        height(Gamedata::getInstance().getXmlInt("HUD/height")),
        info(( Gamedata::getInstance().getXmlStr("HUD/info") ))
    {
    }
    void display() const {
        SDL_SetRenderDrawColor( renderer, 208, 209, 210, 255 );
        SDL_Rect r;
        r.x = posX;
        r.y = posY;
        r.w = width;
        r.h = height;
        // First set the blend mode so that alpha blending will work;
        // the default blend mode is SDL_BLENDMODE_NONE!
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        // Now set the color for the hud:
        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255/2 );

        // Render rect
        SDL_RenderFillRect( renderer, &r );

        // Now set the color for the outline of the hud:
        SDL_SetRenderDrawColor( renderer, 255, 0, 255/2, 255/2 );
        SDL_RenderDrawRect( renderer, &r );

        IOMod::getInstance().writeText("Press W/A/S/D to move", r.x + 20, r.y + r.h - 50);
    }
private:
    SDL_Renderer* renderer;
    int posX;
    int posY;
    int width;
    int height;
    std::string info;
};
