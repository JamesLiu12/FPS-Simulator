#include "map_new_OnlyFloor.h"

void ModelMap_new_OnlyFloor_Init(struct Mesh *map_new_onlyfloor) {
    Vector3_Set(&map_new_onlyfloor->vertices[0], -20.0, 0.0, -20.0);
    Vector3_Set(&map_new_onlyfloor->vertices[1], 60.0, 0.0, -20.0);
    Vector3_Set(&map_new_onlyfloor->vertices[2], -20.0, 0.0, 20.0);
    Vector3_Set(&map_new_onlyfloor->vertices[3], 60.0, 0.0, 20.0);

    Face_Set(&map_new_onlyfloor->triangles[0], 1, 2, 4);
    Face_Set(&map_new_onlyfloor->triangles[1], 1, 3, 4);
}

struct Mesh* ModelMap_new_OnlyFloor_New() {
    struct Mesh *map_new_onlyfloor= New_Mesh(2, 4);
    ModelMap_new_OnlyFloor_Init(map_new_onlyfloor);
    return map_new_onlyfloor;
}
