#ifndef FPS_SIMULATOR_PLANE_H
#define FPS_SIMULATOR_PLANE_H

#include "vector.h"
#include "line.h"

//A 3D-plane in the form of a position vector and two direction vectors
struct Plane{
    struct Vector3 position, direction1, direction2;
};

//Calculate the intersection of plane and vector, the answer will be stored in result
void Plane_intersection_Line(struct Plane *plane, struct Line *line, struct Vector3 *result);

void Plane_Set(struct Plane *plane, struct Vector3 *position, struct Vector3 *direction1, struct Vector3 *direction2);

#endif //FPS_SIMULATOR_PLANE_H
