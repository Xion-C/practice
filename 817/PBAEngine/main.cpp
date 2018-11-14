#include "PBAEngine.h"

int main(int argc, char* argv[])
{
    PBAEngine* pbaEngine = PBAEngine::GetInstance();
    pbaEngine->Init(argc, argv);
    pbaEngine->Start();
    delete pbaEngine;
    return 0;
}
