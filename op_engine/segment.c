#include "segment.h"
#include "stdlib.h"
#include "../util/util.h"

int Segment_is_point_inside(struct Segment *seg, struct Vector3 *p){
    return double_equal((seg->p1.y - p->y) * (seg->p1.x - p->x), (seg->p2.y - p->y) * (seg->p2.x - p->x))
        && double_equal((seg->p1.z - p->z) * (seg->p1.x - p->x), (seg->p2.z - p->z) * (seg->p2.x - p->x))
        && double_equal((seg->p1.z - p->z) * (seg->p1.y - p->y), (seg->p2.z - p->z) * (seg->p2.y - p->y))
        && (seg->p1.x <= p->x || seg->p2.x <= p->x) && (p->x <= seg->p1.x || p->x <= seg->p2.x)
        && (seg->p1.y <= p->y || seg->p2.y <= p->y) && (p->y <= seg->p1.y || p->y <= seg->p2.y)
        && (seg->p1.z <= p->z || seg->p2.z <= p->z) && (p->z <= seg->p1.z || p->z <= seg->p2.z);
}

void Segment_Set(struct Segment *seg, struct Vector3 *p1, struct Vector3 *p2){
    seg->p1.x = p1->x;
    seg->p1.y = p1->y;
    seg->p1.z = p1->z;
    seg->p2.x = p2->x;
    seg->p2.y = p2->y;
    seg->p2.z = p2->z;
}

struct Segment* Segment_New(struct Vector3 *p1, struct Vector3 *p2){
    struct Segment *segment = malloc(sizeof (struct Segment));
    Segment_Set(segment, p1, p2);
    return segment;
}