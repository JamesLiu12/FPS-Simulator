#include "playground.h"
#include "op_engine/op_engine.h"
#include "obj_converter/out/testing1.c"
#include "test_map/map.h"

void test()
{
	struct Mesh* map = ModelTesting1_New();
	struct Player plr; Player_Init(&plr); struct Player* player = &plr;
	struct Transform transform;
	struct CollideBox* box;
	struct Scene* scene = (struct Scene*) malloc(sizeof(struct Scene));
	Scene_Init(scene);



}
