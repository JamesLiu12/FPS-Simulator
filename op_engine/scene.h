#ifndef FPS_SIMULATOR_SCENE_H
#define FPS_SIMULATOR_SCENE_H

#include "../util/array_list.h"

struct Scene{
    struct ArrayList list_object;
};

void Scene_Init(struct Scene *scene);

#endif //FPS_SIMULATOR_SCENE_H
