#ifndef FPS_SIMULATOR_COLLIDE_BOX_H
#define FPS_SIMULATOR_COLLIDE_BOX_H

#include "vector.h"
#include "../util/util.h"
#include "line.h"
#include "transform.h"

struct CollideBox{
    struct Transform transform;
    struct Vector3 halfSize;
};

//Setter of CollideBox
void CollideBox_Init(struct CollideBox *box, struct Transform *father , double length, double height, double width);

void Del_CollideBox(struct CollideBox *box);

//Return the distance between ray and box, return INFINITY if the ray does not hit
double CollideBox_RayDistance(struct CollideBox *box, struct Line *ray);

//Return True <=> the two collide boxed are overlapped
int CollideBox_IsCollide(struct CollideBox *b1, struct CollideBox *b2);

#endif //FPS_SIMULATOR_COLLIDE_BOX_H