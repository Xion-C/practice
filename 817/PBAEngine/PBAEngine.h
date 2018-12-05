#ifndef __PBAENGINE_H__
#define __PBAENGINE_H__

#include "ParameterLoader.h"
#include "View.h"
#include "PBAScene.h"
#include "PBAKeyboardManager.h"
#include "PBAMouseManager.h"

class PBAEngine
{
public:
    ~PBAEngine();
    static PBAEngine* GetInstance();
    int Init(int argc, char* argv[]);
    int Start();
    const PBAKeyboardManager& GetKeyboard() const;
    const PBAMouseManager& GetMouse() const;
    const View& GetView() const;
private: 
    PBAEngine();
    PBAEngine(const PBAEngine&) = delete;
    PBAEngine& operator=(const PBAEngine&) = delete;

    int InitGlut(int argc, char* argv[]);

    void Reshape(int width, int height);
    void HandleKey(unsigned char key, int x, int y);
    void HandleMouseButtons(int button, int state, int x, int y);
    void HandleMouseMotion(int x, int y);
    void HandleMousePassiveMotion(int x, int y);
    //void glutPassiveMotionFunc
    void Display();
    void Update();

    static void ReshapeWrapper(int width, int height);
    static void HandleKeyWrapper(unsigned char key, int x, int y);
    static void HandleMouseButtonsWrapper(int button, int state, int x, int y);
    static void HandleMouseMotionWrapper(int x, int y);
    static void HandleMousePassiveMotionWrapper(int x, int y);
    static void DisplayWrapper();
    static void UpdateWrapper();

    void LoadParameters(const char* path = nullptr);

private: 
    static PBAEngine* instance;
    View viewer;

    PBAKeyboardManager keyboard;
    PBAMouseManager mouse;

    PBAScene* scene;

};

#endif
