#ifndef FPS_SIMULATOR_SCENE_H
#define FPS_SIMULATOR_SCENE_H

#include "../util/array_list.h"
#include "../op_engine/canvas.h"
#include "../Game/models/models.h"
#include "player.h"
#include "enemy.h"
struct Scene{

    //list for storing objects in Scene
    struct ArrayList list_Object;

    //list for storing enemies in Scene
    struct ArrayList list_Enemy;

    //The controllable player in Scene
    struct Player player;

    //The meshes used to create an enemy
    struct EnemyMeshes enemyMeshes;

    //list for storing the region for spawning enemy
    struct ArrayList list_EnemySpawnArea;

    //the number of times that the fake wall has been shot
    int FAKE_WALL_shootcounter;
};

//The initializer of scene
void Scene_Init(struct Scene *scene, enum WeaponName weaponname, int difficulty);

//The deleter of scene
void Del_Scene(struct Scene *scene);

void Scene_Update(struct Scene *scene, double delta_time);

//Showing all the object within scene in the view of canvas
void Scene_Show(struct Scene *scene, struct Canvas *canvas);

//get which enemy and parts are collided by the ray
void Scene_EnemyCollided(struct Scene *scene, struct Line *ray, struct Enemy **result_enemy, enum Tag *result_tag);

//Return the distance of the closet wall from ray
double Scene_MinDistanceWall(struct Scene *scene, struct Line *ray);

//Find whether an enemy is shot and deal damage to it
void Scene_PlayerShoot(struct Scene *scene);

//Clear dead enemies each frame
void Clear_Enemy(struct Scene *scene);

//Return if the collideBox has collided enemy
int Scene_Collided_Enemy(struct Scene *scene, struct CollideBox *collideBox);

//Return if the collideBox has collided object
int Scene_Collided_Object(struct Scene *scene, struct CollideBox *collideBox);

//Add a square region for spawn enemy
void Scene_Add_EnemySpawnSquare(struct Scene *scene, double x, double z, double len, double wid, int num);

//Dlete the fake wall in scene
void Scene_Delete_FakeWall(struct Scene *scene);
#endif //FPS_SIMULATOR_SCENE_H
