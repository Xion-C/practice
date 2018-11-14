#include <cstdio>
#include <cstring>

#include "ParameterLoader.h"

// ParameterLoader::ParameterLoader(const char* path) {
//     success = LoadParameters(path);
// }

ParameterLoader& ParameterLoader::GetInstance()
{
    static ParameterLoader instance;
    return instance;
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
        if (strcmp(text, "Gravity") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(gravity.x), &(gravity.y), &(gravity.z));
            number++;
        }
        if (strcmp(text, "WindVelocity") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(windVelocity.x), &(windVelocity.y), &(windVelocity.z));
            number++;
        }
        if (strcmp(text, "Mass") == 0) {
            fscanf(file, "%f\n", &mass);
            number++;
        }

        if (strcmp(text, "FlagWidth") == 0) {
            fscanf(file, "%f\n", &flagWidth);
            number++;
        }
        if (strcmp(text, "FlagHeight") == 0) {
            fscanf(file, "%f\n", &flagHeight);
            number++;
        }
        if (strcmp(text, "MeshNumX") == 0) {
            fscanf(file, "%d\n", &meshNumX);
            number++;
        }
        if (strcmp(text, "MeshNumY") == 0) {
            fscanf(file, "%d\n", &meshNumY);
            number++;
        }

        if (strcmp(text, "StartPostion") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(startPostion.x), &(startPostion.y), &(startPostion.z));
            number++;
        }
        if (strcmp(text, "Springy_k") == 0) {
            fscanf(file, "%f\n", &springy_k);
            number++;
        }
        if (strcmp(text, "Damper_d") == 0) {
            fscanf(file, "%f\n", &damper_d);
            number++;
        }
        if (strcmp(text, "DragCoefficient") == 0) {
            fscanf(file, "%f\n", &dragCoefficient);
            number++;
        }
        if (strcmp(text, "LiftCoefficient") == 0) {
            fscanf(file, "%f\n", &liftCoefficient);
            number++;
        }

    }

    fclose(file);

    printf("Parameters Number: %d\n", number);

    success = true;
    return true;
}
