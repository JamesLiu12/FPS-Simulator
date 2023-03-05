#ifndef OP_MODEL

#include <stdlib.h>
#include "triangle.h"

struct Model {
    unsigned int triangle_count;
    struct Triangle *triangles;
};

struct Model *new_model(unsigned int triangle_count) {
    struct Model *model = malloc(sizeof(struct Model));

    model->triangle_count = triangle_count;
    model->triangles = malloc(triangle_count * sizeof(struct Triangle));

    return model;
}

void del_model(struct Model *model) {
    free(model->triangles);
    free(model);
}

#define OP_MODEL
#endif
