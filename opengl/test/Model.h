/*
 Model.h

 Adapted form Dr. Donald H. House
*/

#ifndef __MODEL_H__
#define __MODEL_H__

#include "Vector.h"

class Model{
  private:
    // Ball and box simulation parameters
    float speed;
    float mass;
    float drag;
    float buoyancy;

    float h;
    int dispinterval;
    bool Rising;

    // State of bubble
    Vector3d BubblePos;
    Vector3d BubbleVel;

  public:
    Model();

    bool loadParameters(const char *parmfilename); // get simulation parameters

    void initSimulation();    // initialize bubble to initial position and velocity
    void timeStep();          // take one timestep
    void startBubble();       // make the bubble active

    // accessors to retrieve bubble state
    Vector3d bubblePosition(){return BubblePos;}
    Vector3d bubbleVelocity(){return BubbleVel;}
    bool isRising(){return Rising;}

    // accessor to retrieve model information for viewer
    int displayInterval(){return dispinterval;}
};

#endif
