#ifndef FPS_SIMULATOR_WEAPON_H
#define FPS_SIMULATOR_WEAPON_H

#include "../op_engine/op_engine.h"

enum WeaponName{
    AK47
};

struct Weapon{
    double speed, damage, critical_rate;
    enum WeaponName name;
};


//Initializer of weapon (corresponding to player)
void Weapon_Init(struct Weapon* weapon, enum WeaponName weaponName);
struct Weapon* New_Weapon(enum WeaponName weaponName);


#endif //FPS_SIMULATOR_WEAPON_H
