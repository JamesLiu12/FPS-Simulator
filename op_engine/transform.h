#ifndef OP_ENGINE_TRANSFORMATION

#include "vector.h"
#include "matrix.h"
#include "../util/array_list.h"

struct Transform {
    struct Vector3 position;
    struct Vector3 rotation;
    struct Vector3 scale;
    struct Matrix3x3 rotationMatrix;

    struct Vector3 globalPosition;
    struct Vector3 globalRotation;
    struct Vector3 globalScale;
    struct Matrix3x3 globalRotationMatrix;

    struct Transform *father;
    int childCount;
    struct ArrayList list_child;
};

//Initializer of transform, father_transform is NULL if this transform is the root
void Transform_Init(struct Transform *transform, struct Transform *father_transform);

void Del_Transform(struct Transform *transform);

//Update the rotationMatrix by the current rotation, call it after each time the rotation has changed
void Transform_RotationMatrixUpdate(struct Transform *transform);

//Call this function every time before using the global data!!!
void Transform_UpdateGlobal(struct Transform *transform);

//Add a child transform to transform
void Transform_AddChild(struct Transform *transform, struct Transform *child);

void Transform_ToGlobal(struct Transform *transform, struct Vector3 *vector);

void Transform_AddPosition(struct Transform *transform, struct Vector3 *position);

void Transform_AddRotation(struct Transform *transform, struct Vector3 *rotation);

#define OP_ENGINE_TRANSFORMATION
#endif
