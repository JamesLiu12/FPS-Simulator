#include "true_wall.h"

void TrueWall_Init(struct Mesh *cube) {
    Vector3_Set(&cube->vertices[0], -2.5, -0.1, -0.2);
    Vector3_Set(&cube->vertices[1], 2.5, -0.1, -0.2);
    Vector3_Set(&cube->vertices[2], 2.5, -0.1, 0.2);
    Vector3_Set(&cube->vertices[3], -2.5, -0.1, 0.2);
    Vector3_Set(&cube->vertices[4], -2.5, 2, -0.2);
    Vector3_Set(&cube->vertices[5], 2.5, 2, -0.2);
    Vector3_Set(&cube->vertices[6], 2.5, 2, 0.2);
    Vector3_Set(&cube->vertices[7], -2.5, 2, 0.2);

    Face_Set(&cube->triangles[0], 1, 2, 6);
    Face_Set(&cube->triangles[1], 1, 3, 2);
    Face_Set(&cube->triangles[2], 1, 4, 3);
    Face_Set(&cube->triangles[3], 1, 5, 8);
    Face_Set(&cube->triangles[4], 1, 6, 5);
    Face_Set(&cube->triangles[5], 1, 8, 4);
    Face_Set(&cube->triangles[6], 2, 3, 7);
    Face_Set(&cube->triangles[7], 2, 7, 6);
    Face_Set(&cube->triangles[8], 4, 7, 3);
    Face_Set(&cube->triangles[9], 4, 8, 7);
    Face_Set(&cube->triangles[10], 5, 6, 7);
    Face_Set(&cube->triangles[11], 5, 7, 8);

    

}

struct Mesh* TrueWall_New() {
    struct Mesh *cube = New_Mesh(12, 8);
    TrueWall_Init(cube);
    return cube;
}
