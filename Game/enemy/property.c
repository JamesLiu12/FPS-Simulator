#include "property.h"

void Enemy_Init(struct Enemy *enemy,struct Object* body,struct Object* face, struct Object* leg){
    enemy->body = *body;
    enemy->leg = *leg;
    enemy->face = *face;
    enemy->speed = 5;
	enemy->health = 100;
	enemy->damage = 5;

	Transform_Init(&enemy->transform, NULL);

	struct Vector3 v1, v2;
	Vector3_Set(&v1, 1, -1, 1);
	Vector3_Set(&v2, 2, 1, 2);
	CollideBox_Set(&enemy->collideBox, &v1, &v2);
}

void Del_Enemy(struct Enemy *enemy)
{
	free(enemy);
}

void Enemy_Move(struct Enemy *enemy, struct Vector3* move){
	Vector3_Add(&enemy->transform.position, move);
}
