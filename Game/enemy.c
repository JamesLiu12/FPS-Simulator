#include "enemy.h"
#include "math.h"
#include "../util/util.h"

void Enemy_Init(struct Enemy *enemy, struct EnemyMeshes *meshes){
    Transform_Init(&enemy->transform, NULL);

    //Enemy_Head
    Object_Init(&enemy->head, meshes->head, &enemy->transform, ENEMY_HEAD);
    Vector3_Set(&enemy->head.transform.position, 0, 0, 0);

    struct CollideBox *collideBoxes_EnemyHead = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    CollideBox_Init(collideBoxes_EnemyHead, &enemy->transform, 0.7, 0.7, 0.7);
    Vector3_Set(&collideBoxes_EnemyHead->transform.position, 0, 1.75, 0);

    Object_SetCollideBoxes(&enemy->head, collideBoxes_EnemyHead, 1);


    //Enemy_Body
    Object_Init(&enemy->body, meshes->body, &enemy->transform, ENEMY_BODY);
    Vector3_Set(&enemy->body.transform.position, 0, 0, 0);

    struct CollideBox *collideBoxes_EnemyBody = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    CollideBox_Init(collideBoxes_EnemyBody, &enemy->transform, 0.3, 1, 0.3);
    Vector3_Set(&collideBoxes_EnemyBody->transform.position, 0, 0.9, 0);

    Object_SetCollideBoxes(&enemy->body, collideBoxes_EnemyBody, 1);

    //Enemy_Leg
    Object_Init(&enemy->leg, meshes->leg, &enemy->transform, ENEMY_LEG);
    Vector3_Set(&enemy->leg.transform.position, 0, 0, 0);

    struct CollideBox *collideBoxes_EnemyLeg = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    CollideBox_Init(collideBoxes_EnemyLeg, &enemy->leg.transform, 0.74, 0.4, 0.74);
    Vector3_Set(&collideBoxes_EnemyLeg->transform.position, 0, 0.2, 0);

    Object_SetCollideBoxes(&enemy->leg, collideBoxes_EnemyLeg, 1);

    enemy->speed = 1;
	enemy->health = 100;
	enemy->damage = 5;
	enemy->Critical_Rate = 50;//critical damage to player; should not be higher than 50
    enemy->findPathCD = 1;
    enemy->attackDistance = 1.5;
    enemy->canSeePlayer = FALSE;
    Vector3_Set(&enemy->moveDirection, 0, 0, 0);
}

void Enemy_Start(struct Enemy *enemy){
	//TODO enemy start
}

void Enemy_Update(struct Enemy *enemy, double delta_time){
    if (enemy->canSeePlayer){
        struct Vector3 move = enemy->moveDirection,
                posDiff = enemy->destination;
        Vector3_Scale(&move, enemy->speed * delta_time);
        Vector3_Subtract(&posDiff, &enemy->transform.position);
        posDiff.y = 0;
        if (Vector3_Magnitude(&move) > Vector3_Magnitude(&posDiff))
            Transform_AddPosition(&enemy->transform, &posDiff);
        else
            Transform_AddPosition(&enemy->transform, &move);
    }
}

struct Enemy* New_Enemy(struct EnemyMeshes *meshes){
    struct Enemy *enemy = (struct Enemy*)malloc(sizeof(struct Enemy));
    Enemy_Init(enemy, meshes);
    return enemy;
}

void Del_Enemy(struct Enemy *enemy){
    Del_Transform(&enemy->transform);
    Del_Object(&enemy->head);
    Del_Object(&enemy->body);
    Del_Object(&enemy->leg);
}

void EnemyMeshes_Init(struct EnemyMeshes *meshes, struct Mesh *head, struct Mesh *body, struct Mesh *leg){
    meshes->head = head;
    meshes->body = body;
    meshes->leg = leg;
}

struct EnemyMeshes* New_EnemyMeshes(struct Mesh *head, struct Mesh *body, struct Mesh *leg){
    struct EnemyMeshes *meshes = (struct EnemyMeshes*)malloc(sizeof(struct EnemyMeshes));
    EnemyMeshes_Init(meshes, head, body, leg);
    return meshes;
}

void Del_EnemyMeshes(struct EnemyMeshes *meshes){
    Del_Mesh(meshes->head);
    Del_Mesh(meshes->body);
    Del_Mesh(meshes->leg);
}

void Enemy_Move(struct Enemy* enemy, struct Vector3* move){
    Transform_AddPosition(&enemy->transform, move);
}

void Enemy_Rotation(struct Enemy* enemy, struct Vector3 *angle){
    Object_Rotation(&enemy->head, angle);
    Object_Rotation(&enemy->body,angle);
    Vector3_Add(&enemy->transform.rotation, angle);
    Transform_RotationMatrixUpdate(&enemy->transform);
}
int Enemy_IsTargetInAttackRange(struct Enemy *enemy, struct Vector3 *targetPosition){
    return (sqrt(pow(enemy->transform.globalPosition.x - targetPosition->x,2) +
             pow(enemy->transform.globalPosition.z - targetPosition->z,2))
             < enemy->attackDistance);
}