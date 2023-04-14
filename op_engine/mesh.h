#ifndef OP_MODEL

#include <stdlib.h>
#include "triangle.h"

//f1, f2, f3 are the index of the vertices that forms the triangle face
struct Face {
    unsigned int f1, f2, f3;
};

//The setter of face
void Face_Set(struct Face* face, unsigned int f1, unsigned int f2, unsigned int f3);

//
struct Mesh {
    unsigned int triangle_count;
    unsigned int vertex_count;

    struct Face *triangles;
    struct Vector3 *vertices;
};

void Mesh_Set(unsigned int triangle_count, unsigned int vertex_count);

//The newer of mesh
struct Mesh *New_Mesh(unsigned int triangle_count, unsigned int vertex_count);

//Freeing the memory of mesh from heap
void Del_Mesh(struct Mesh *model);

void Mesh_Copy(struct Mesh *from, struct Mesh *to);

#define OP_MODEL
#endif
