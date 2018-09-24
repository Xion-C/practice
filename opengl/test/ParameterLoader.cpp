#include <cstdio>
#include <cstring>

#include "ParameterLoader.h"

ParameterLoader::ParameterLoader(const char* path) {
    success = LoadParameters(path);
}

bool ParameterLoader::LoadParameters(const char* path)
{
    FILE * file = fopen(path, "r");
    if(file == NULL) {
        fprintf(stderr, "Unable to open parameter file: %s\n", path);
        return false;
    }
    printf("Loading parameters from: %s\n", path);

    int number = 0;
    while (1) {
        char text[128]; //save current reading text
        if (fscanf(file, "%s", text) == EOF) break;
        if (strcmp(text, "TimeStep-h") == 0) {
            fscanf(file, "%f\n", &timeStep);
            number++;
        }
        if (strcmp(text, "DisplayInterval") == 0) {
            fscanf(file, "%d\n", &displayInterval);
            number++;
        }
        if (strcmp(text, "Mass") == 0) {
            fscanf(file, "%f\n", &mass);
            number++;
        }
        if (strcmp(text, "InitialVelocity") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(initialVelocity.x), &(initialVelocity.y), &(initialVelocity.z));
            number++;
        }
        if (strcmp(text, "Gravity") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(gravity.x), &(gravity.y), &(gravity.z));
            number++;
        }
        if (strcmp(text, "WindVelocity") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(windVelocity.x), &(windVelocity.y), &(windVelocity.z));
            number++;
        }
        if (strcmp(text, "CoefficientOfAirResistance") == 0) {
            fscanf(file, "%f\n", &airReisistance);
            number++;
        }
        if (strcmp(text, "BallSize") == 0) {
            fscanf(file, "%f\n", &ballSize);
            number++;
        }
        if (strcmp(text, "BoxSize") == 0) {
            fscanf(file, "%f\n", &boxSize);
            number++;
        }
        if (strcmp(text, "CoefficientOfRestitution") == 0) {
            fscanf(file, "%f\n", &restitution);
            number++;
        }
        if (strcmp(text, "CoefficientOfFriction") == 0) {
            fscanf(file, "%f\n", &friction);
            number++;
        }

    }

    fclose(file);

    printf("Parameters Number: %d\n", number);

    success = true;
    return true;
}
