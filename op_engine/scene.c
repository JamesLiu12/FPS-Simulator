#include "scene.h"
#include "object.h"

void Scene_Init(struct Scene *scene, struct Canvas *canvas){
    scene->canvas = canvas;
    ArrayList_Init(&scene->list_StaticObject, sizeof(struct Object*));
    ArrayList_Init(&scene->list_MovableObject, sizeof(struct Object*));
}