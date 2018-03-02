#include <sstream>
#include "viewport.h"
#include "ioMod.h"
#include "clock.h"

Viewport& Viewport::getInstance() {
    static Viewport viewport;
    return viewport;
}

Viewport::Viewport() :
    gdata(Gamedata::getInstance()),
    position(0, 0),
    worldWidth(gdata.getXmlInt("world/width")),
    worldHeight(gdata.getXmlInt("world/height")),
    viewWidth(gdata.getXmlInt("view/width")),
    viewHeight(gdata.getXmlInt("view/height")),
    objWidth(0), objHeight(0),
    objectToTrack(NULL)
{
}

void Viewport::setObjectToTrack(const Drawable *obj) {
    objectToTrack = obj;
    objWidth = objectToTrack->getScaledWidth();
    objHeight = objectToTrack->getScaledHeight();
}

void Viewport::draw() const {
    IoMod::getInstance().writeText("Tracking: "+objectToTrack->getName(),
                                   30, 30);
    IoMod::getInstance().writeText("FPS: " + \
                                   std::to_string(Clock::getInstance().getFps()),
                                   30, 60,
                                   {30, 255, 150, 0});
    IoMod::getInstance().writeText("Xin Cheng",
                                   30, viewHeight - 30,
                                   {255, 150, 100, 0});
}

void Viewport::update() {
    const float x = objectToTrack->getX();
    const float y = objectToTrack->getY();

    position[0] = (x + objWidth/2) - viewWidth/2;
    position[1] = (y + objHeight/2) - viewHeight/2;
    if (position[0] < 0) position[0] = 0;
    if (position[1] < 0) position[1] = 0;
    if (position[0] > (worldWidth - viewWidth)) {
        position[0] = worldWidth-viewWidth;
    }
    if (position[1] > (worldHeight - viewHeight)) {
        position[1] = worldHeight-viewHeight;
    }
}
