#include "collide_box.h"
#include "plane.h"
#include "triangle.h"

void CollideBox_Set(struct CollideBox *box, struct Vector3 *minVertex, struct Vector3 *maxVertex){
    box->minVertex = *minVertex;
    box->maxVertex = *maxVertex;
}

int CollideBox_RayDistance(struct CollideBox *box, struct Transform *transform, struct Line *ray){
    Transform_UpdateGlobal(transform);

    struct Plane plane;
    struct Triangle t1, t2;
    struct Vector3 position, direction;

    //front surface
}