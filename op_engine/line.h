#ifndef FPS_SIMULATOR_LINE_H
#define FPS_SIMULATOR_LINE_H

#include "vector.h"

//3D-line in the form of a position vector and a direction vector
struct Line{
    struct Vector3 position, direction;
};

void Line_Set(struct Line *line, struct Vector3 *position, struct Vector3 *direction);
struct Line* Line_New(struct Vector3 *position, struct Vector3 *direction);
int Line_IsPointOnLine(struct Line *line, struct Vector3 *point);

#endif //FPS_SIMULATOR_LINE_H
