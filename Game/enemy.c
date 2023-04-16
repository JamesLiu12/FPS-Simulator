#include "enemy.h"

void Enemy_Init(struct Enemy *enemy, struct Object *head, struct Object *body, struct Object *leg){
    enemy->head = *head;
    enemy->body = *body;
    enemy->leg = *leg;
    Transform_Init(&enemy->transform, NULL);
    Transform_Init(&enemy->head.transform, &enemy->transform);
    Transform_Init(&enemy->body.transform, &enemy->transform);
    Transform_Init(&enemy->leg.transform, &enemy->transform);
    Transform_CopyValues(&head->transform, &enemy->head.transform);
    Transform_CopyValues(&body->transform, &enemy->body.transform);
    Transform_CopyValues(&leg->transform, &enemy->leg.transform);
}

struct Enemy* New_Enemy(struct Object *head, struct Object *body, struct Object *leg){
    struct Enemy *enemy = (struct Enemy*)malloc(sizeof(struct Enemy));
    Enemy_Init(enemy, head, body, leg);
    return enemy;
}

void Del_Enemy(struct Enemy *enemy){

}