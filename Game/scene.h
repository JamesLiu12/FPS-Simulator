#ifndef FPS_SIMULATOR_SCENE_H
#define FPS_SIMULATOR_SCENE_H

#include "../util/array_list.h"
#include "../op_engine/canvas.h"
#include "player.h"
#include "enemy/enemy.h"

struct Enemy_TransformLink{
    struct Transform* current;
    struct Enemy_TransformLink* next;
};

struct Scene{
    struct ArrayList list_Object;
    struct ArrayList list_Enemy;
    struct Player player;
};

//The initializer of scene
void Scene_Init(struct Scene *scene);

//The deleter of scene
void Del_Scene(struct Scene *scene);

//Showing all the object within scene in the view of canvas
void Scene_Show(struct Scene *scene, struct Canvas *canvas);

//get which enemy and parts are collided by the ray
void Scene_EnemyCollided(struct Scene *scene, struct Line *ray, struct Enemy **result_enemy, enum Tag *result_tag);

struct Enemy_TransformLink* Enemy_FindWay(struct Object *enemy, struct Scene* scene);

void Scene_EnemyUpdate(struct Enemy *enemy, bool do_find_way, struct Scene* scene, struct Enemy_TransformLink* current);
#endif //FPS_SIMULATOR_SCENE_H
