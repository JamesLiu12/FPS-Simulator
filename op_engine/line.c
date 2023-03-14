#include "line.h"
#include "vector.h"
#include "stdlib.h"
#include "../util/util.h"

void Line_Set(struct Line *line, struct Vector3 *position, struct Vector3 *direction){
    Vector3_Set(&line->position, position->x, position->y, position->z);
    Vector3_Set(&line->direction, direction->x, direction->y, direction->z);
}

struct Line* Line_New(struct Vector3 *position, struct Vector3 *direction){
    struct Line *line = malloc(sizeof (struct Line));
    Line_Set(line, position, direction);
    return line;
}

int Line_IsPointOnLine(struct Line *line, struct Vector3 *point){
    int number_direction = 3; //The number of non-zero direction

    //Some value in direction vector may be 0, should be considered separately
    if (double_IsZero(line->direction.x)) {
        if (!double_equal(line->position.x, point->x)) return FALSE;
        number_direction--;
    }
    if (double_IsZero(line->direction.y)) {
        if (!double_equal(line->position.y, point->y)) return FALSE;
        number_direction--;
    }
    if (double_IsZero(line->direction.z)) {
        if (!double_equal(line->position.z, point->z)) return FALSE;
        number_direction--;
    }

    if (number_direction == 0 || number_direction == 1) return TRUE;

    if (number_direction == 2){
        if (double_IsZero(line->direction.x)){
            double alpha = (point->y - line->position.y) / line->direction.y;
            return double_equal(point->z, line->position.z + alpha * line->direction.z);
        }
        if (double_IsZero(line->direction.y)){
            double alpha = (point->x - line->position.x) / line->direction.x;
            return double_equal(point->z, line->position.z + alpha * line->direction.z);
        }
        if (double_IsZero(line->direction.z)){
            double alpha = (point->x - line->position.x) / line->direction.x;
            return double_equal(point->y, line->position.y + alpha * line->direction.y);
        }
    }
    else{
        double alpha = (point->x - line->position.x) / line->direction.x;
        return double_equal(point->y, line->position.y + alpha * line->direction.y)
            && double_equal(point->z, line->position.z + alpha * line->direction.z);
    }
}