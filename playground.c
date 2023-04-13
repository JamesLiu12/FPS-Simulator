#include "playground.h"
#include "op_engine/op_engine.h"
#include "obj_converter/out/testing1.c"
#include "test_map/map.h"
#include <windows.h>
#include <stdio.h>

void test()
{
	struct Mesh* map = ModelTesting1_New();
	struct Player plr; Player_Init(&plr); struct Player* player = &plr;
	struct Transform transform;
	struct CollideBox* box;
	struct Scene* scene = (struct Scene*) malloc(sizeof(struct Scene));
	Scene_Init(scene);

	struct Enemy* enemy = (struct Enemy*)malloc(sizeof(struct Enemy));
	struct Object* body = (struct Object*)malloc(sizeof (struct Object));
	struct Object* leg = (struct Object*)malloc(sizeof (struct Object));
	struct Object* face = (struct Object*)malloc(sizeof (struct Object));
	Enemy_Init(enemy,body,face,leg);

	int count = 1;
	bool dof = 0;
	struct link* beginning = Find_Way(&enemy->body,scene);
	while (count < 100){
		if (count%10==0){dof = 1;}
		Enemy_Update(enemy,dof,scene,beginning);
		printf("%f",enemy->transform.globalPosition.x);
		count++;
		Sleep(500);
	}





}
