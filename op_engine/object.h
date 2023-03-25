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

    int number_of_child;

    //A list of the child objects, equals to NULL if no child
    struct Object* childList;

    //The father object, equals to NULL if this is the root object
    struct Object* father;
};

//Setter of object
void Object_Set(struct Object *object, struct Mesh *mesh, struct Transform *transform, enum Tag tag,
        int number_of_child, struct Object* child, struct Object* father);

//Newer of object
struct Object* Object_New(struct Mesh *mesh, struct Transform *transform, enum Tag tag,
        int number_of_child, struct Object* child, struct Object* father);

//Free the memory of object
void Del_Object(struct Object *object);

//Showing an object on the screen
void Object_Show(struct Object *object, struct Canvas *canvas, struct Transform *transform_father);

//Rotate an object by an Eular angle rotation
void Object_Rotation(struct Object *object, struct Vector3* rotation);

//Move an object by a vector move
void Object_Move(struct Object *object, struct Vector3 *move);
;

#endif //FPS_SIMULATOR_OBJECT_H
