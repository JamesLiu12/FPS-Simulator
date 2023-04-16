#include "scene.h"
#include "../op_engine/object.h"
#include "../Game/models/models.h"
#include "../util/array_list.h"
#include "../util/util.h"
#include "runner.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
void Scene_Init(struct Scene *scene){
    srand((int)time(NULL));
    ArrayList_Init(&scene->list_Object, sizeof(struct Object*));
    ArrayList_Init(&scene->list_Enemy, sizeof(struct Enemy*));
    Player_Init(&scene->player);


    //Map_boundary origin coordinate (0,0,0)
    
    struct Vector3 minVertex_Boundary, maxVertex_Boundary;
    int collideBoxCount_Boundary = 4;
    struct CollideBox *collideBoxes_Boundary = (struct CollideBox *) malloc(
            sizeof(struct CollideBox) * collideBoxCount_Boundary);
    //set collideBoxes:

    Vector3_Set(&minVertex_Boundary, -7.8, 0, -7.8);//boundary west
    Vector3_Set(&maxVertex_Boundary, -7.4, 2.5, 7.4);
    CollideBox_Set(&collideBoxes_Boundary[0], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.8, 0, -7.8);//boundary south
    Vector3_Set(&maxVertex_Boundary, 7.4, 2.5, -7.4);
    CollideBox_Set(&collideBoxes_Boundary[1], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, 7.4, 0, -7.4);//boundary east
    Vector3_Set(&maxVertex_Boundary, 7.8, 2.5, 7.8);
    CollideBox_Set(&collideBoxes_Boundary[2], &minVertex_Boundary, &maxVertex_Boundary);

    Vector3_Set(&minVertex_Boundary, -7.4, 0, 7.4);//boundary north
    Vector3_Set(&maxVertex_Boundary, 7.8, 2.5, 7.8);
    CollideBox_Set(&collideBoxes_Boundary[3], &minVertex_Boundary, &maxVertex_Boundary);

    struct Transform transform_Boundary;
    struct Mesh *mesh_Boundary = ModelBoundaries_New();
    ModelBoundaries_Init(mesh_Boundary);
    Transform_Init(&transform_Boundary, NULL);

    struct Object *Map_Boundary = Object_New(mesh_Boundary, &transform_Boundary, WALL,
            collideBoxes_Boundary,collideBoxCount_Boundary);

    ArrayList_PushBack(&scene->list_Object, &Map_Boundary);
    //Map_boundary finished

    //Map_barrier origin coordinate (0,0,0)
    struct Vector3 minVertex_Barrier, maxVertex_Barrier;
    int collideBoxCount_Barrier = 2;
    struct CollideBox *collideBoxes_Barrier = (struct CollideBox *) malloc(
            sizeof(struct CollideBox) * collideBoxCount_Barrier);

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

    struct Object *Map_Barrier = Object_New(mesh_Barrier, &transform_Barrier, WALL,
            collideBoxes_Barrier,collideBoxCount_Barrier);

    ArrayList_PushBack(&scene->list_Object, &Map_Barrier);

//    Map_Floor origin coordinate (0,0,0)
    struct Vector3 minVertex_Floor, maxVertex_Floor;
    int collideBoxCount_Floor = 1;
    struct CollideBox *collideBoxes_Floor = (struct CollideBox *) malloc(
            sizeof(struct CollideBox) * collideBoxCount_Floor);

    Vector3_Set(&minVertex_Floor, -7.5, -0.1, -7.5);    //floor
    Vector3_Set(&maxVertex_Floor, 7.5, 0, 7.5);
    CollideBox_Set(&collideBoxes_Floor[0], &minVertex_Floor, &maxVertex_Floor);

    struct Transform transform_Floor;
    struct Mesh *mesh_Floor = ModelFloor_New();
    ModelFloor_Init(mesh_Floor);
    Transform_Init(&transform_Floor, NULL);

    struct Object *Map_Floor = Object_New(mesh_Floor, &transform_Floor, FLOOR,
            collideBoxes_Floor,collideBoxCount_Floor);

    ArrayList_PushBack(&scene->list_Object, &Map_Floor);

    //Enemy_Head
    struct Vector3 minVertex_EnemyHead, maxVertex_EnemyHead;
    int collideBoxCount_EnemyHead = 1;
    struct CollideBox *collideBoxes_EnemyHead = (struct CollideBox *) malloc(
            sizeof(struct CollideBox) * collideBoxCount_EnemyHead);

    Vector3_Set(&minVertex_EnemyHead, -0.35, 1.4, -0.35);    //Head
    Vector3_Set(&maxVertex_EnemyHead, 0.35, 2.1, 0.35);
    CollideBox_Set(&collideBoxes_EnemyHead[0], &minVertex_EnemyHead, &maxVertex_EnemyHead);

    struct Transform transform_EnemyHead;
    struct Mesh *mesh_EnemyHead = ModelEnemy_Head_New();
    ModelEnemy_Head_Init(mesh_EnemyHead);
    Transform_Init(&transform_EnemyHead, NULL);

    struct Object *Enemy_Head = Object_New(mesh_EnemyHead, &transform_EnemyHead, ENEMY_HEAD,
            collideBoxes_EnemyHead,collideBoxCount_EnemyHead);
    scene->enemyHead_obj = Enemy_Head;

    //Enemy_body
    struct Vector3 minVertex_EnemyBody, maxVertex_EnemyBody;
    int collideBoxCount_EnemyBody = 1;
    struct CollideBox *collideBoxes_EnemyBody = (struct CollideBox *) malloc(
            sizeof(struct CollideBox) * collideBoxCount_EnemyBody);

    Vector3_Set(&minVertex_EnemyBody, -0.15, 0.4, -0.15);    //Body
    Vector3_Set(&maxVertex_EnemyBody, 0.15, 1.4, 0.15);
    CollideBox_Set(&collideBoxes_EnemyBody[0], &minVertex_EnemyBody, &maxVertex_EnemyBody);

    struct Transform transform_EnemyBody;
    struct Mesh *mesh_EnemyBody = ModelEnemy_Body_New();
    ModelEnemy_Body_Init(mesh_EnemyBody);
    Transform_Init(&transform_EnemyBody, NULL);

    struct Object *Enemy_Body = Object_New(mesh_EnemyBody, &transform_EnemyBody, ENEMY_BODY,
            collideBoxes_EnemyBody,collideBoxCount_EnemyBody);
    scene->enemyBody_obj = Enemy_Body;

    //Enemy_Leg
    struct Vector3 minVertex_EnemyLeg, maxVertex_EnemyLeg;
    int collideBoxCount_EnemyLeg = 1;
    struct CollideBox *collideBoxes_EnemyLeg = (struct CollideBox *) malloc(
            sizeof(struct CollideBox) * collideBoxCount_EnemyLeg);

    Vector3_Set(&minVertex_EnemyLeg, -0.37, 0, -0.37);    //Leg
    Vector3_Set(&maxVertex_EnemyLeg, 0.37, 0.4, 0.37);
    CollideBox_Set(&collideBoxes_EnemyLeg[0], &minVertex_EnemyLeg, &maxVertex_EnemyLeg);

    struct Transform transform_EnemyLeg;
    struct Mesh *mesh_EnemyLeg = ModelEnemy_Leg_New();
    ModelEnemy_Leg_Init(mesh_EnemyLeg);
    Transform_Init(&transform_EnemyLeg, NULL);

    struct Object *Enemy_Leg = Object_New(mesh_EnemyLeg, &transform_EnemyLeg, ENEMY_LEG,
            collideBoxes_EnemyLeg,collideBoxCount_EnemyLeg);
    scene->enemyLeg_obj = Enemy_Leg;

    printf("\033[32;16O");
}


void Del_Scene(struct Scene *scene){
    for (int i = 0; i < scene->list_Object.size; i++){
        struct Object *object = ((struct Object**)scene->list_Object.data)[i];
        Del_Object(object);
        free(object);
    }

    for (int i = 0; i < scene->list_Enemy.size; i++){
        struct Enemy *enemy = ((struct Enemy**)scene->list_Enemy.data)[i];
        Del_Enemy(enemy);
        free(enemy);
    }

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
    printf("\n");
    for(int i=0;i<52;i++)printf("-");
    printf("\n|");
    int temp=50*scene->player.health/100;
    for(int i=0;i<temp;i++)printf("█");
    for(int i=0;i<50-temp;i++)printf(" ");
    printf("|\n");
    for(int i=0;i<52;i++)printf("-");
    printf("\n");
    for(int i=0;i<16;i++)printf(" ");
    printf("HP : %.2lf / %.0lf \n",scene->player.health,scene->player.maxHealth);
    //The following 2 lines are for debugging
    //TODO
    //Delete it when the game is finished
    printf("%lf %lf %lf\n",scene->player.facing.x,scene->player.facing.y,scene->player.facing.z);
    printf("%lf %lf %lf\n",scene->player.transform.position.x,scene->player.transform.position.y,scene->player.transform.position.z);
    printf("\033[16;60HX");
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
