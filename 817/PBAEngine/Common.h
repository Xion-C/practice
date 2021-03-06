#ifndef __PBA_COMMON_H__
#define __PBA_COMMON_H__

#include "Vector.h"
#include "Utility.h"


#ifdef __APPLE__
#   pragma clang diagnostic ignored "-Wdeprecated-declarations"
#   include <GLUT/glut.h>
#else
#   include <GL/glut.h>
#endif

#define __DEBUG__

#ifdef __DEBUG__
#   define IFDEBUG(...) __VA_ARGS__
#else
#   define IFDEBUG(...)
#endif


#endif