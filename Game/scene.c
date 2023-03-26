#include "scene.h"
#include "../op_engine/object.h"

void Scene_Init(struct Scene *scene){
    ArrayList_Init(&scene->list_Object, sizeof(struct Object*));
    ArrayList_Init(&scene->list_Enemy, sizeof(struct Enemy*));
    Player_Init(&scene->player);
}

void Del_Scene(struct Scene *scene){
    Del_ArrayList(&scene->list_Object);
    Del_ArrayList(&scene->list_Enemy);
    Del_Player(&scene->player);
}