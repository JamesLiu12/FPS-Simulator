#include "weapon.h"
#include "string.h"
#include "../op_engine/canvas.h"

// assigns weapon data such as damage, fire cd time and so on to a weapon struct
// according to the name of the weapon
// input: a pointer to a weapon struct and an enumeration of WeaponName
// output: none
void Weapon_Init(struct Weapon* weapon, enum WeaponName weaponName){

    if (weaponName == AK47){
        weapon->damage = 21;
        weapon->fireCDtime = 0.1;
        weapon->reloadCDtime=1.6;
        weapon->magazine_size=30;
        weapon->bullet_number=weapon->magazine_size;
        weapon->head_rate=1.2;
        weapon->body_rate=1.0;
        weapon->leg_rate=0.8;
        strcpy(weapon->namestring,"   AK47   ");
    }
    if (weaponName == P1999){
        weapon->damage = 34;
        weapon->fireCDtime = 0.6;
        weapon->reloadCDtime=0.9;
        weapon->magazine_size=8;
        weapon->bullet_number=weapon->magazine_size;
        weapon->head_rate=1.5;
        weapon->body_rate=1.0;
        weapon->leg_rate=0.9;
        strcpy(weapon->namestring,"  P1999   ");
    }
    if (weaponName == Razor_ELEC){
        weapon->damage = 60;
        weapon->fireCDtime = 0.8;
        weapon->reloadCDtime=2;
        weapon->magazine_size=5;
        weapon->bullet_number=weapon->magazine_size;
        weapon->head_rate=1;
        weapon->body_rate=1.7;
        weapon->leg_rate=1;
        strcpy(weapon->namestring,"Razor_ELEC");
    }
    if (weaponName == X_114514){
        weapon->damage = 26;
        weapon->fireCDtime = 0.2;
        weapon->reloadCDtime=1;
        weapon->magazine_size=16;
        weapon->bullet_number=weapon->magazine_size;
        weapon->head_rate=1.3;
        weapon->body_rate=1.0;
        weapon->leg_rate=0.8;
        strcpy(weapon->namestring," X_114514 ");
    }
    if (weaponName == MOSS){
        weapon->damage = 70;
        weapon->fireCDtime = 0.1;
        weapon->reloadCDtime=1;
        weapon->magazine_size=1;
        weapon->bullet_number=weapon->magazine_size;
        weapon->head_rate=1;
        weapon->body_rate=1.5;
        weapon->leg_rate=1;
        strcpy(weapon->namestring,"   MOSS   ");
    }
}

// allocates heap memory to a weapon struct
// sets the parameters of the weapon based on its name
// returns the address of the memory allocated
// input: an enumeration of WeaponName
// output: the address of the Weapon struct allocated
struct Weapon* New_Weapon(enum WeaponName weaponName){
    struct Weapon* weapon = (struct Weapon*)malloc(sizeof(struct Weapon));
    Weapon_Init(weapon, weaponName);
    return weapon;
}

//
// input:
// output: