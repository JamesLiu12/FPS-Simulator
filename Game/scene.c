#include "scene.h"
#include "../op_engine/object.h"

void Scene_Init(struct Scene *scene){
    ArrayList_Init(&scene->list_Object, sizeof(struct Object*));
    ArrayList_Init(&scene->list_Enemy, sizeof(struct Enemy*));
    Player_Init(&scene->player);
<<<<<<< Updated upstream
=======

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

    //Map_boundary origin coordinate (0,0,0)
    struct Vector3 minVertex_Boundary, maxVertex_Boundary;
    int collideBoxCount_Boundary = 5;
    struct CollideBox *collideBoxes_Boundary = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount_Boundary);
    //set collideBoxes:

    Vector3_Set(&minVertex_Boundary, 7.5, 7.5, 0);//ground
    Vector3_Set(&maxVertex_Boundary, -7.5, -7.5, -0.1);
    CollideBox_Set(&collideBoxes_Boundary[0], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.4, -7.4, 0);//boundary west
    Vector3_Set(&maxVertex_Boundary, -7.8, 7.8, 2.5);
    CollideBox_Set(&collideBoxes_Boundary[1], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.4, -7.4, 0);//boundary south
    Vector3_Set(&maxVertex_Boundary, 7.8, -7.5, 2.5);
    CollideBox_Set(&collideBoxes_Boundary[2], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, 7.4, 7.4, 0);//boundary east
    Vector3_Set(&maxVertex_Boundary, 7.8, -7.8, 2.5);
    CollideBox_Set(&collideBoxes_Boundary[3], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, 7.4, 7.4, 0);//boundary north
    Vector3_Set(&maxVertex_Boundary, -7.8, 7.8, 2.5);
    CollideBox_Set(&collideBoxes_Boundary[4], &minVertex_Boundary, &maxVertex_Boundary);

    struct Transform transform_Boundary;
    struct Mesh *mesh_Boundary = ModelTest_boundary_New();
    ModelTest_boundary_Init(mesh_Boundary);
    Transform_Init(&transform_Boundary, NULL);

    struct Object* Map_Boundary = Object_New(mesh_Boundary, &transform_Boundary, WALL, collideBoxes_Boundary, collideBoxCount_Boundary);

    ArrayList_PushBack(&scene->list_Object, Map_Boundary);
    //Map_boundary finished

    //Map_barrier origin coordinate (0,0,0)
    struct Vector3 minVertex_Barrier, maxVertex_Barrier;
    int collideBoxCount_Barrier = 2;
    struct CollideBox *collideBoxes_Barrier = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount_Barrier);

    Vector3_Set(&minVertex_Barrier, -2.9, -4.57, 0);    //barrier left
    Vector3_Set(&maxVertex_Barrier, -3.1, 7.43, 2.5);
    CollideBox_Set(&collideBoxes_Barrier[0], &minVertex_Barrier, &maxVertex_Barrier);

    Vector3_Set(&minVertex_Barrier, 2.9, -7.29, 0);    //barrier right
    Vector3_Set(&maxVertex_Barrier, 3.1, 4.9, 2.5);
    CollideBox_Set(&collideBoxes_Barrier[1], &minVertex_Barrier, &maxVertex_Barrier);

    struct Transform transform_Barrier;
    struct Mesh *mesh_Barrier = ModelWall_New();
    ModelWall_Init(mesh_Barrier)
    Transform_Init(&transform_Barrier, NULL);

    struct Object* Map_Barrier = Object_New(mesh_Barrier, &transform_Barrier, WALL, collideBoxes_Barrier, collideBoxCount_Barrier);

    ArrayList_PushBack(&scene->list_Object, Map_Barrier);
>>>>>>> Stashed changes
}

void Del_Scene(struct Scene *scene){
    Del_ArrayList(&scene->list_Object);
    Del_ArrayList(&scene->list_Enemy);
    Del_Player(&scene->player);
}