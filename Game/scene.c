#include "scene.h"
#include "../op_engine/object.h"
#include "../Game/models/clock.h"

void Scene_Init(struct Scene *scene){
    ArrayList_Init(&scene->list_Object, sizeof(struct Object*));
    ArrayList_Init(&scene->list_Enemy, sizeof(struct Enemy*));
    Player_Init(&scene->player);

    //Sample
    struct Vector3 minVertex, maxVertex;
    int collideBoxCount = 2;
    struct CollideBox *collideBoxes = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount);

    Vector3_Set(&minVertex, -1, -1, -1);
    Vector3_Set(&maxVertex, -0.5, -0.5, -0.5);
    CollideBox_Set(&collideBoxes[0], &minVertex, &maxVertex);

    Vector3_Set(&minVertex, 0.5, 0.5, 0.5);
    Vector3_Set(&maxVertex, 1, -1, 1);
    CollideBox_Set(&collideBoxes[1], &minVertex, &maxVertex);

    struct Transform transform;
    struct Mesh *mesh = ModelClock_New();
    ModelClock_Init(mesh);
    Transform_Init(&transform, NULL);

    struct Object* objectFloor = Object_New(mesh, &transform, FLOOR, collideBoxes, collideBoxCount);

    ArrayList_PushBack(&scene->list_Object, objectFloor);
    //SampleEnd
}

void Del_Scene(struct Scene *scene){
    Del_ArrayList(&scene->list_Object);
    Del_ArrayList(&scene->list_Enemy);
    Del_Player(&scene->player);
}