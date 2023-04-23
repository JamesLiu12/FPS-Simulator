#include "weapon.h"
#include "string.h"
#include "../op_engine/canvas.h"

void Weapon_Init(struct Weapon* weapon, enum WeaponName weaponName){

    if (weaponName == AK47){
        weapon->damage = 10;
        weapon->fireCDtime = 0.1;
        weapon->reloadCDtime=2;
        weapon->magazine_size=30;
        weapon->bullet_number=weapon->magazine_size;
        weapon->head_rate=1.2;
        weapon->body_rate=1.0;
        weapon->leg_rate=0.8;
        strcpy(weapon->namestring,"   AK47   ");
    }
    if (weaponName == P1999){
        weapon->damage = 40;
        weapon->fireCDtime = 0.6;
        weapon->reloadCDtime=0.9;
        weapon->magazine_size=8;
        weapon->bullet_number=weapon->magazine_size;
        weapon->head_rate=1.5;
        weapon->body_rate=1.0;
        weapon->leg_rate=0.9;
        strcpy(weapon->namestring,"  P1999   ");
    }
}

struct Weapon* New_Weapon(enum WeaponName weaponName){
    struct Weapon* weapon = (struct Weapon*)malloc(sizeof(struct Weapon));
    Weapon_Init(weapon, weaponName);
    return weapon;
}

void Weapon_CoverCanvas(struct Weapon *weapon, struct Canvas *canvas){
    if (weapon->name == AK47){
        
    }
}