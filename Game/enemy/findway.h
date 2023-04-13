#ifndef FPS_SIMULATOR_FINDWAY_H
#define FPS_SIMULATOR_FINDWAY_H
#include "../../op_engine/op_engine.h"
#include "behaviour.h"
#include "../scene.h"
#include "../../op_engine/collide_box.h"

struct link{
	struct Transform* current;
	struct link* next;
};
struct link* Find_Way(struct Object *enemy, struct Scene* scene);
#endif //FPS_SIMULATOR_FINDWAY_H
