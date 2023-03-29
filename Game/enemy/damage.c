#include "damage.h"

bool is_inside(struct Vector3 *a,struct Vector3 *bmin,struct Vector3 *bmax)
{
	bool status1 = a->x>=bmin->x && a->y>=bmin->y && a->z>=bmin->z;
	bool status2 = a->x<=bmax->x && a->y<=bmax->y && a->z<=bmax->z;
	return status1 && status2;
}

bool Damage_Determination(struct Player *player,struct Enemy *enemy)
{
	struct Vector3 *player_min = &player->collideBox.minVertex;
	struct Vector3 *player_max = &player->collideBox.maxVertex;
	struct Vector3 *enemy_min  = &enemy->collideBox.minVertex;
	struct Vector3 *enemy_max  = &enemy->collideBox.maxVertex;
	return is_inside(enemy_min,player_min,player_max) /*v87*/ |
		   is_inside(enemy_max,player_min,player_max);

}

double Damage_Calculation(struct Scene *scene,struct Enemy *enemy)
{
	if(! Damage_Determination(&scene->player,enemy)){return 0;}
	double damage = enemy->damage * (rand() % 15 ) / scene->player.defence;
	return damage;
}
