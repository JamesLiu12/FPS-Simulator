#include "property.h"
#include "math.h"

double square(double x);

void Enemy_Init(struct Enemy *enemy,struct Object* body,struct Object* face, struct Object* leg){
    enemy->body = *body;
    enemy->leg = *leg;
    enemy->face = *face;
    enemy->speed = 5;
	enemy->health = 100;
	enemy->damage = 5;
	enemy->Critical_Rate = 50;//critical damage to player; should not be higher than 50

	Transform_Init(&enemy->transform, NULL);
    Transform_Init(&enemy->face.transform, &enemy->transform);
    Transform_Init(&enemy->body.transform, &enemy->transform);
    Transform_Init(&enemy->leg.transform, &enemy->transform);

	struct Vector3 v1, v2;
	Vector3_Set(&v1, 1, -1, 1);
	Vector3_Set(&v2, 2, 1, 2);
	CollideBox_Set(&enemy->collideBox, &v1, &v2);
}

void Enemy_Start(struct Enemy *enemy)
{
	//TODO enemy start
}

bool Damage_Determination(struct Scene *scene,struct Enemy *enemy)//enemy's damage to player
{
    double damage = 0;
    double distance = 1.5;//max distance for enemy to attack the player
    if (sqrt(square(enemy->transform.globalPosition.x - scene->player.transform.globalPosition.x) +
             square(enemy->transform.globalPosition.z - scene->player.transform.globalPosition.z)
             >= distance)) return 0;
    return 1;
}

double Damage_Calculation(struct Scene *scene,struct Enemy *enemy)//enemy's damage to player
{
    double roller = rand() % 100;
    double rate = roller * enemy->Critical_Rate;//this value should be 0-5000
    if (roller >= 2345/*critical damage*/){ return square(enemy->damage/scene->player.defence); }
    else { return enemy->damage/scene->player.defence; }
}

void Enemy_Move(struct Enemy* enemy, struct Vector3* move){
    Transform_AddPosition(&enemy->transform, move);
}

void Enemy_Rotation(struct Enemy* enemy, struct Vector3 *angle){
    Object_Rotation(&enemy->face,angle);
    Object_Rotation(&enemy->body,angle);
    Vector3_Add(&enemy->transform.rotation, angle);
    Transform_RotationMatrixUpdate(&enemy->transform);
}

double square(double x)
{
    return x*x;
}
