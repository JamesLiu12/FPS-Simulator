#ifndef FPS_SIMULATOR_COLLIDE_BOX_H
#define FPS_SIMULATOR_COLLIDE_BOX_H

#include "vector.h"

struct CollideBox{
    struct Vector3 low_front_vertex, up_back_vertex;
};

void CollideBox_Set(struct CollideBox box, struct Vector3 *low_front_vertex, struct Vector3 *up_back_vertex);

#endif //FPS_SIMULATOR_COLLIDE_BOX_H