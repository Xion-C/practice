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
    bool GetClick() const { return click; }
    int Reset() { click = false; }
    int Click() { click = true; }
private: 
    int x, y;
    bool click;

};

#endif