#ifndef FPS_SIMULATOR_SCENE_H
#define FPS_SIMULATOR_SCENE_H

#include "../util/array_list.h"
#include "../op_engine/canvas.h"
#include "player.h"
#include "./enemy/property.h"

struct Scene{
    struct ArrayList list_Object;
    struct ArrayList list_Enemy;
    struct Player player;
};

void Scene_Init(struct Scene *scene);

void Del_Scene(struct Scene *scene);

#endif //FPS_SIMULATOR_SCENE_H
