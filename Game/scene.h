#ifndef FPS_SIMULATOR_SCENE_H
#define FPS_SIMULATOR_SCENE_H

#include "../util/array_list.h"
#include "../op_engine/canvas.h"
#include "../Game/models/models.h"
#include "player.h"
#include "enemy.h"

struct Scene{
    struct ArrayList list_Object;
    struct ArrayList list_Enemy;
    struct Player player;

    //The meshes used to create an enemy
    struct EnemyMeshes enemyMeshes;
};

//The initializer of scene
void Scene_Init(struct Scene *scene);

//The deleter of scene
void Del_Scene(struct Scene *scene);

void Scene_Update(struct Scene *scene, double delta_time);

//Showing all the object within scene in the view of canvas
void Scene_Show(struct Scene *scene, struct Canvas *canvas);

//get which enemy and parts are collided by the ray
void Scene_EnemyCollided(struct Scene *scene, struct Line *ray, struct Enemy **result_enemy, enum Tag *result_tag);

struct Path* Scene_EnemyFindPath(struct Scene* scene, struct Object *enemy);

void Scene_EnemyUpdate(struct Enemy *enemy, bool do_find_way, struct Scene* scene, struct Path* current);

bool Scene_IsPlayerInAttackRange(struct Scene *scene, struct Enemy *enemy);

double Scene_DamageCalculation(struct Scene *scene, struct Enemy *enemy);

double Scene_MinDistanceWall(struct Scene *scene, struct Line *ray);

void Scene_PlayerShoot(struct Scene *scene);

#endif //FPS_SIMULATOR_SCENE_H
