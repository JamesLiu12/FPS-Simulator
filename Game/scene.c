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
    Vector3_Set(&scene->player.transform.position, 0, 1, 0);


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

    struct Object *Map_Boundary = Object_New(mesh_Boundary, NULL, WALL,
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

    struct Object *Map_Barrier = Object_New(mesh_Barrier, NULL, WALL,
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

    struct Object *Map_Floor = Object_New(mesh_Floor, NULL, FLOOR,
            collideBoxes_Floor,collideBoxCount_Floor);

    ArrayList_PushBack(&scene->list_Object, &Map_Floor);

    //Initialize the meshes of enemy
    EnemyMeshes_Init(&scene->enemyMeshes,
                     ModelEnemy_Head_New(), ModelEnemy_Body_New(), ModelEnemy_Leg_New());

    printf("\033[32;16O");
    //Sample Enemy generate test
    struct Enemy *enemy = New_Enemy(&scene->enemyMeshes);
    ArrayList_PushBack(&scene->list_Enemy, &enemy);
    Vector3_Set(&enemy->transform.position, 0, 1.05 ,0);
    //Sample end
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
        struct Enemy *enemy = ((struct Enemy**)scene->list_Enemy.data)[i];
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
