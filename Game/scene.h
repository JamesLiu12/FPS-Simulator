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
    struct ArrayList list_EnemySpawnRegion;
};

struct EnemySpawnRegion {
    // an enemy spawn region is a rectangle and can be defined by two vertecies.

    // vertex1 is the point closest to the origin
    struct Vector3* vertex1;
    // vertex2 is the point farthest to the origin
    struct Vector3* vertex2;
    int EnemyNum;
};


//The initializer of scene
void Scene_Init(struct Scene *scene, enum WeaponName weaponname);

//The deleter of scene
void Del_Scene(struct Scene *scene);

void Scene_Update(struct Scene *scene, double delta_time);

//Showing all the object within scene in the view of canvas
void Scene_Show(struct Scene *scene, struct Canvas *canvas);

//get which enemy and parts are collided by the ray
void Scene_EnemyCollided(struct Scene *scene, struct Line *ray, struct Enemy **result_enemy, enum Tag *result_tag);

double Scene_DamageCalculation(struct Scene *scene, struct Enemy *enemy);

double Scene_MinDistanceWall(struct Scene *scene, struct Line *ray);
//Find whether an enemy is shooted and deal damage to it
void Scene_PlayerShoot(struct Scene *scene);
//Clear dead enemies each frame
void Clear_Enemy(struct Scene *scene);
int Scene_Collided_Enemy(struct Scene *scene, struct CollideBox *collidebox);
int Scene_Collided_Object(struct Scene *scene, struct CollideBox *collidebox);
// void Scene_Add_EnemySpawnRegion(struct Scene *scene,double x, double y,double z);
void Scene_Add_EnemySpawnRegion(struct Scene *scene, struct EnemySpawnRegion *region);
struct EnemySpawnRegion* EnemySpawnRegion_Init(double x1, double y1, double z1, double x2, double y2, double z2, int enemy_num);
void Del_EnemySpawnRegion(struct EnemySpawnRegion* region);
#endif //FPS_SIMULATOR_SCENE_H
