#ifndef FPS_SIMULATOR_SCENE_H
#define FPS_SIMULATOR_SCENE_H

#include "../util/array_list.h"
#include "canvas.h"

struct Scene{
    struct Canvas *canvas;
    struct ArrayList list_StaticObject, list_MovableObject;
};

void Scene_Init(struct Scene *scene, struct Canvas *canvas);

#endif //FPS_SIMULATOR_SCENE_H
