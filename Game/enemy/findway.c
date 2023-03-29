#include "findway.h"
#define typename struct Object

double baseCost(struct Enemy *enemy,struct Vector3 point)
{
    Transform_UpdateGlobal(&enemy->transform);
    struct Vector3 start = enemy->transform.globalPosition;
    double speed = enemy->speed;
    double dx=point.x-start.x;
    double dz=point.z-start.z;
    if(dx<0){dx=-dx;}
    if(dz<0){dz=-dz;}
    return speed * (dx+dz);
}

double HCost(struct Player *player,struct Vector3 point, double speed)
{
    double dx=player->transform.globalPosition.x-point.x;
    double dz=player->transform.globalPosition.z-point.z;
    if(dx<0){dx=-dx;}
    if(dz<0){dz=-dz;}
    return speed * (dx+dz);
}

double totalCost(struct Enemy *enemy,struct Scene *scene,struct Vector3 point)
{
    return baseCost(enemy,point)+HCost(&scene->player,point,enemy->speed);
}

bool pointIsValid(struct Scene *scene,struct Object* point)//struct Object* point = &((typename *)scene->list_Object.data)[identifier];
{
    if (point->tag == WALL){return 0;}
    return 1;
}

bool isDestination(struct Scene *scene,struct Vector3* point)
{
	if (point->x == scene->player.transform.globalPosition.x
		&& point->z == scene->player.transform.globalPosition.z)
	{return 1;}
	return 0;
}

void Find_Way(struct Object *enemy, struct Scene* scene)
{
	if (isDestination(scene,&enemy->transform.globalPosition)){return;}
	struct ArrayList* objects = &(scene->list_Object);
	struct ArrayList* enemies = &(scene->list_Enemy);
	unsigned int map_size = objects->size + enemies->size;


}
