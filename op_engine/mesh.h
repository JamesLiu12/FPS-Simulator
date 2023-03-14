#ifndef OP_MODEL

#include <stdlib.h>
#include "triangle.h"

struct Face {
    unsigned int f1, f2, f3;
};

void Face_Set(struct Face* face, unsigned int f1, unsigned int f2, unsigned int f3);

struct Mesh {
    unsigned int triangle_count;
    unsigned int vertex_count;

    struct Face *triangles;
    struct Vector3 *vertices;
};

struct Mesh *new_Mesh(unsigned int triangle_count, unsigned int vertex_count);
void del_Mesh(struct Mesh *model);

void ModelCube_Init(struct Mesh *cube);
struct Mesh* ModelCube_New();

#define OP_MODEL
#endif
