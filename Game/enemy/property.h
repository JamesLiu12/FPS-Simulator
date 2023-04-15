#ifndef FPS_SIMULATOR_PROPERTY_H
#define FPS_SIMULATOR_PROPERTY_H

#include "../../op_engine/op_engine.h"
#include "../player.h"


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



#endif //FPS_SIMULATOR_PROPERTY_H
