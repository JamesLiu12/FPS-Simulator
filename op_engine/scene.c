#include "scene.h"
#include "object.h"

void Scene_Init(struct Scene *scene){
    ArrayList_Init(&scene->list_object, sizeof(struct Object));
}