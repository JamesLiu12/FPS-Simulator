#include "../mesh.h"


void ModelCube_Init(struct Mesh *cube) {
    Face_Set(&cube->triangles[0], 0, 1, 5);
    Face_Set(&cube->triangles[1], 0, 2, 1);
    Face_Set(&cube->triangles[2], 0, 3, 2);
    Face_Set(&cube->triangles[3], 0, 4, 7);
    Face_Set(&cube->triangles[4], 0, 5, 4);
    Face_Set(&cube->triangles[5], 0, 7, 3);
    Face_Set(&cube->triangles[6], 1, 2, 6);
    Face_Set(&cube->triangles[7], 1, 6, 5);
    Face_Set(&cube->triangles[8], 3, 6, 2);
    Face_Set(&cube->triangles[9], 3, 7, 6);
    Face_Set(&cube->triangles[10], 4, 5, 6);
    Face_Set(&cube->triangles[11], 4, 6, 7);

    Vector3_Set(&cube->vertices[0], -.5, -.5, -.5);
    Vector3_Set(&cube->vertices[1], .5, -.5, -.5);
    Vector3_Set(&cube->vertices[2], .5, -.5, .5);
    Vector3_Set(&cube->vertices[3], -.5, -.5, .5);
    Vector3_Set(&cube->vertices[4], -.5, .5, -.5);
    Vector3_Set(&cube->vertices[5], .5, .5, -.5);
    Vector3_Set(&cube->vertices[6], .5, .5, .5);
    Vector3_Set(&cube->vertices[7], -.5, .5, .5);

}

struct Mesh* ModelCube_New() {
    struct Mesh *cube = new_Mesh(12, 8);
    ModelCube_Init(cube);
    return cube;
}
