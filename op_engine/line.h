#ifndef FPS_SIMULATOR_LINE_H
#define FPS_SIMULATOR_LINE_H

#include "vector.h"

//3D-line in the form of a position vector and a direction vector
struct Line{
    struct Vector3 position, direction;
};

//The setter of Line, given a position vector and a direction vector
void Line_Set(struct Line *line, struct Vector3 *position, struct Vector3 *direction);

//The newer of Line, given a position vector and a direction vector
struct Line* Line_New(struct Vector3 *position, struct Vector3 *direction);

//Return true <=> the point is on the line
int Line_IsPointOnLine(struct Line *line, struct Vector3 *point);

#endif //FPS_SIMULATOR_LINE_H
