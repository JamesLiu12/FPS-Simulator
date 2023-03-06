#ifndef OP_TRIANGLE

#include "vector.h"

struct Triangle {
    //3 positions for vertices
    struct Vector3 v1, v2, v3;
};

void Triangle_set(struct Triangle *triangle, struct Vector3 *p1, struct Vector3 *p2, struct Vector3 *p3);

#define OP_TRIANGLE
#endif

