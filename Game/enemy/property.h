#ifndef FPS_SIMULATOR_PROPERTY_H
#define FPS_SIMULATOR_PROPERTY_H

#include "../../op_engine/op_engine.h"
#include "../player.h"
#include "../scene.h"
#include "behaviour.h"
#include "damage.h"
#include "findway.h"

struct Enemy{
    struct Object face,leg,body;
    double speed,damage,health;
    struct Transform transform;
	struct CollideBox collideBox;
	double Critical_Rate;
};

void Enemy_Init(struct Enemy *enemy,struct Object* body,struct Object* face, struct Object* leg);

void Del_Enemy(struct Enemy *enemy);

void Enemy_Start(struct Enemy *enemy);

void Enemy_Update(struct Enemy *enemy, bool do_find_way, struct Scene* scene, struct link* current);

#endif //FPS_SIMULATOR_PROPERTY_H
