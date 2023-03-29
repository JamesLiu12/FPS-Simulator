#ifndef FPS_SIMULATOR_OBJECT_H
#define FPS_SIMULATOR_OBJECT_H

#include "mesh.h"
#include "vector.h"
#include "transform.h"
#include "canvas.h"
#include "tag.h"
#include "collide_box.h"
#include "../util/array_list.h"

struct Object{
    //Mesh of object, equals to NULL if no mesh
    struct Mesh *mesh;

    //transform of object
    struct Transform transform;

    //Tag of object, means what is the object
    enum Tag tag;

    //Collide box of object
    struct CollideBox collide_box;
};

//Setter of object
void Object_Set(struct Object *object, struct Mesh *mesh, struct Transform *transform, enum Tag tag);

//Newer of object
struct Object* Object_New(struct Mesh *mesh, struct Transform *transform, enum Tag tag);

//Free the memory of object
void Del_Object(struct Object *object);

//Showing an object on the screen
void Object_Show(struct Object *object, struct Canvas *canvas);

//Rotate an object by an Eular angle rotation
void Object_Rotation(struct Object *object, struct Vector3* rotation);

//Move an object by a vector move
void Object_Move(struct Object *object, struct Vector3 *move);


#endif //FPS_SIMULATOR_OBJECT_H
