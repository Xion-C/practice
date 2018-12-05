#include "PBAKeyboardManager.h"

PBAKeyboardManager::PBAKeyboardManager() : 
    activated(false), 
    key(0), x(0), y(0), 
    keypre(0), xpre(0), ypre(0)
{
}


void PBAKeyboardManager::Reset() 
{
    if(activated == true) activated = false;
    else SetKey(0, 0, 0);
}

void PBAKeyboardManager::SetKey(unsigned char k, int x_, int y_)
{
    activated = true;
    keypre = key;
    key = k;
    xpre = x;
    ypre = y;
    x = x_;
    y = y_;
}

bool PBAKeyboardManager::GetKey(unsigned char k) const 
{
    if(k == key) return true;
    else return false;
} 