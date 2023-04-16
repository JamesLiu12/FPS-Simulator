#ifndef FPS_SIMULATOR_ENEMY_H
#define FPS_SIMULATOR_ENEMY_H

#include "../../op_engine/op_engine.h"
#include "../player.h"
#include "../scene.h"


struct Enemy{
    struct Object face,leg,body;
    double speed,damage,health;
    struct Transform transform;
	struct CollideBox collideBox;
	double Critical_Rate;
};

void Enemy_Init(struct Enemy *enemy,struct Object* body,struct Object* face, struct Object* leg);

void Enemy_Start(struct Enemy *enemy);

bool Damage_Determination(struct Scene *scene,struct Enemy *enemy);

double Damage_Calculation(struct Scene *scene,struct Enemy *enemy);

void Enemy_Move(struct Enemy* enemy, struct Vector3 *move); //enemy consists of three objects: face and body

void Enemy_Rotation(struct Enemy *enemy, struct Vector3* angle);
#endif //FPS_SIMULATOR_ENEMY_H
