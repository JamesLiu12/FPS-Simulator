#include "scene.h"
#include "../op_engine/object.h"
#include "../Game/models/models.h"
#include "runner.h"
#include <math.h>

void Scene_Init(struct Scene *scene){
    ArrayList_Init(&scene->list_Object, sizeof(struct Object*));
    ArrayList_Init(&scene->list_Enemy, sizeof(struct Enemy*));
    Player_Init(&scene->player);

    //Map_boundary origin coordinate (0,0,0)
    struct Vector3 minVertex_Boundary, maxVertex_Boundary;
    int collideBoxCount_Boundary = 5;
    struct CollideBox *collideBoxes_Boundary = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount_Boundary);
    //set collideBoxes:

    Vector3_Set(&minVertex_Boundary, -7.5, -7.5, -0.1);//ground
    Vector3_Set(&maxVertex_Boundary, 7.5, 7.5, 0);
    CollideBox_Set(&collideBoxes_Boundary[0], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.8, -7.8, 0);//boundary west
    Vector3_Set(&maxVertex_Boundary, -7.4, 7.4, 2.5);
    CollideBox_Set(&collideBoxes_Boundary[1], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.8, -7.8, 0);//boundary south
    Vector3_Set(&maxVertex_Boundary, 7.4, -7.4, 2.5);
    CollideBox_Set(&collideBoxes_Boundary[2], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, 7.4, -7.4, 0);//boundary east
    Vector3_Set(&maxVertex_Boundary, 7.8, 7.8, 2.5);
    CollideBox_Set(&collideBoxes_Boundary[3], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.4, 7.4, 0);//boundary north
    Vector3_Set(&maxVertex_Boundary, 7.8, 7.8, 2.5);
    CollideBox_Set(&collideBoxes_Boundary[4], &minVertex_Boundary, &maxVertex_Boundary);

    struct Transform transform_Boundary;
    struct Mesh *mesh_Boundary = ModelTest_boundary_New();
    ModelTest_boundary_Init(mesh_Boundary);
    Transform_Init(&transform_Boundary, NULL);

    struct Object* Map_Boundary = Object_New(mesh_Boundary, &transform_Boundary, WALL, collideBoxes_Boundary, collideBoxCount_Boundary);

    ArrayList_PushBack(&scene->list_Object, &Map_Boundary);
    //Map_boundary finished

    //Map_barrier origin coordinate (0,0,0)
    struct Vector3 minVertex_Barrier, maxVertex_Barrier;
    int collideBoxCount_Barrier = 2;
    struct CollideBox *collideBoxes_Barrier = (struct CollideBox*)malloc(sizeof(struct CollideBox) * collideBoxCount_Barrier);

    Vector3_Set(&minVertex_Barrier, -3.2, -4.57, 0);    //barrier left
    Vector3_Set(&maxVertex_Barrier, -2.9, 7.43, 2.5);
    CollideBox_Set(&collideBoxes_Barrier[0], &minVertex_Barrier, &maxVertex_Barrier);

    Vector3_Set(&minVertex_Barrier, 2.9, -7.29, 0);    //barrier right
    Vector3_Set(&maxVertex_Barrier, 3.1, 4.9, 2.5);
    CollideBox_Set(&collideBoxes_Barrier[1], &minVertex_Barrier, &maxVertex_Barrier);

    struct Transform transform_Barrier;
    struct Mesh *mesh_Barrier = ModelWall_New();
    ModelWall_Init(mesh_Barrier);
    Transform_Init(&transform_Barrier, NULL);

    struct Object* Map_Barrier = Object_New(mesh_Barrier, &transform_Barrier, WALL, collideBoxes_Barrier, collideBoxCount_Barrier);

    ArrayList_PushBack(&scene->list_Object, &Map_Barrier);
}

void Del_Scene(struct Scene *scene){
    Del_ArrayList(&scene->list_Object);
    Del_ArrayList(&scene->list_Enemy);
    Del_Player(&scene->player);
}

void Scene_Show(struct Scene *scene, struct Canvas *canvas){
    Canvas_clear(canvas);
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
    Canvas_flush(canvas);
}

void Scene_EnemyCollided(struct Scene *scene, struct Line *ray, struct Enemy **result_enemy, enum Tag *result_tag){
    double min_dist = INFINITY;

    // loop through an ArrayList of enemies, detecting the min_dist of the ray to all enemies
    for (int i = 0; i < scene->list_Enemy.size; i++){
        struct Enemy *current_enemy = ((struct Enemy**)scene->list_Enemy.data)[i];
        double head_dist = CollideBox_RayDistance(current_enemy->head.collideBoxes,
                                                  &current_enemy->head.transform, ray);
        if (head_dist < min_dist){
            min_dist = head_dist;
            *result_enemy = current_enemy;
            *result_tag = current_enemy->head.tag;
        }
        double body_dist = CollideBox_RayDistance(current_enemy->body.collideBoxes,
                                                  &current_enemy->body.transform, ray);
        if (body_dist < min_dist){
            min_dist = body_dist;
            *result_enemy = current_enemy;
            *result_tag = current_enemy->body.tag;
        }
        double leg_dist = CollideBox_RayDistance(current_enemy->leg.collideBoxes,
                                                 &current_enemy->leg.transform, ray);
        if (leg_dist < min_dist){
            min_dist = leg_dist;
            *result_enemy = current_enemy;
            *result_tag = current_enemy->leg.tag;
        }
    }

    //condition of collides an object other than Enemy
    for (int i = 0; i < scene->list_Object.size; i++){
        struct Object *current_object = ((struct Object**)scene->list_Object.data)[i];

        for (int j = 0; j < current_object->collideBoxCount; j++){
            double collideBox_dist = CollideBox_RayDistance(&current_object->collideBoxes[j],
                                                            &current_object->transform, ray);
            if (collideBox_dist < min_dist){
                min_dist = collideBox_dist;
                *result_enemy = NULL;
                *result_tag = current_object->tag;
            }
        }
    }

    // condition of no collision
    if (min_dist == INFINITY){
        *result_enemy = NULL;
        *result_tag = EMPTY;
    }
}
