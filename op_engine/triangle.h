#ifndef OP_TRIANGLE

#include "vector.h"

struct Triangle {
    //3 positions for vertices
    struct Vector3 v1, v2, v3;
};

//The setter of Triangle
void Triangle_Set(struct Triangle *triangle, struct Vector3 *p1, struct Vector3 *p2, struct Vector3 *p3);

//Return true <=> the point is inside the triangle, but only considering x-axis and y-axis
int Triangle_IsPointInTriangle2D(struct Triangle *triangle, struct Vector3 *point);

/*
 * Return true <=> the point is inside the triangle, when the point is coplanar with the triangle.
 * This function does not check if the point is coplanar with the triangle!!!
 * Make sure the point is coplanar with the triangle before using this function.
 */
int Triangle_IsPointInTriangle3D(struct Triangle *triangle, struct Vector3 *point);

/*
 * Given the positions of a triangle and a point in a triangle, returns the depth of the point before it is projected
   on to the screen.
 * The normal Interpolation cannot be used directly, as the triangle further, the same distance difference on the screen
   would result in a larger depth change.
 */
double Triangle_PerspectiveCorrectInterpolation(struct Triangle *triangle, struct Vector3 *point);

#define OP_TRIANGLE
#endif

