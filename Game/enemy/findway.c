#include "findway.h"
#include <math.h>

#define typename struct Object

//build a linked list to find the shortest way from enemy to player.
void Find_Way(struct Object *enemy, struct Scene* scene)
{
	unsigned int size = scene->list_Object.size;
	double min_distance = INFINITY, distance;
	typename* list = (typename*)scene->list_Object.data;
	struct Line* ray = NULL;
	struct Player* player = &scene->player;
	struct Object* min_distance_obj = NULL,*min_temp = NULL;
	min_distance_obj->transform.globalPosition.x = player->transform.globalPosition.x;
	min_distance_obj->transform.globalPosition.y = player->transform.globalPosition.y;
	min_distance_obj->transform.globalPosition.z = player->transform.globalPosition.z;
	struct link* destination = NULL;
	destination->next = NULL;
	destination->current = &min_distance_obj->transform;
	struct link* next_addr = destination;

	while(!	(min_distance_obj->transform.globalPosition.x == enemy->transform.globalPosition.x &&
		     min_distance_obj->transform.globalPosition.z == enemy->transform.globalPosition.z)){
		for (int j=0;j<size;j++){
			if (min_distance_obj->transform.globalPosition.x==list[j].transform.globalPosition.x
			&&  min_distance_obj->transform.globalPosition.z==list[j].transform.globalPosition.z) continue;
			if (list[j].tag == WALL) continue;
			struct Vector3* direction = NULL;
			Vector3_Set(direction,
						min_distance_obj->transform.globalPosition.x-list[j].transform.globalPosition.x,
						min_distance_obj->transform.globalPosition.y-list[j].transform.globalPosition.y,
						min_distance_obj->transform.globalPosition.z-list[j].transform.globalPosition.z);
			Line_Set(ray,&list[j].transform.globalPosition,direction);
			distance = CollideBox_RayDistance(enemy->collideBoxes,&list[j].transform,ray);
			if (distance == INFINITY) continue;
			if (distance < min_distance){
				min_distance = distance;
				min_temp = &list[j];
			}
		}
		struct link* link = NULL;
		link->current = &min_temp->transform;
		link->next = next_addr;
		min_distance_obj = min_temp;
		next_addr = link;
		min_temp = NULL;
	}

	struct link* beginning = NULL;
	beginning->current = &enemy->transform;
	beginning->next = next_addr;

}
