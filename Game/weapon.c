#include "weapon.h"

void Weapon_Init(struct Weapon* weapon, enum WeaponName weaponName){

    if (weaponName == AK47){
        weapon->damage = 10;
        weapon->speed = 1;
        weapon->critical_rate = 0.3;
    }
}

struct Weapon* New_Weapon(enum WeaponName weaponName){
    struct Weapon* weapon = (struct Weapon*)malloc(sizeof(struct Weapon));
    Weapon_Init(weapon, weaponName);
    return weapon;
}