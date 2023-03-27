#include "property.h"

void Property_Set(struct Enemy *enemy,struct Object* body,struct Object* face, struct Object* leg, double speed){
    enemy->body = *body;
    enemy->leg = *leg;
    enemy->face = *face;
    enemy->speed = speed;
}



struct Enemy *alpha;
struct Enemy *beta;

