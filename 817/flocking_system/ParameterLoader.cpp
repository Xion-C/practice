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

        if (strcmp(text, "GenerateSpeed") == 0) {
            fscanf(file, "%d\n", &generateSpeed);
            number++;
        }
        if (strcmp(text, "InitialPosition") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(position.x), &(position.y), &(position.z));
            number++;
        }
        if (strcmp(text, "InitialVelocity") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(velocity.x), &(velocity.y), &(velocity.z));
            number++;
        }
        if (strcmp(text, "Mass") == 0) {
            fscanf(file, "%f\n", &mass);
            number++;
        }

        if (strcmp(text, "Lifespan") == 0) {
            fscanf(file, "%f\n", &lifespan);
            number++;
        }
        if (strcmp(text, "Height") == 0) {
            fscanf(file, "%d\n", &height);
            number++;
        }
        if (strcmp(text, "Width") == 0) {
            fscanf(file, "%d\n", &width);
            number++;
        }
        if (strcmp(text, "VelocityStd") == 0) {
            fscanf(file, "%f\n", &velocityStd);
            number++;
        }

        if (strcmp(text, "ParticleSize") == 0) {
            fscanf(file, "%f\n", &particleSize);
            number++;
        }

        if (strcmp(text, "vertex0") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(vertex0.x), &(vertex0.y), &(vertex0.z));
            number++;
        }

        if (strcmp(text, "vertex1") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(vertex1.x), &(vertex1.y), &(vertex1.z));
            number++;
        }

        if (strcmp(text, "vertex2") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(vertex2.x), &(vertex2.y), &(vertex2.z));
            number++;
        }

        if (strcmp(text, "BallSize") == 0) {
            fscanf(file, "%f\n", &ballSize);
            number++;
        }

        if (strcmp(text, "BallPosition") == 0) {
            fscanf(file, "%lf %lf %lf\n", &(ballPosition.x), &(ballPosition.y), &(ballPosition.z));
            number++;
        }

        if (strcmp(text, "ParticlesNumber") == 0) {
            fscanf(file, "%d\n", &particleNum);
            number++;
        }

        if (strcmp(text, "GeneratorSize") == 0) {
            fscanf(file, "%f\n", &generatorSize);
            number++;
        }

        if (strcmp(text, "CollisionAvoidance_ka") == 0) {
            fscanf(file, "%f\n", &ka);
            number++;
        }
        if (strcmp(text, "VelocityMatching_kv") == 0) {
            fscanf(file, "%f\n", &kv);
            number++;
        }
        if (strcmp(text, "Centering_kc") == 0) {
            fscanf(file, "%f\n", &kc);
            number++;
        }
        if (strcmp(text, "MaxResidualAcceleration_amax") == 0) {
            fscanf(file, "%f\n", &amax);
            number++;
        }
        if (strcmp(text, "LeadBoidSpeed") == 0) {
            fscanf(file, "%f\n", &leadBoidSpeed);
            number++;
        }
        if (strcmp(text, "RoutePointsNumber") == 0) {
            fscanf(file, "%d\n", &routePointsNum);
            number++;
            if(routePointsNum > 0)
            {
                routePoints.clear();
                for(int i = 0; i < routePointsNum; i++)
                {
                    Vector3d rpoint;
                    fscanf(file, "%lf %lf %lf\n", &(rpoint.x), &(rpoint.y), &(rpoint.z));
                    routePoints.push_back(rpoint);
                }
                number += routePointsNum;
            }
        }

    }

    fclose(file);

    printf("Parameters Number: %d\n", number);

    success = true;
    return true;
}
