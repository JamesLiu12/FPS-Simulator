#ifndef FPS_SIMULATOR_ENEMY_H
#define FPS_SIMULATOR_ENEMY_H

#include "../op_engine/op_engine.h"
#include "models/models.h"
#include "weapon.h"

struct Enemy{
    //The 3 objects that make an enemy
    struct Object head, leg, body;

    /*
     * speed: move speed
     * damage: the base damage in each attack
     * maxHealth: the initial health point of an Enemy
     * attackDistance: the attack distance range
     * senseDistance: the maximum distance that makes enemy tracking the target
     * attackCDtime: the time gap between each attack
     * attackCounter: the time left fore next attack
     */
    double speed, damage, maxHealth, health, attackDistance, senseDistance, attackCDtime, attackCounter;

    struct Transform transform;

    /*
     * criticalRate: The probability of an attack to be critical damage
     * criticalDamage: The value of critical damage
     */
	double criticalRate, criticalDamage;

    /*
     * canSeeTarget: if Enemy could see target
     */
    int canSeeTarget;

    /*
     * move: the move in this frame
     * destination: the destination in this frame
     */
    struct Vector3 moveDirection, destination;

    /*
     * DEADFLAG: if the enemy is dead
     * inattackCD: if the enemy could not attack
     * ATTACKFALG: if the enemy is attacking
     */
    int DEADFLAG, inattackCD, ATTACKFLAG;
};

//The meshes used to construct an enemy
struct EnemyMeshes{
    struct Mesh *head, *body, *leg;
};

//Initializer of Enemy
void Enemy_Init(struct Enemy *enemy, struct EnemyMeshes *meshes, int difficulty);

//Newer of Enemy
struct Enemy* New_Enemy(struct EnemyMeshes *meshes, int difficulty);

//Deleter of Enemy
void Del_Enemy(struct Enemy *enemy);

//What enemy does each frame
void Enemy_Update(struct Enemy *enemy, double delta_time);

//Let enemy displace a vector
void Enemy_Move(struct Enemy* enemy, struct Vector3 *move);

//Let enemy rotation an euler angle
void Enemy_Rotation(struct Enemy *enemy, struct Vector3* angle);

//Initializer of EnemyMeshes
void EnemyMeshes_Init(struct EnemyMeshes *meshes, struct Mesh *head, struct Mesh *body, struct Mesh *leg);

//Newer of EnemyMeshes
struct EnemyMeshes* New_EnemyMeshes(struct Mesh *head, struct Mesh *body, struct Mesh *leg);

//Deleter of EnemyMeshes
void Del_EnemyMeshes(struct EnemyMeshes *meshes);

//enemy's damage to player
int Enemy_IsTargetInAttackRange(struct Enemy *enemy, struct Vector3 *targetPosition);

//Change HP of enemy
void Enemy_ChangeHealth(struct Enemy *enemy, double delta_health);

//Imply the damage got
void Enemy_GetDamage(struct Enemy *enemy, enum Tag *tag, struct Weapon *weapon);

//Update attack information
void Enemy_Attack(struct Enemy *enemy);
#endif //FPS_SIMULATOR_ENEMY_H
