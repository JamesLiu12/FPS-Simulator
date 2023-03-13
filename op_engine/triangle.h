#ifndef OP_TRIANGLE

#include "vector.h"

struct Triangle {
    //3 positions for vertices
    struct Vector3 v1, v2, v3;
};

void Triangle_Set(struct Triangle *triangle, struct Vector3 *p1, struct Vector3 *p2, struct Vector3 *p3);
int Triangle_IsPointInTriangle(struct Triangle *triangle, struct Vector3 *point);
int Triangle_IsPointInRange(struct Triangle *triangle, struct Vector3 *point);
int Triangle_IsPointInTriangle2D(struct Triangle *triangle, struct Vector3 *point);
int Triangle_IsPointInTriangle3D(struct Triangle *triangle, struct Vector3 *point);

#define OP_TRIANGLE
#endif

