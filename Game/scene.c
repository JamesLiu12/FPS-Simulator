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
#include "../util/util.h"

void Scene_Init(struct Scene *scene){
    srand((int)time(NULL));
    ArrayList_Init(&scene->list_Object, sizeof(struct Object*));
    ArrayList_Init(&scene->list_Enemy, sizeof(struct Enemy*));
    Player_Init(&scene->player);
    Vector3_Set(&scene->player.transform.position, 0, 0, -3);


    //Map_boundary origin coordinate (0,0,0)

    //Map_boundary
    struct Mesh *mesh_Boundary = ModelBoundaries_New();
    ModelBoundaries_Init(mesh_Boundary);
    struct Object *Map_Boundary = Object_New(mesh_Boundary, NULL, WALL);

    //set collideBoxes:
    struct CollideBox *collideBoxes_Boundary = (struct CollideBox *) malloc(sizeof(struct CollideBox) * 4);

    //boundary west
    CollideBox_Init(&collideBoxes_Boundary[0], &Map_Boundary->transform, 0.4, 2.5, 15.2);
    Vector3_Set(&collideBoxes_Boundary[0].transform.position, -7.6, 1.25, -0.2);

    //boundary south
    CollideBox_Init(&collideBoxes_Boundary[1], &Map_Boundary->transform, 15.2, 2.5, 0.4);
    Vector3_Set(&collideBoxes_Boundary[1].transform.position, -0.2, 1.25, -7.6);

    //boundary east
    CollideBox_Init(&collideBoxes_Boundary[2], &Map_Boundary->transform, 0.4, 2.5, 15.2);
    Vector3_Set(&collideBoxes_Boundary[2].transform.position, 7.6, 1.25, 0.2);

    //boundary north
    CollideBox_Init(&collideBoxes_Boundary[3], &Map_Boundary->transform, 15.2, 2.5, 0.4);
    Vector3_Set(&collideBoxes_Boundary[3].transform.position, 0.2, 1.25, 7.6);

    Object_SetCollideBoxes(Map_Boundary, collideBoxes_Boundary, 4);

    ArrayList_PushBack(&scene->list_Object, &Map_Boundary);

    //Map_barrier origin coordinate (0,0,0)
    struct Mesh *mesh_Barrier = ModelWall_New();
    ModelWall_Init(mesh_Barrier);
    struct Object *Map_Barrier = Object_New(mesh_Barrier, NULL, WALL);

    struct CollideBox *collideBoxes_Barrier = (struct CollideBox *) malloc(sizeof(struct CollideBox) * 2);

    //barrier left
    CollideBox_Init(&collideBoxes_Barrier[0], &Map_Barrier->transform, 0.3, 2.5, 12);
    Vector3_Set(&collideBoxes_Barrier[0].transform.position, -3.05, 1.25, 1.43);

    //barrier right
    CollideBox_Init(&collideBoxes_Barrier[1], &Map_Barrier->transform, 0.2, 2.5, 12.19);
    Vector3_Set(&collideBoxes_Barrier[1].transform.position, 3, 1.25, -1.195);

    Object_SetCollideBoxes(Map_Barrier, collideBoxes_Barrier, 2);

    ArrayList_PushBack(&scene->list_Object, &Map_Barrier);

    //    Map_Floor origin coordinate (0,0,0)
    struct Transform transform_Floor;
    struct Mesh *mesh_Floor = ModelFloor_New();
    ModelFloor_Init(mesh_Floor);
    struct Object *Map_Floor = Object_New(mesh_Floor, NULL, FLOOR);
    struct CollideBox *collideBoxes_Floor = (struct CollideBox *) malloc(sizeof(struct CollideBox));

    CollideBox_Init(&collideBoxes_Floor[0], &Map_Floor->transform, 15, 0.1, 15);
    Vector3_Set(&collideBoxes_Floor[0].transform.position, 0, -0.05, 0);

    Object_SetCollideBoxes(Map_Floor, collideBoxes_Floor, 1);

    ArrayList_PushBack(&scene->list_Object, &Map_Floor);

    //Initialize the meshes of enemy
    EnemyMeshes_Init(&scene->enemyMeshes,
                     ModelEnemy_Head_New(), ModelEnemy_Body_New(), ModelEnemy_Leg_New());

    printf("\033[32;16O");
    //Sample Enemy generate test
    struct Enemy *enemy = New_Enemy(&scene->enemyMeshes);
    ArrayList_PushBack(&scene->list_Enemy, &enemy);
    Vector3_Set(&enemy->transform.position, 0, 0 ,0);
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

void Scene_Update(struct Scene *scene, double delta_time){

    Transform_UpdateGlobal(&scene->player.transform);
    for (int i = 0; i < scene->list_Enemy.size; i++){
        struct Enemy *enemy = ((struct Enemy**)scene->list_Enemy.data)[i];

        Transform_UpdateGlobal(&enemy->transform);

        struct Vector3 enemyPosition = enemy->transform.globalPosition,
                playerPosition = scene->player.transform.globalPosition;

        enemyPosition.y = 1;
        playerPosition.y = 1;

        struct Line ray;
        struct Vector3 positionDiff;
        positionDiff = playerPosition;
        Vector3_Subtract(&positionDiff, &enemyPosition);
        Line_Set(&ray, &enemyPosition, &positionDiff);

        double distanceBetween = Vector3_Distance3D(&enemyPosition, &playerPosition);
        enemy->canSeePlayer = Scene_MinDistanceWall(scene, &ray) > distanceBetween;

        enemy->moveDirection = positionDiff;
        Vector3_Normalize(&enemy->moveDirection);
        enemy->destination = playerPosition;

        Enemy_Update(enemy, delta_time);

        if (Enemy_IsTargetInAttackRange(enemy, &playerPosition)){
            //TODO Enemy攻击，记得判断CD
        }
    }

    Player_Update(&scene->player, delta_time);
    if (scene->player.IsFiring){
        Scene_PlayerShoot(scene);
    }
    Canvas_clear(&scene->player.canvas);
    Scene_Show(scene, &scene->player.canvas);
    Canvas_flush(&scene->player.canvas);
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
        double head_dist = CollideBox_RayDistance(current_enemy->head.collideBoxes, ray);
        if (head_dist < min_dist){
            min_dist = head_dist;
            *result_enemy = current_enemy;
            *result_tag = current_enemy->head.tag;
        }
        double body_dist = CollideBox_RayDistance(current_enemy->body.collideBoxes, ray);
        if (body_dist < min_dist){
            min_dist = body_dist;
            *result_enemy = current_enemy;
            *result_tag = current_enemy->body.tag;
        }
        double leg_dist = CollideBox_RayDistance(current_enemy->leg.collideBoxes, ray);
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
            double collideBox_dist = CollideBox_RayDistance(&current_object->collideBoxes[j], ray);
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

double Scene_DamageCalculation(struct Scene *scene, struct Enemy *enemy)//enemy's damage to player
{
    double roller = rand() % 100;
    double rate = roller * enemy->Critical_Rate;//this value should be 0-5000
    if (roller >= 2345/*critical damage*/){ return pow(enemy->damage/scene->player.defence,2); }
    else { return enemy->damage/scene->player.defence; }
}

double Scene_MinDistanceWall(struct Scene *scene, struct Line *ray){
    double minDistance = INFINITY;
    for (int j = 0; j < scene->list_Object.size; j++){
        struct Object *object = ((struct Object**)scene->list_Object.data)[j];
        if (object->tag != WALL) continue;
        for (int k = 0; k < object->collideBoxCount; k++){
            struct CollideBox *collideBox = &object->collideBoxes[k];
            double distance = CollideBox_RayDistance(collideBox, ray);
            if (minDistance > distance) minDistance = distance;
        }
    }
    return minDistance;
}

void Scene_PlayerShoot(struct Scene *scene){
    struct Line ray;
    Transform_UpdateGlobal(&scene->player.canvas.camera_transform);
    Line_Set(&ray, &scene->player.canvas.camera_transform.globalPosition, &scene->player.facing);
    struct Enemy *enemy;
    enum Tag tag;
    Scene_EnemyCollided(scene, &ray, &enemy, &tag);
    if (enemy == NULL) return;
    //TODO 被射中之后干啥，冷却计算啥的
    puts("TMD，老子被射了，真tnd痛");

}