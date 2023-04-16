#ifndef FPS_SIMULATOR_WEAPON_H
#define FPS_SIMULATOR_WEAPON_H
#include "../op_engine/op_engine.h"
#include "player.h"

//Initializer of weapon (corresponding to player)
void Weapon_Init(struct Weapon* weapon, struct Player* player, struct ArrayList* weapon_list);

void Weapon_Change(struct Weapon* Old, struct Weapon* New, struct Player* player, struct ArrayList* weapon_list);

void Weapon_List_Init(struct ArrayList* weapon_list);
#endif //FPS_SIMULATOR_WEAPON_H
