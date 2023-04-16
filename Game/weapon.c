#include "weapon.h"

void Weapon_Init(struct Weapon* weapon, struct Player* player, struct ArrayList* weapon_list)
{
    Transform_Init(&weapon->transform,&player->transform);
    weapon->transform = player->transform;

    weapon->damage = 10;
    weapon->speed = 1;
    weapon->critical_rate = 30;//0-100

    weapon->index = weapon_list->capacity;//all weapons in this function are assumed not initialized and should be added into the list
    ArrayList_PushBack(weapon_list,weapon);

    if(player->weapon.damage == 0) player->weapon = *weapon;//player's weapon does not exist
}

void Weapon_Change(struct Weapon* Old, struct Weapon* New, struct Player* player, struct ArrayList* weapon_list)
{
    struct Weapon empty = {};
    if(New->index == empty.index) Weapon_Init(New,player,weapon_list);//New weapon is not initialized
    player->weapon = *New;
}

void Del_Weapon(struct Weapon* weapon)
{
    free(weapon);
}
void Weapon_List_Init(struct ArrayList* weapon_list)
{
    ArrayList_Init(weapon_list,sizeof(struct Weapon));
    struct Weapon empty = {};
    ArrayList_PushBack(weapon_list,&empty);
}