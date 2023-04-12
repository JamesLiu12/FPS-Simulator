#include "scene.h"
#include "../op_engine/object.h"
#include "../Game/models/models.h"

void Scene_Init(struct Scene *scene){
    ArrayList_Init(&scene->list_Object, sizeof(struct Object*));
    ArrayList_Init(&scene->list_Enemy, sizeof(struct Enemy*));
    Player_Init(&scene->player);

    //Map_boundary origin coordinate (0,0,0)
    struct Vector3 minVertex_Boundary, maxVertex_Boundary;
    int collideBoxCount_Boundary = 4;
    struct CollideBox *collideBoxes_Boundary = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount_Boundary);
    //set collideBoxes:

    Vector3_Set(&minVertex_Boundary, -7.8, 0, -7.8);//boundary west
    Vector3_Set(&maxVertex_Boundary, -7.4, 2.5, 7.4);
    CollideBox_Set(&collideBoxes_Boundary[1], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.8, 0, -7.8);//boundary south
    Vector3_Set(&maxVertex_Boundary, 7.4, 2.5, -7.4);
    CollideBox_Set(&collideBoxes_Boundary[2], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, 7.4, 0, -7.4);//boundary east
    Vector3_Set(&maxVertex_Boundary, 7.8, 2.5, 7.8);
    CollideBox_Set(&collideBoxes_Boundary[3], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.4, 0, 7.4);//boundary north
    Vector3_Set(&maxVertex_Boundary, 7.8, 2.5, 7.8);
    CollideBox_Set(&collideBoxes_Boundary[4], &minVertex_Boundary, &maxVertex_Boundary);

    struct Transform transform_Boundary;
    struct Mesh *mesh_Boundary = ModelBoundaries_New();
    ModelBoundaries_Init(mesh_Boundary);
    Transform_Init(&transform_Boundary, NULL);

    struct Object* Map_Boundary = Object_New(mesh_Boundary, &transform_Boundary, WALL, collideBoxes_Boundary, collideBoxCount_Boundary);

    ArrayList_PushBack(&scene->list_Object, &Map_Boundary);
    //Map_boundary finished

    //Map_barrier origin coordinate (0,0,0)
    struct Vector3 minVertex_Barrier, maxVertex_Barrier;
    int collideBoxCount_Barrier = 2;
    struct CollideBox *collideBoxes_Barrier = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount_Barrier);

    Vector3_Set(&minVertex_Barrier, -3.2, 0, -4.57);    //barrier left
    Vector3_Set(&maxVertex_Barrier, -2.9, 2.5, 7.43);
    CollideBox_Set(&collideBoxes_Barrier[0], &minVertex_Barrier, &maxVertex_Barrier);

    Vector3_Set(&minVertex_Barrier, 2.9, 0, -7.29);    //barrier right
    Vector3_Set(&maxVertex_Barrier, 3.1, 2.5, 4.9);
    CollideBox_Set(&collideBoxes_Barrier[1], &minVertex_Barrier, &maxVertex_Barrier);

    struct Transform transform_Barrier;
    struct Mesh *mesh_Barrier = ModelWall_New();
    ModelWall_Init(mesh_Barrier);
    Transform_Init(&transform_Barrier, NULL);

    struct Object* Map_Barrier = Object_New(mesh_Barrier, &transform_Barrier, WALL, collideBoxes_Barrier, collideBoxCount_Barrier);

    ArrayList_PushBack(&scene->list_Object, &Map_Barrier);

    //Map_Floor origin coordinate (0,0,0)
    struct Vector3 minVertex_Floor, maxVertex_Floor;
    int collideBoxCount_Floor = 1;
    struct CollideBox *collideBoxes_Floor = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount_Floor);

    Vector3_Set(&minVertex_Floor, -7.5, -0.1, -7.5);    //floor
    Vector3_Set(&maxVertex_Floor, 7.5, 0, 7.5);
    CollideBox_Set(&collideBoxes_Barrier[0], &minVertex_Barrier, &maxVertex_Barrier);

    struct Transform transform_Floor;
    struct Mesh *mesh_Floor = ModelFloor_New();
    ModelFloor_Init(mesh_Floor);
    Transform_Init(&transform_Floor, NULL);

    struct Object* Map_Floor= Object_New(mesh_Floor, &transform_Floor, FLOOR, collideBoxes_Floor, collideBoxCount_Floor);

    ArrayList_PushBack(&scene->list_Object, &Map_Floor);

    //enemy origin coordinate (0,0,0)
    struct Vector3 minVertex_enemy, maxVertex_enemy;
    int collideBoxCount_enemy = 1;
    struct CollideBox *collideBoxes_enemy = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount_enemy);

    Vector3_Set(&minVertex_enemy, -0.3, 0, -0.3);    //total
    Vector3_Set(&maxVertex_enemy, 0.3, 1.9, 0.3);
    CollideBox_Set(&collideBoxes_enemy[0], &minVertex_enemy, &maxVertex_enemy);

    struct Transform transform_enemy;
    struct Mesh *mesh_enemy = ModelEnemy_model_New();
    ModelEnemy_model_Init(mesh_enemy);
    Transform_Init(&transform_enemy, NULL);

    struct Object* Map_enemy= Object_New(mesh_enemy, &transform_enemy, Enemy->, collideBoxes_Floor, collideBoxCount_Floor);

    ArrayList_PushBack(&scene->list_Enemy, &Map_enemy);
}

void Del_Scene(struct Scene *scene){
    Del_ArrayList(&scene->list_Object);
    Del_ArrayList(&scene->list_Enemy);
    Del_Player(&scene->player);
}

void Scene_Show(struct Scene *scene, struct Canvas *canvas){
    for (int i = 0; i < scene->list_Object.size; i++){
        struct Object *object = ((struct Object**)scene->list_Object.data)[i];
        Object_Show(object, canvas);
    }
    for (int i = 0; i < scene->list_Enemy.size; i++){
        struct Enemy *enemy = ((struct Enemy**)scene->list_Object.data)[i];
        struct Object
                *head = &enemy->head,
                *body = &enemy->body,
                *leg = &enemy->leg;
        Object_Show(head, canvas);
        Object_Show(body, canvas);
        Object_Show(leg, canvas);
    }
}