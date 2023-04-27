#include "enemy.h"
#include "math.h"
#include "../util/util.h"
void Enemy_Init(struct Enemy *enemy, struct EnemyMeshes *meshes){
    Transform_Init(&enemy->transform, NULL);

    //Enemy_Head
    Object_Init(&enemy->head, meshes->head, &enemy->transform, ENEMY_HEAD);
    Vector3_Set(&enemy->head.transform.position, 0, 0, 0);

    struct CollideBox *collideBoxes_EnemyHead = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    CollideBox_Init(collideBoxes_EnemyHead, &enemy->transform, 0.6, 0.6, 0.6);
    Vector3_Set(&collideBoxes_EnemyHead->transform.position, 0, 1.75, 0);

    Object_SetCollideBoxes(&enemy->head, collideBoxes_EnemyHead, 1);


    //Enemy_Body
    Object_Init(&enemy->body, meshes->body, &enemy->transform, ENEMY_BODY);
    Vector3_Set(&enemy->body.transform.position, 0, 0, 0);

    struct CollideBox *collideBoxes_EnemyBody = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    CollideBox_Init(collideBoxes_EnemyBody, &enemy->transform, 0.7, 1, 0.7);
    Vector3_Set(&collideBoxes_EnemyBody->transform.position, 0, 0.9, 0);

    Object_SetCollideBoxes(&enemy->body, collideBoxes_EnemyBody, 1);

    //Enemy_Leg
    Object_Init(&enemy->leg, meshes->leg, &enemy->transform, ENEMY_LEG);
    Vector3_Set(&enemy->leg.transform.position, 0, 0, 0);

    struct CollideBox *collideBoxes_EnemyLeg = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    CollideBox_Init(collideBoxes_EnemyLeg, &enemy->leg.transform, 0.74, 0.4, 0.74);
    Vector3_Set(&collideBoxes_EnemyLeg->transform.position, 0, 0.2, 0);

    Object_SetCollideBoxes(&enemy->leg, collideBoxes_EnemyLeg, 1);

    enemy->speed = 1.3;
    enemy->maxHealth = 100;
	enemy->health = enemy->maxHealth;
	enemy->damage = 3;
    enemy->attackCDtime=1;
    enemy->attackcounter=0;
    enemy->inattackCD=0;
	enemy->Critical_Rate = 15;//the possibility of a critical hit, %
    enemy->Critical_Damage = 0.5;// the critical damage is 150%
    enemy->findPathCD = 1;
    enemy->attackDistance = 1.5;
    enemy->senseDistance = 20;
    enemy->canSeeTarget = FALSE;
    enemy->DEADFLAG=0;
    Vector3_Set(&enemy->moveDirection, 0, 0, 0);
}

void Enemy_Start(struct Enemy *enemy){
	//TODO enemy start
}

void Enemy_Update(struct Enemy *enemy, double delta_time){
    if (enemy->canSeeTarget){
        struct Vector3 move = enemy->moveDirection,
                posDiff = enemy->destination;
        Vector3_Scale(&move, enemy->speed * delta_time);
        Vector3_Subtract(&posDiff, &enemy->transform.position);
        posDiff.y = 0;
        if (Vector3_Magnitude(&move) > Vector3_Magnitude(&posDiff)){
            Vector3_Set(&enemy->moveDirection, posDiff.x, 0, posDiff.z);
            //Vector3_Normalize(&enemy->moveDirection);
            }
        else{
            Vector3_Set(&enemy->moveDirection, move.x, 0, move.z);
            //Vector3_Normalize(&enemy->moveDirection);
            }
    }
    else {
        Vector3_Scale(&enemy->moveDirection,0);
    }
    if (enemy->inattackCD){
        enemy->ATTACKFLAG=0;
        enemy->attackcounter-=delta_time;
        if(enemy->attackcounter<=0)enemy->inattackCD=0;
    }
}
void Enemy_Attack(struct Enemy *enemy){
    if(!enemy->inattackCD && enemy->canSeeTarget){
        enemy->ATTACKFLAG=1;
        enemy->inattackCD=1;
        enemy->attackcounter=enemy->attackCDtime;
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

void Enemy_ChangeHealth(struct Enemy *enemy, double delta_health){
    enemy->health += delta_health;
    if(enemy->health > enemy->maxHealth) enemy->health = enemy->maxHealth;
    if(enemy->health <= 0) enemy->DEADFLAG=1;
}
void Enemy_GetDamage(struct Enemy *enemy, enum Tag *tag, struct Weapon *weapon){
    if(*tag == ENEMY_HEAD){
        Enemy_ChangeHealth(enemy, -weapon->damage*weapon->head_rate);
    }
    if(*tag == ENEMY_BODY){
        Enemy_ChangeHealth(enemy, -weapon->damage*weapon->body_rate);
    }
    if(*tag == ENEMY_LEG){
        Enemy_ChangeHealth(enemy, -weapon->damage*weapon->leg_rate);
    }
}
int Enemy_IsTargetInAttackRange(struct Enemy *enemy, struct Vector3 *targetPosition){
    if(Vector3_Distance3D(&enemy->transform.globalPosition,targetPosition)<enemy->attackDistance)return 1;
    return 0;
}