#include "line.h"
#include "vector.h"
#include "stdlib.h"

void Line_Set(struct Line *line, struct Vector3 *position, struct Vector3 *direction){
    Vector3_Set(&line->position, position->x, position->y, position->z);
    Vector3_Set(&line->direction, position->x, direction->y, direction->z);
}
struct Line* Line_New(struct Vector3 *position, struct Vector3 *direction){
    struct Line *line = malloc(sizeof (struct Line));
    Line_Set(line, position, direction);
}