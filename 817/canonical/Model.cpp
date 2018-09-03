/*
 Model.h

 CPSC 8170 Physically Based Animation
 Donald H. House     8/23/2018

 Implementation for Teapot-Bubble Simulation Model
*/

#include "Model.h"

#include <cstdlib>
#include <cstdio>

using namespace std;

//===========================================================================
// Model
//===========================================================================

Model::Model(){
  initSimulation();
}

// get simulation parameters from parameter file
bool Model::loadParameters(const char *paramfilename){
  FILE *paramfile;

  paramfile = fopen(paramfilename, "r");
  if(paramfile == NULL){
    fprintf(stderr, "Unable to open parameter file: %s\n", paramfilename);
    return false;
  }

  int nparams = fscanf(paramfile, "%f, %f, %f, %f, %f, %d", &speed, &mass, &drag, &buoyancy, &h, &dispinterval);
  if(nparams != 6){
    fprintf(stderr,
            "Parameter file %s invalid format. Needs 5 comma seperated floats, and 1 integer\n",
            paramfilename);
    return false;
  }

  return true;
}

// restore the bubble simulation to its initial state
void Model::initSimulation(){
  // return the bubble to its starting position and velocity
  BubblePos.set(0.0, 0.0, 0.0);
  BubbleVel.set(0.866 * speed, 0.5 * speed, 0.0);    // start bubble at 30 degrees to right
  Rising = false;
}

// this does one time step in the simulation
void Model::timeStep(){
  const Vector3d Buoyancy(0, buoyancy, 0);     // buoyancy force straight up

  // modified Euler update of velocity and position
  Vector3d newBubbleVel = BubbleVel + h * (-drag / mass * BubbleVel + Buoyancy);
  BubblePos = BubblePos + h * (newBubbleVel + BubbleVel) / 2;
  BubbleVel = newBubbleVel;
}

// start the bubble
void Model::startBubble(){
  Rising = true;
}

void Model::print() const {
    cout << "Pos: " << BubblePos << " | " << "Vel: " << BubbleVel << endl;
}
