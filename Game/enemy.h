#ifndef FPS_SIMULATOR_ENEMY_H
#define FPS_SIMULATOR_ENEMY_H

#include "../op_engine/op_engine.h"
#include "models/models.h"

struct Enemy{
    struct Object head, body, leg;
    double health, atk, speed;
    struct Transform transform;
};

struct EnemyMeshes{
    struct Mesh *head, *body, *leg;
};

void Enemy_Init(struct Enemy *enemy, struct EnemyMeshes *meshes);
struct Enemy* New_Enemy(struct EnemyMeshes *meshes);
void Del_Enemy(struct Enemy *enemy);

void EnemyMeshes_Init(struct EnemyMeshes *meshes, struct Mesh *head, struct Mesh *body, struct Mesh *leg);
struct EnemyMeshes* New_EnemyMeshes(struct Mesh *head, struct Mesh *body, struct Mesh *leg);
void Del_EnemyMeshes(struct EnemyMeshes *meshes);


#endif //FPS_SIMULATOR_ENEMY_H
