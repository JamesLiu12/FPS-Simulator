#include "enemy.h"

void Enemy_Init(struct Enemy *enemy, struct Object *head, struct Object *body, struct Object *leg){
    enemy->head = *head;
    enemy->body = *body;
    enemy->leg = *leg;
    Transform_Init(&enemy->head.transform, &enemy->transform);
    Transform_Init(&enemy->body.transform, &enemy->transform);
    Transform_Init(&enemy->leg.transform, &enemy->transform);
}

void Del_Enemy(struct Enemy *enemy){

}