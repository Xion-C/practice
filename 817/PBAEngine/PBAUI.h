#ifndef __PBAUI__H__
#define __PBAUI__H__

#include "Common.h"
#include <string>

#define DEFAULTFONT GLUT_BITMAP_9_BY_15
#define DEFAULTFONTWIDTH 9
#define DEFAULTFONTHEIGHT 15

class PBAUI 
{
public: 
    virtual void Render() = 0;

public: 
    std::string name;
    Vector3d position;

};


class PBAText2D : public PBAUI 
{
public: 
    PBAText2D(const float pcolor[4], void* pfont = GLUT_BITMAP_9_BY_15);
    virtual void Render() override;

public: 
    std::string text;
    float color[4];
    float size[2];
    void* font;

};

class PBAText3D : public PBAUI 
{
public: 
    virtual void Render() override;

public: 
    std::string text;
    float color[4];
    void* font;
};


#endif