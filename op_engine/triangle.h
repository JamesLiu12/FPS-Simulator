#include "vector.h"

#ifndef OP_TRIANGLE

struct Triangle {
    //3 positions for vertices
    struct Vector3 v1, v2, v3;
};

#define OP_TRIANGLE
#endif

