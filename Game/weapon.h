#ifndef FPS_SIMULATOR_WEAPON_H
#define FPS_SIMULATOR_WEAPON_H

#include "../op_engine/op_engine.h"

// a list of names of weapons available
enum WeaponName{
    AK47, P1999, Razor_ELEC, X_114514, MOSS, 
};

// defines the parameters available for each weapon
struct Weapon{
    double fireCDtime, damage, reloadCDtime;
    double head_rate,body_rate,leg_rate;
    int bullet_number,magazine_size;
    enum WeaponName name;
    char namestring[10];
};


//Initializer of weapon (corresponding to player)
void Weapon_Init(struct Weapon* weapon, enum WeaponName weaponName);
struct Weapon* New_Weapon(enum WeaponName weaponName);
void Weapon_CoverCanvas(struct Weapon *weapon, struct Canvas *canvas);


#endif //FPS_SIMULATOR_WEAPON_H
