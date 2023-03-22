#include "scene.h"
#include "object.h"

void Scene_Init(struct Scene *scene, short canvas_height, short canvas_width){
    ArrayList_Init(&scene->list_object, sizeof(struct Object));
    Canvas_Init(&scene->canvas, canvas_height, canvas_width);
}