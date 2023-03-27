#ifndef FPS_SIMULATOR_DAMAGE_H
#define FPS_SIMULATOR_DAMAGE_H
//damage calculation & determination from enemy to player

#include "behaviour.h"

int Damage_Determination(struct CollideBox *box, struct Vector3 *collide);
void Damage_Calculation(struct Enemy *enemy, );


#endif //FPS_SIMULATOR_DAMAGE_H
