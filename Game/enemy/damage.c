#include "damage.h"
#include "math.h"
#include "property.h"
double square(double x)
{
	return x*x;
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