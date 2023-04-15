#include "scene.h"
#include "../op_engine/object.h"
#include "../Game/models/models.h"
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
    for (int i = 0; i < scene->list_Object.size; i++){
        struct Object *object = ((struct Object**)scene->list_Object.data)[i];
        Object_Show(object, canvas);
    }
    for (int i = 0; i < scene->list_Enemy.size; i++){
        struct Enemy *enemy = ((struct Enemy**)scene->list_Object.data)[i];
        struct Object
                *head = &enemy->face,
                *body = &enemy->body,
                *leg = &enemy->leg;
        Object_Show(head, canvas);
        Object_Show(body, canvas);
        Object_Show(leg, canvas);
    }
}

void Scene_EnemyCollided(struct Scene *scene, struct Line *ray, struct Enemy **result_enemy, enum Tag *result_tag){
    double min_dist = INFINITY;

    // loop through an ArrayList of enemies, detecting the min_dist of the ray to all enemies
    for (int i = 0; i < scene->list_Enemy.size; i++){
        struct Enemy *current_enemy = ((struct Enemy**)scene->list_Enemy.data)[i];
        double head_dist = CollideBox_RayDistance(current_enemy->face.collideBoxes,
                                                  &current_enemy->face.transform, ray);
        if (head_dist < min_dist){
            min_dist = head_dist;
            *result_enemy = current_enemy;
            *result_tag = current_enemy->face.tag;
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

void Enemy_Move(struct Enemy* enemy, struct Vector3* move);

void Enemy_Update(struct Enemy* enemy, bool do_find_way, struct Scene* scene, struct link* current)
{
    if (do_find_way){
        struct link* beginning = Find_Way(&enemy->body,scene);//beginning actually refers to current position of bot.
        current = beginning;
    }
    struct Transform* target = current->next->current;
    struct Vector3* move = (struct Vector3*)malloc(sizeof(struct Vector3));
    Transform_UpdateGlobal(&enemy->transform);
    Vector3_Set(move,
                target->globalPosition.x - enemy->transform.globalPosition.x,
                target->globalPosition.y - enemy->transform.globalPosition.y,
                target->globalPosition.z - enemy->transform.globalPosition.z);
    Enemy_Move(enemy, move);
}

void Enemy_Move(struct Enemy* enemy, struct Vector3* move){
    Transform_AddPosition(&enemy->transform, move);
}

#define typename struct Object
//build a linked list to find the shortest way from enemy to player.
struct link* Find_Way(struct Object *enemy, struct Scene* scene)
{
    unsigned int size = scene->list_Object.size;
    double min_distance = INFINITY, distance;
    typename* list = (typename*)scene->list_Object.data;
    struct Line* ray = NULL;
    struct Player* player = &scene->player;
    struct Object* min_distance_obj = (struct Object*)malloc(sizeof(struct Object)),*min_temp = (struct Object*)malloc(sizeof(struct Object));
    Transform_UpdateGlobal(&player->transform);
    min_distance_obj->transform.globalPosition.x = player->transform.globalPosition.x;
    min_distance_obj->transform.globalPosition.y = player->transform.globalPosition.y;
    min_distance_obj->transform.globalPosition.z = player->transform.globalPosition.z;
    struct link* destination = NULL;
    destination->next = NULL;
    destination->current = &min_distance_obj->transform;
    struct link* next_addr = destination;

    while(!	(min_distance_obj->transform.globalPosition.x == enemy->transform.globalPosition.x &&
                min_distance_obj->transform.globalPosition.z == enemy->transform.globalPosition.z)){
        for (int j=0;j<size;j++){
            if (min_distance_obj->transform.globalPosition.x==list[j].transform.globalPosition.x
                &&  min_distance_obj->transform.globalPosition.z==list[j].transform.globalPosition.z) continue;
            if (list[j].tag == WALL) continue;
            struct Vector3* direction = (struct Vector3*)malloc(sizeof(struct Vector3));
            Transform_UpdateGlobal(&list[j].transform);
            Vector3_Set(direction,
                        min_distance_obj->transform.globalPosition.x-list[j].transform.globalPosition.x,
                        min_distance_obj->transform.globalPosition.y-list[j].transform.globalPosition.y,
                        min_distance_obj->transform.globalPosition.z-list[j].transform.globalPosition.z);
            Line_Set(ray,&list[j].transform.globalPosition,direction);
            distance = CollideBox_RayDistance(enemy->collideBoxes,&list[j].transform,ray);
            if (distance == INFINITY) continue;
            if (distance < min_distance){
                min_distance = distance;
                min_temp = &list[j];
            }
        }
        struct link* link = NULL;
        link->current = &min_temp->transform;
        link->next = next_addr;
        min_distance_obj = min_temp;
        next_addr = link;
        min_temp = NULL;
    }

    struct link* beginning = NULL;
    beginning->current = &enemy->transform;
    beginning->next = next_addr;

    return beginning;
}