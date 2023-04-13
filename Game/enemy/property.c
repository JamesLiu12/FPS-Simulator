#include "property.h"

void Enemy_Init(struct Enemy *enemy,struct Object* body,struct Object* face, struct Object* leg){
    enemy->body = *body;
    enemy->leg = *leg;
    enemy->face = *face;
    enemy->speed = 5;
	enemy->health = 100;
	enemy->damage = 5;
	enemy->Critical_Rate = 50;//critical damage to player; should not be higher than 50

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

void Enemy_Start(struct Enemy *enemy)
{
	//TODO enemy start
}

void Enemy_Update(struct Enemy* enemy, bool do_find_way, struct Scene* scene, struct link* current)
{
	if (do_find_way){
		struct link* beginning = Find_Way(&enemy->body,scene);//beginning actually refers to current position of bot.
		current = beginning;
	}
	struct Transform* target = current->next->current;
	struct Vector3* move = (struct Vector3*)malloc(sizeof(struct Vector3));
	Vector3_Set(move,
				target->globalPosition.x - enemy->transform.globalPosition.x,
				target->globalPosition.y - enemy->transform.globalPosition.y,
				target->globalPosition.z - enemy->transform.globalPosition.z);
	Enemy_Move(enemy, move);
}