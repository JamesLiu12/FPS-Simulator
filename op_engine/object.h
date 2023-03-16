#ifndef FPS_SIMULATOR_OBJECT_H
#define FPS_SIMULATOR_OBJECT_H

#include "mesh.h"
#include "vector.h"
#include "transform.h"
#include "canvas.h"
#include "tag.h"
#include "collide_box.h"

struct Object{
    struct Mesh *mesh;
    struct Transform transform;
    enum Tag tag;
};

void Object_Set(struct Object *object, struct Mesh *mesh, struct Transform *transform, enum Tag tag);
struct Object* Object_New(struct Mesh*, enum Tag tag);
void Object_Show(struct Object *object, struct Canvas *canvas);
void Object_Rotation(struct Object *object, struct Vector3* rotation);

#endif //FPS_SIMULATOR_OBJECT_H
