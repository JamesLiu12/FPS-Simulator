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
// initializes an enemy including its collidebox and coordinates
// input: an enemy struct pointer, an enemymeshes pointer, an int indicating the difficulty
// output: none
void Enemy_Init(struct Enemy *enemy, struct EnemyMeshes *meshes, int difficulty);

//Newer of Enemy
// input: a mesh pointer and an int indicating the difficulty
// output: an enemy pointer
struct Enemy* New_Enemy(struct EnemyMeshes *meshes, int difficulty);

//Deleter of Enemy
// frees the memory address stored in an enemy struct and the enemy struct itself
// input: an enemy pointer
// output: void
void Del_Enemy(struct Enemy *enemy);

//What enemy does each frame
// updates the enemy for a given time
// input: an enemy pointer and a double indicating time
// output: void
void Enemy_Update(struct Enemy *enemy, double delta_time);

//Let enemy displace a vector
// input: an enemy pointer and a 3d vector pointer indicating the movement of an enemy
// output: void
void Enemy_Move(struct Enemy* enemy, struct Vector3 *move);

//Let enemy rotation an euler angle
// input: an enemy pointer and a 3d vector pointer indicating the rotation of an enemy
// output: void
void Enemy_Rotation(struct Enemy *enemy, struct Vector3* angle);

//Initializer of EnemyMeshes
// initializes meshes within an enemy
// input: an enemymesh pointer and meshes for the head, body and leg of an enemy
// output: void
void EnemyMeshes_Init(struct EnemyMeshes *meshes, struct Mesh *head, struct Mesh *body, struct Mesh *leg);

//Newer of EnemyMeshes
// creates meshes within an enemy
// input: meshes for the head, body and leg of an enemy
// output: an enemymesh pointer
struct EnemyMeshes* New_EnemyMeshes(struct Mesh *head, struct Mesh *body, struct Mesh *leg);

//Deleter of EnemyMeshes
// frees the memory allocated to enemymeshes
// input: an enemymeshes pointer
// output: void
void Del_EnemyMeshes(struct EnemyMeshes *meshes);

//enemy's damage to player
// judges if the target position is less than the attack distance of the enemy
// input: an enemy pointer, a 3d vector pointer indicating the coordinates of the target position
// output: a boolean represented by an integer
int Enemy_IsTargetInAttackRange(struct Enemy *enemy, struct Vector3 *targetPosition);

//Change HP of enemy
// the behavior when an enemy's health changes, including add hp, judging max hp and enemy death
// input: an enemy pointer, a double representing health point change
// output: void
void Enemy_ChangeHealth(struct Enemy *enemy, double delta_health);

//Imply the damage got
// gets the damage done to the enemy when a weapon hits
// input: an enemy pointer, an enum Tag pointer, a struct weapon pointer
// output: void
void Enemy_GetDamage(struct Enemy *enemy, enum Tag *tag, struct Weapon *weapon);

//Update attack information
void Enemy_Attack(struct Enemy *enemy);
#endif //FPS_SIMULATOR_ENEMY_H
