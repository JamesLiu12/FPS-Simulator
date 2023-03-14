#include "segment.h"
#include "stdlib.h"
#include "../util/util.h"

int Segment_IsPointOnSegment(struct Segment *segment, struct Vector3 *point){
    struct Line line;
    struct Vector3 vec_tmp;

    //Calculate the line which the segment is on
    Vector3_Copy(&segment->p2, &vec_tmp);
    Vector3_Subtract(&vec_tmp, &segment->p1);
    Line_Set(&line, &segment->p1, &vec_tmp);

    //Ture if the point is on the line, and all the directions are in the range
    return Line_IsPointOnLine(&line, point)
           && (segment->p1.x <= point->x || segment->p2.x <= point->x)
           && (point->x <= segment->p1.x || point->x <= segment->p2.x)
           && (segment->p1.y <= point->y || segment->p2.y <= point->y)
           && (point->y <= segment->p1.y || point->y <= segment->p2.y)
           && (segment->p1.z <= point->z || segment->p2.z <= point->z)
           && (point->z <= segment->p1.z || point->z <= segment->p2.z);
}

void Segment_Set(struct Segment *seg, struct Vector3 *p1, struct Vector3 *p2){
    Vector3_Copy(p1, &seg->p1);
    Vector3_Copy(p2, &seg->p2);
}

struct Segment* Segment_New(struct Vector3 *p1, struct Vector3 *p2){
    struct Segment *segment = malloc(sizeof (struct Segment));
    Segment_Set(segment, p1, p2);
    return segment;
}