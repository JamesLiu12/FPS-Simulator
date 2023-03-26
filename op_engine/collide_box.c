#include "collide_box.h"

void CollideBox_Set(struct CollideBox *box, struct Vector3 *low_front_vertex, struct Vector3 *up_back_vertex){
    box->low_front_vertex = *low_front_vertex;
    box->up_back_vertex = *up_back_vertex;
}