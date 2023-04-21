#ifndef FPS_SIMULATOR_BOUNDARIES_H
#define FPS_SIMULATOR_BOUNDARIES_H

#include "../../op_engine/mesh.h"

void ModelBoundaries_Init(struct Mesh *boundaries);
struct Mesh* ModelBoundaries_New();

#endif //FPS_SIMULATOR_BOUNDARIES_H