#ifndef __PBAENGINE_H__
#define __PBAENGINE_H__

#include "ParameterLoader.h"
#include "View.h"
#include "PBAScene.h"
#include "PBARigidBodyScene.h"

class PBAEngine
{
public:
    ~PBAEngine();
    static PBAEngine* GetInstance();
    int Init(int argc, char* argv[]);
    int Start();
private: 
    PBAEngine();
    PBAEngine(const PBAEngine&) = delete;
    PBAEngine& operator=(const PBAEngine&) = delete;

    int InitGlut(int argc, char* argv[]);

    void Reshape(int width, int height);
    void HandleKey(unsigned char key, int x, int y);
    void HandleMouseButtons(int button, int state, int x, int y);
    void HandleMouseMotion(int x, int y);
    void Display();
    void Update();

    static void ReshapeWrapper(int width, int height);
    static void HandleKeyWrapper(unsigned char key, int x, int y);
    static void HandleMouseButtonsWrapper(int button, int state, int x, int y);
    static void HandleMouseMotionWrapper(int x, int y);
    static void DisplayWrapper();
    static void UpdateWrapper();

    void LoadParameters(const char* path = nullptr);

private: 
    static PBAEngine* instance;
    View viewer;

    PBAScene* scene;
};

#endif
