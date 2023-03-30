#ifndef FPS_SIMULATOR_COLLIDE_BOX_H
#define FPS_SIMULATOR_COLLIDE_BOX_H

#include "vector.h"
#include "../util/util.h"
#include "line.h"
#include "transform.h"

struct CollideBox{
    struct Vector3 minVertex, maxVertex;
};

//Setter of CollideBox
void CollideBox_Set(struct CollideBox *box, struct Vector3 *minVertex, struct Vector3 *maxVertex);

//Return the distance between ray and box, return INFINITY if the ray does not hit
double CollideBox_RayDistance(struct CollideBox *box, struct Transform *transform, struct Line *ray);

//Return True <=> the two collide boxed are overlapped
double CollideBox_IsCollide(struct CollideBox *b1, struct Transform *t1, struct CollideBox *b2, struct Transform *t2);

#endif //FPS_SIMULATOR_COLLIDE_BOX_H