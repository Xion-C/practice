#include "PBAUI.h"


PBAText2D::PBAText2D(const float pcolor[4], void* pfont) : 
    text(""), 
    font(pfont)
{
    size[0] = DEFAULTFONTWIDTH;
    size[1] = DEFAULTFONTHEIGHT;
    for(unsigned int i = 0; i < 4; i++) {
        color[i] = pcolor[i];
    }
}

//void drawString(const char *str, int x, int y, float color[4], void *font);

void PBAText2D::Render()
{
    const char* str = text.c_str();

    glPushAttrib(GL_LIGHTING_BIT | GL_CURRENT_BIT); // lighting and color mask
    glDisable(GL_LIGHTING); // need to disable lighting for proper text color
    glDisable(GL_TEXTURE_2D);

    glColor4fv(color);
    //glRasterPos2i(position.x, position.y); // place text position
    glRasterPos3f(position.x, position.y, position.z);

    // loop all characters in the string
    while(*str)
    {
        glutBitmapCharacter(font, *str);
        ++str;
    }

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glPopAttrib();
    // IFDEBUG(
    //     std::cout << "render text: " << text << std::endl;
    // )
}