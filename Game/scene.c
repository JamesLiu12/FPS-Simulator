#include "scene.h"
#include "../op_engine/object.h"
#include "../Game/models/models.h"
#include "../util/array_list.h"
#include "../util/util.h"
#include "../op_engine/region2D.h"
#include "runner.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../util/util.h"
#define _USE_MATH_DEFINES

void Scene_Init(struct Scene *scene, enum WeaponName weaponname){
    srand((int)time(NULL));
    ArrayList_Init(&scene->list_Object, sizeof(struct Object*));
    ArrayList_Init(&scene->list_Enemy, sizeof(struct Enemy*));
    ArrayList_Init(&scene->list_EnemySpawnArea,sizeof(struct Region2D*));
    Player_Init(&scene->player, weaponname);
    Player_SetPosition(&scene->player, -17.5, 0, -17.5);
    scene->FAKE_WALL_shootcounter = 0;
    //Map_new_Wall origin coordinate (0,0,0)

    //Map_new_Walls
    struct Mesh *mesh_Wall = ModelMap_new_Wall_New();
    struct Object *Map_Wall = Object_New(mesh_Wall, NULL, WALL);
    //set collideBoxes:
    struct CollideBox *collideBoxes_Wall = (struct CollideBox *) malloc(sizeof(struct CollideBox) * 30);

    //Wall      Name Rule: from blender collection
    CollideBox_Init(&collideBoxes_Wall[0], &Map_Wall->transform, 80, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[0].transform.position, 20, 1.25, 20);
    //Wall_001
    CollideBox_Init(&collideBoxes_Wall[1], &Map_Wall->transform, 60, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[1].transform.position, 30, 1.25, -20);
    //Wall_002
    CollideBox_Init(&collideBoxes_Wall[2], &Map_Wall->transform, 40, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[2].transform.position, -20, 1.25, 0);
    Vector3_Set(&collideBoxes_Wall[2].transform.rotation,0,M_PI/2,0);
    //Wall_003
    CollideBox_Init(&collideBoxes_Wall[3], &Map_Wall->transform, 40, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[3].transform.position, 60, 1.25, 0);
    Vector3_Set(&collideBoxes_Wall[3].transform.rotation,0,M_PI/2,0);
    //Wall_004
    CollideBox_Init(&collideBoxes_Wall[4], &Map_Wall->transform, 30, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[4].transform.position, -15, 1.25, -5);
    Vector3_Set(&collideBoxes_Wall[4].transform.rotation,0,M_PI/2,0);
    //Wall_005
    CollideBox_Init(&collideBoxes_Wall[5], &Map_Wall->transform, 30, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[5].transform.position, -0.8, 1.25, 0.5);
    Vector3_Set(&collideBoxes_Wall[5].transform.rotation,0,-M_PI/4,0);
    //Wall_006
    CollideBox_Init(&collideBoxes_Wall[6], &Map_Wall->transform, 40, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[6].transform.position, 30, 1.25, 15);
    //Wall_007__ERROR FIX
    CollideBox_Init(&collideBoxes_Wall[7], &Map_Wall->transform, 13, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[7].transform.position, 0.5, 1.25, -10);
    Vector3_Set(&collideBoxes_Wall[7].transform.rotation,0,M_PI/4,0);
    //Wall_008
    CollideBox_Init(&collideBoxes_Wall[8], &Map_Wall->transform, 15, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[8].transform.position, 25, 1.25, -2.5);
    Vector3_Set(&collideBoxes_Wall[8].transform.rotation,0,M_PI/2,0);
    //Wall_009
    CollideBox_Init(&collideBoxes_Wall[9], &Map_Wall->transform, 15, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[9].transform.position, -3.5, 1.25, -3.5);
    Vector3_Set(&collideBoxes_Wall[9].transform.rotation,0,-M_PI/4,0);
    //Wall_010
    CollideBox_Init(&collideBoxes_Wall[10], &Map_Wall->transform, 9, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[10].transform.position, 10, 1.25, 10.55);
    Vector3_Set(&collideBoxes_Wall[10].transform.rotation,0,M_PI/2,0);
    //Wall_011
    CollideBox_Init(&collideBoxes_Wall[11], &Map_Wall->transform, 30, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[11].transform.position, 30, 1.25, 10);
    //Wall_012
    CollideBox_Init(&collideBoxes_Wall[12], &Map_Wall->transform, 7, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[12].transform.position, 0, 1.25, 8);
    Vector3_Set(&collideBoxes_Wall[12].transform.rotation,0,M_PI/3,0);
    //Wall_013
    CollideBox_Init(&collideBoxes_Wall[13], &Map_Wall->transform, 16, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[13].transform.position, -2, 1.25, -15);
    //Wall_014__ERROR FIX
    CollideBox_Init(&collideBoxes_Wall[14], &Map_Wall->transform, 5, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[14].transform.position, 10, 1.25, -12.5);
    Vector3_Set(&collideBoxes_Wall[14].transform.rotation,0,M_PI/2,0);
    //Wall_015
    CollideBox_Init(&collideBoxes_Wall[15], &Map_Wall->transform, 40, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[15].transform.position, 40, 1.25, -15);
    //Wall_016__ERROR FIX
    CollideBox_Init(&collideBoxes_Wall[16], &Map_Wall->transform, 5, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[16].transform.position, 12.5, 1.25, -10);
    //Wall_017__ERROR FIX
    CollideBox_Init(&collideBoxes_Wall[17], &Map_Wall->transform, 30, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[17].transform.position, 15, 1.25, -5);
    Vector3_Set(&collideBoxes_Wall[17].transform.rotation,0,M_PI/2,0);
    //Wall_018__ERROR FIX
    CollideBox_Init(&collideBoxes_Wall[18], &Map_Wall->transform, 20, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[18].transform.position, 20, 1.25, -5);
    Vector3_Set(&collideBoxes_Wall[18].transform.rotation,0,M_PI/2,0);
    //Wall_019__ERROR FIX
    CollideBox_Init(&collideBoxes_Wall[19], &Map_Wall->transform, 20, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[19].transform.position, 45, 1.25, -5);
    Vector3_Set(&collideBoxes_Wall[19].transform.rotation,0,M_PI/2,0);
    //Wall_020
    CollideBox_Init(&collideBoxes_Wall[20], &Map_Wall->transform, 25, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[20].transform.position, 50, 1.25, 2.6);
    Vector3_Set(&collideBoxes_Wall[20].transform.rotation,0,M_PI/2,0);
    //Wall_021
    CollideBox_Init(&collideBoxes_Wall[21], &Map_Wall->transform, 20, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[21].transform.position, 35, 1.25, 5);
    //Wall_022
    CollideBox_Init(&collideBoxes_Wall[22], &Map_Wall->transform, 15, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[22].transform.position, 32.5, 1.25, -10);
    //Wall_023
    CollideBox_Init(&collideBoxes_Wall[23], &Map_Wall->transform, 10, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[23].transform.position, 40, 1.25, -5);
    Vector3_Set(&collideBoxes_Wall[23].transform.rotation,0,M_PI/2,0);
    //Wall_024
    CollideBox_Init(&collideBoxes_Wall[24], &Map_Wall->transform, 10, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[24].transform.position, 35, 1.25, 0);
    //Wall_025
    CollideBox_Init(&collideBoxes_Wall[25], &Map_Wall->transform, 5, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[25].transform.position, 30, 1.25, -2.5);
    Vector3_Set(&collideBoxes_Wall[25].transform.rotation,0,M_PI/2,0);
    //Wall_026
    CollideBox_Init(&collideBoxes_Wall[26], &Map_Wall->transform, 5, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[26].transform.position, 32.5, 1.25, -5);
    //Wall_027
    CollideBox_Init(&collideBoxes_Wall[27], &Map_Wall->transform, 16, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[27].transform.position, -1.3, 1.25, 15);
    //Wall_028
    CollideBox_Init(&collideBoxes_Wall[28], &Map_Wall->transform, 3, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[28].transform.position, 8.4, 1.25, 12);
    //Wall_029
    CollideBox_Init(&collideBoxes_Wall[29], &Map_Wall->transform, 3, 2.5, 0.2);
    Vector3_Set(&collideBoxes_Wall[29].transform.position, 6.8, 1.25, 13.5);
    Vector3_Set(&collideBoxes_Wall[29].transform.rotation,0,M_PI/2,0);

    Object_SetCollideBoxes(Map_Wall, collideBoxes_Wall, 30);

    ArrayList_PushBack(&scene->list_Object, &Map_Wall);


//    Map_EndGate origin coordinate (0,0,0)
    struct Mesh *mesh_EndGate = ModelMap_new_EndGate_New();
    struct Object *Map_EndGate = Object_New(mesh_EndGate, NULL, END);
    struct CollideBox *collideBoxes_EndGate = (struct CollideBox *) malloc(sizeof(struct CollideBox));

    CollideBox_Init(&collideBoxes_EndGate[0], &Map_EndGate->transform, 0.66, 4.06, 7);
    Vector3_Set(&collideBoxes_EndGate[0].transform.position, 57.8, 2.07, -0.1);

    Object_SetCollideBoxes(Map_EndGate, collideBoxes_EndGate, 1);

    ArrayList_PushBack(&scene->list_Object, &Map_EndGate);

    struct Mesh *mesh_TrueEndGate = TrueWall_New();
    struct Object *Map_TrueEndGate = Object_New(mesh_TrueEndGate, NULL, TRUE_END);

    struct CollideBox *collideBoxes_TrueEndGate = (struct CollideBox *) malloc(sizeof(struct CollideBox));

    CollideBox_Init(&collideBoxes_TrueEndGate[0], &Map_TrueEndGate->transform, 5, 2, 0.4);
    Vector3_Set(&collideBoxes_TrueEndGate[0].transform.position, 0, 1.5, 0);

    Object_SetCollideBoxes(Map_TrueEndGate, collideBoxes_TrueEndGate, 1);
    Vector3_Set(&Map_TrueEndGate->transform.position, -17.5, 0, -22);

    ArrayList_PushBack(&scene->list_Object, &Map_TrueEndGate);

    struct Mesh *mesh_FakeWall = TrueWall_New();
    struct Object *Map_FakeWall = Object_New(mesh_FakeWall, NULL, FAKE_WALL);

    struct CollideBox *collideBoxes_FakeWall = (struct CollideBox *) malloc(sizeof(struct CollideBox));

    CollideBox_Init(&collideBoxes_FakeWall[0], &Map_FakeWall->transform, 5, 2, 0.4);
    Vector3_Set(&collideBoxes_FakeWall[0].transform.position, 0, 1.5, 0);

    Object_SetCollideBoxes(Map_FakeWall, collideBoxes_FakeWall, 1);
    Vector3_Set(&Map_FakeWall->transform.position, -17.5, 0, -19);

    ArrayList_PushBack(&scene->list_Object, &Map_FakeWall);

    //    Map_Floor origin coordinate (0,0,0)
    struct Mesh *mesh_Floor = ModelMap_new_OnlyFloor_New();
    struct Object *Map_Floor = Object_New(mesh_Floor, NULL, FLOOR);
    struct CollideBox *collideBoxes_Floor = (struct CollideBox *) malloc(sizeof(struct CollideBox));

    CollideBox_Init(&collideBoxes_Floor[0], &Map_Floor->transform, 80, 0.1, 40);
    Vector3_Set(&collideBoxes_Floor[0].transform.position, 0,-1,0);

    Object_SetCollideBoxes(Map_Floor, collideBoxes_Floor, 1);

    ArrayList_PushBack(&scene->list_Object, &Map_Floor);

    
    //Initialize the meshes of enemy
    EnemyMeshes_Init(&scene->enemyMeshes,
                     ModelEnemy_Head_New(), ModelEnemy_Body_New(), ModelEnemy_Leg_New());

    printf("\033[32;16O");

    //Adding Enemy Spawn Areas
    Scene_Add_EnemySpawnArea(scene, -15, 15, 8, 8, 2);
    Scene_Add_EnemySpawnArea(scene, 25, 17.5, 50, 4, 15);
    Scene_Add_EnemySpawnArea(scene, 55, 12, 8, 8, 4);
    Scene_Add_EnemySpawnArea(scene, 55, -10, 8, 8, 4);
    Scene_Add_EnemySpawnArea(scene, 55, -10, 8, 8, 3);
    //Enemy generator 
    int maxX, minX, maxZ, minZ;
    for(int i=0; i < scene->list_EnemySpawnArea.size; i++){
        struct Region2D *region = ((struct Region2D**)scene->list_EnemySpawnArea.data)[i];
        maxX = region->x + region->length/2;
        minX = region->x - region->length/2;
        maxZ = region->z + region->width/2;
        minZ = region->z - region->width/2;
        for(int j = 0; j < region->number ; j++){
            struct Enemy *enemy = New_Enemy(&scene->enemyMeshes);

            Vector3_Set(&enemy->transform.position, minX + 1.0 * rand() / RAND_MAX * ( maxX - minX ), 0, minZ + 1.0 * rand() / RAND_MAX * ( maxZ - minZ ));
            
            ArrayList_PushBack(&scene->list_Enemy, &enemy);
        }
    }
    //Enemy generator  end
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
    for (int i = 0; i < scene->list_EnemySpawnArea.size; i++){
        struct Region2D *region = ((struct Region2D**)scene->list_EnemySpawnArea.data)[i];
        free(region);
    }
    Del_ArrayList(&scene->list_Object);
    Del_ArrayList(&scene->list_Enemy);
    Del_ArrayList(&scene->list_EnemySpawnArea);
    Del_Player(&scene->player);
}

void Scene_Update(struct Scene *scene, double delta_time){
    Transform_UpdateGlobal(&scene->player.transform);
    Transform_UpdateGlobal(&scene->player.collideBox.transform);
    
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
        enemy->canSeeTarget = (Scene_MinDistanceWall(scene, &ray) > distanceBetween) && (distanceBetween < enemy->senseDistance);
        enemy->moveDirection = positionDiff;
        Vector3_Normalize(&enemy->moveDirection);
        enemy->destination = playerPosition;
        if (Enemy_IsTargetInAttackRange(enemy, &playerPosition)){
            Enemy_Attack(enemy);
            if(enemy->ATTACKFLAG){
                Player_ChangeHealth(&scene->player,-enemy->damage*(1+ enemy->criticalDamage * (rand() % 100 > enemy->criticalRate)));
                Player_SetDamageFlag(&scene->player);
            }
        }
        Enemy_Update(enemy, delta_time);
        Enemy_Move(enemy,&enemy->moveDirection);
        if( Scene_Collided_Object(scene, &enemy->body.collideBoxes[0]) || 
            CollideBox_IsCollide(&enemy->body.collideBoxes[0], &scene->player.collideBox)){
            Vector3_Scale(&enemy->moveDirection, -1);
            Enemy_Move(enemy,&enemy->moveDirection);
        }

    }

    if (scene->player.FIREFLAG){
        Scene_PlayerShoot(scene);
    }
    Player_Update(&scene->player, delta_time);
    Player_Move(&scene->player, &scene->player.move);

    Scene_Player_WinningCheck(scene);
    if(scene->FAKE_WALL_shootcounter == 3) Scene_Delete_FakeWall(scene);
    if(Scene_Collided_Object(scene,&scene->player.collideBox)){
        Vector3_Scale(&scene->player.move, -1);
        Player_Move(&scene->player, &scene->player.move);
    }
    

#if DEBUG
    if (Scene_Collided_Enemy(scene, &scene->player.collideBox)){
        puts("Collide Enemy");
//        getchar();
    }
    if (Scene_Collided_Object(scene, &scene->player.collideBox)){
        puts("Collide Object");
//        getchar();
    }
#endif

    for (int i = 0; i < 10 ; i++)kbhit();
    Clear_Enemy(scene);
    Canvas_clear(&scene->player.canvas);
    Scene_Show(scene, &scene->player.canvas);
}

//print information bar in the position start_row and start_col, with bar_length and ratio
void print_bar(int bar_length, double ratio, int start_row, int start_col){
    move_cursor_to(start_row, start_col);
    for (int i = 0; i < bar_length + 2; i++) printf("-");
    move_cursor_to(start_row + 1, start_col);
    printf("|");
    for (int i = 0; i < (int)(bar_length * ratio); i++) printf("█");
    for (int i = 0; i < bar_length - (int)(bar_length * ratio); i++) printf(" ");
    printf("|");
    move_cursor_to(start_row + 2, start_col);
    for (int i = 0; i < bar_length + 2; i++) printf("-");
}

void Scene_Show(struct Scene *scene, struct Canvas *canvas){
    Canvas_clear(canvas);

    //Draw all the object
    for (int i = 0; i < scene->list_Object.size; i++){
        struct Object *object = ((struct Object**)scene->list_Object.data)[i];
        Object_Show(object, canvas);
    }

    //Draw all the enemy
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

    //Print if it is loading the bullet now
    printf("\033[36;100H");
    printf("\n");
    if (scene->player.inReloadCD == 1){
        for (int i = 0; i < 87; i++) printf(" ");
        printf("Reloading\n");
    }
    else{
        printf("\r");
        for (int i = 0; i < 100; i++) printf(" ");
        printf("\n");
    }

    //Get the position of the cursor
    int row = canvas->height + 1, col = 0;

    //The maximum length of the bar
    int bar_length = 50;

    //Display player health
    print_bar(bar_length, scene->player.health / scene->player.maxHealth,
              row + 4, col + 5);
    move_cursor_to(row + 7, col + 5 + 10);
    printf("Player HP : %.2lf / %.0lf ", scene->player.health, scene->player.maxHealth);

    //Display bullet number
    print_bar(bar_length, scene->player.weapon.bullet_number * 1.0 / scene->player.weapon.magazine_size,
              row + 4, col + 16 + bar_length);
    move_cursor_to(row + 7, col + 16 + 13 + bar_length);
    printf("%s : %d / %d ",scene->player.weapon.namestring, scene->player.weapon.bullet_number,
           scene->player.weapon.magazine_size);

    //Display Enemy health
    struct Line ray;
    Transform_UpdateGlobal(&scene->player.canvas.camera_transform);
    
    struct Vector3 direction;
    Vector3_Copy(&scene->player.facing, &direction);
    //Matrix3x3_TransformEuler(&scene->player.canvas.camera_transform.globalRotation, &direction);
    Line_Set(&ray, &scene->player.canvas.camera_transform.globalPosition, &direction);

    struct Enemy *enemy;
    enum Tag tag;
    Scene_EnemyCollided(scene, &ray, &enemy, &tag);
    if (enemy != NULL){
        print_bar(bar_length, enemy->health / enemy->maxHealth,
                  row + 10, col + 5 + 30);
        move_cursor_to(row + 13, col + 5 + 11 + 30);
        printf("Enemy HP : %.2lf / %.0lf ", enemy->health, enemy->maxHealth);
    }
    else{
        move_cursor_to(row + 10, col + 5 + 30);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < bar_length + 40; j++) printf(" ");
            puts("");
        }
    }

    //Draw the STAR in the center of canvas
    Canvas_AddCover(&scene->player.canvas, scene->player.canvas.height / 2 ,
                    scene->player.canvas.width / 2 , STAR);
#if DEBUG
    printf("%lf %lf %lf\n",scene->player.facing.x,scene->player.facing.y,scene->player.facing.z);
    printf("%lf %lf %lf\n",scene->player.canvas.camera_transform.rotation.x,scene->player.canvas.camera_transform.rotation.y,scene->player.canvas.camera_transform.rotation.z);
    printf("%lf %lf %lf\n",scene->player.canvas.camera_transform.globalPosition.x,scene->player.canvas.camera_transform.globalPosition.y,scene->player.canvas.camera_transform.globalPosition.z);
#endif
    
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
    if (enemy == NULL) { if (tag == FAKE_WALL){
        scene->FAKE_WALL_shootcounter++;
    }
    }
    Enemy_GetDamage(enemy, &tag, &scene->player.weapon);

}

void Clear_Enemy(struct Scene *scene){
    for(int i = 0; i < scene->list_Enemy.size; i++){
        struct Enemy *enemy = ((struct Enemy **)scene->list_Enemy.data)[i];
        if(enemy->DEADFLAG == 1){
            if(ArrayList_DeleteElement(&scene->list_Enemy,scene->list_Enemy.data + i*scene->list_Enemy.element_size))
            Del_Enemy(enemy);}
    }
}
int Scene_Collided_Enemy(struct Scene *scene, struct CollideBox *collidebox){
    for(int i = 0; i < scene->list_Enemy.size ; i++){
            struct Enemy *enemy = ((struct Enemy**)scene->list_Enemy.data)[i];
            if(CollideBox_IsCollide(collidebox,&enemy->head.collideBoxes[0])){ return 1; }
        }
    return 0;
}
int Scene_Collided_Object(struct Scene *scene, struct CollideBox *collidebox){
    for(int i = 0; i < scene->list_Object.size ; i++){
            struct Object *object = ((struct Object**)scene->list_Object.data)[i];
            for(int j = 0; j < object->collideBoxCount ;j++){
                if(CollideBox_IsCollide(collidebox,&object->collideBoxes[j])){
#if DEBUG
                    printf("%d %d OBJECT\n", i, j);
#endif
                    return 1;
                }
            }
        }
    return 0;
}
void Scene_Add_EnemySpawnArea(struct Scene *scene, double x, double z, double len, double wid, int num){
    struct Region2D *region2d = Region2D_New(x, z, len, wid, num);
    ArrayList_PushBack(&scene->list_EnemySpawnArea,&region2d);
}
void Scene_Player_WinningCheck(struct Scene *scene){
    for(int i = 0; i < scene->list_Object.size ; i++){
            struct Object *object = ((struct Object**)scene->list_Object.data)[i];
            for(int j = 0; j < object->collideBoxCount ;j++){
                if(CollideBox_IsCollide(&scene->player.collideBox,&object->collideBoxes[j])){
                    if(object->tag == END){
                        scene->player.WINFLAG=1;
                    }
                    if(object->tag == TRUE_END){
                        scene->player.TRUEWINFLAG=1;
                    }
#if DEBUG
                    printf("%d %d OBJECT\n", i, j);
#endif
                    return;
                }
            }
        }
    return;
}
void Scene_Delete_FakeWall(struct Scene *scene){
    for(int i = 0; i < scene->list_Object.size; i++){
        struct Object *object = ((struct Object **)scene->list_Object.data)[i];
        if(object->tag == FAKE_WALL){
            if(ArrayList_DeleteElement(&scene->list_Object,scene->list_Object.data + i*scene->list_Object.element_size))
            Del_Object(object);
            break;}
    }
}