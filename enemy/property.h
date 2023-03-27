#ifndef FPS_SIMULATOR_PROPERTY_H
#define FPS_SIMULATOR_PROPERTY_H

#include "../op_engine/op_engine.h"

struct Enemy{
    struct Object face,leg,body;
    double speed,damage,health;
};

void Property_Set(struct Enemy *enemy,struct Object* body,struct Object* face, struct Object* leg, double speed);

#endif //FPS_SIMULATOR_PROPERTY_H
