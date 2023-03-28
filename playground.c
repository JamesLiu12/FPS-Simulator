#include "op_engine/op_engine.h"
#include <math.h>
void test(){
    struct C{
        struct Vector3 point;
        struct Transform transform;
    };
    struct C a, b;
    Transform_Init(&a.transform, NULL);
    Transform_Init(&b.transform, &a.transform);

    struct Vector3 vec;
    vec = b.transform.position;
    vec = b.transform.rotation;
    vec = b.transform.scale;

    Transform_UpdateGlobal(&b.transform);
    vec = b.transform.globalPosition;
    vec = b.transform.globalRotation;
    vec = b.transform.globalScale;

    struct Vector3 globalPoint;
    globalPoint = b.point;
    Transform_ToGlobal(&b.transform, &globalPoint);

    struct Vector3 position;
    Vector3_Set(&position, 1, 1, 1);
    Transform_AddPosition(&a.transform, &position);

struct Vector3 eularAngle;
Vector3_Set(&eularAngle, 3.14, 0, 0);
Transform_AddPosition(&a.transform, &position);
}