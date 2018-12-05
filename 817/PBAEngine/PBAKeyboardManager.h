#ifndef __PBAKEYBOARDMANAGER_H_
#define __PBAKEYBOARDMANAGER_H_

enum class KeyState {
    Up,
    Down,
    Hold
};

class PBAKeyboardManager 
{
public: 
    PBAKeyboardManager();

    void Reset();

    void SetKey(unsigned char k, int x_, int y_);

    bool GetKey(unsigned char k) const;

    // KeyState GetKeyState(unsigned char k);

private: 
    bool activated;
    unsigned char key;
    int x, y;
    unsigned char keypre;
    int xpre, ypre;
};

#endif