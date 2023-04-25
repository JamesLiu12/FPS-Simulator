#ifndef FPS_SIMULATOR_ENEMY_H
#define FPS_SIMULATOR_ENEMY_H

#include "../op_engine/op_engine.h"
#include "models/models.h"
#include "weapon.h"
struct Path{
    struct Transform* current;
    struct Path* next;
};

struct Enemy{
    struct Object head, leg, body;
    double speed, damage, maxhealth, health, findPathCD, attackDistance;
    double attackCDtime,attackcounter;
    struct Transform transform;
	//struct CollideBox collideBox;
	double Critical_Rate,Critical_Damage;
    int canSeePlayer;
    struct Vector3 moveDirection, destination;
    int DEADFLAG,inattackCD,ATTACKFLAG;
};

struct EnemyMeshes{
    struct Mesh *head, *body, *leg;
};

void Enemy_Init(struct Enemy *enemy, struct EnemyMeshes *meshes);
struct Enemy* New_Enemy(struct EnemyMeshes *meshes);
void Del_Enemy(struct Enemy *enemy);
void Enemy_Start(struct Enemy *enemy);
void Enemy_Update(struct Enemy *enemy, double delta_time);

void Enemy_Move(struct Enemy* enemy, struct Vector3 *move); //enemy consists of three objects: head and body
void Enemy_Rotation(struct Enemy *enemy, struct Vector3* angle);

void EnemyMeshes_Init(struct EnemyMeshes *meshes, struct Mesh *head, struct Mesh *body, struct Mesh *leg);
struct EnemyMeshes* New_EnemyMeshes(struct Mesh *head, struct Mesh *body, struct Mesh *leg);
void Del_EnemyMeshes(struct EnemyMeshes *meshes);

//enemy's damage to player
int Enemy_IsTargetInAttackRange(struct Enemy *enemy, struct Vector3 *targetPosition);

void Enemy_ChangeHealth(struct Enemy *enemy, double delta_health);
void Enemy_GetDamage(struct Enemy *enemy, enum Tag *tag, struct Weapon *weapon);
void Enemy_Attack(struct Enemy *enemy);
#endif //FPS_SIMULATOR_ENEMY_H
