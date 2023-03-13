#ifndef FPS_SIMULATOR_SEGMENT_H
#define FPS_SIMULATOR_SEGMENT_H

#include "vector.h"
#include "plane.h"

//A segment is basically a vector that has two-side endpoints, representing by the position of the two endpoints
struct Segment{
    struct Vector3 p1, p2;
};

//seg is the segment, p is the point, the function returns ture <=> p is a point on seg
int Segment_IsPointOnSegment(struct Segment *seg, struct Vector3 *p);
void Segment_Set(struct Segment *seg, struct Vector3 *p1, struct Vector3 *p2);
struct Segment* Segment_New(struct Vector3 *p1, struct Vector3 *p2);

#endif //FPS_SIMULATOR_SEGMENT_H
