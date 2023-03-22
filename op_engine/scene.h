#ifndef FPS_SIMULATOR_SCENE_H
#define FPS_SIMULATOR_SCENE_H

#include "../util/array_list.h"
#include "canvas.h"

struct Scene{
    struct Canvas canvas;
    struct ArrayList list_object;
};

void Scene_Init(struct Scene *scene, short canvas_height, short canvas_width);

#endif //FPS_SIMULATOR_SCENE_H
