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

#endif //FPS_SIMULATOR_COLLIDE_BOX_H