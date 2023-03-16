#ifndef FPS_SIMULATOR_SEGMENT_H
#define FPS_SIMULATOR_SEGMENT_H

#include "vector.h"
#include "plane.h"

//A segment is basically a vector that has two-side endpoints, representing by the position of the two endpoints
struct Segment{
    struct Vector3 p1, p2;
};

//Returns ture <=> point is on segment
int Segment_IsPointOnSegment(struct Segment *segment, struct Vector3 *point);

//The setter of segment
void Segment_Set(struct Segment *seg, struct Vector3 *p1, struct Vector3 *p2);

//The newer of segment
struct Segment* Segment_New(struct Vector3 *p1, struct Vector3 *p2);

#endif //FPS_SIMULATOR_SEGMENT_H
