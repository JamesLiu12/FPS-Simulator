#ifndef FPS_SIMULATOR_DAMAGE_H
#define FPS_SIMULATOR_DAMAGE_H
//damage calculation & determination from enemy to player


#include "../scene.h"

bool Damage_Determination(struct Scene *scene,struct Enemy *enemy);
double Damage_Calculation(struct Scene *scene,struct Enemy *enemy);


#endif //FPS_SIMULATOR_DAMAGE_H
