#ifndef __PBAMOUSEMANAGER_H__
#define __PBAMOUSEMANAGER_H__

class PBAMouseManager
{
public: 
    PBAMouseManager() : x(0), y(0) {}
    int SetMotion(int x_, int y_) {
        x = x_;
        y = y_;
    }
    int GetX() const { return x; }
    int GetY() const { return y; }
private: 
    int x, y;

};

#endif