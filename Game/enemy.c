#include "enemy.h"

void Enemy_Init(struct Enemy *enemy, struct EnemyMeshes *meshes){
    Transform_Init(&enemy->transform, NULL);

    struct Vector3 minVertex, maxVertex;

    //Enemy_Head
    struct CollideBox *collideBoxes_EnemyHead = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    Vector3_Set(&minVertex, -0.35, -0.35, -0.35);    //Head
    Vector3_Set(&maxVertex, 0.35, 0.35, 0.35);
    CollideBox_Set(collideBoxes_EnemyHead, &minVertex, &maxVertex);

    Object_Set(&enemy->head, meshes->head, &enemy->transform, ENEMY_HEAD,
               collideBoxes_EnemyHead,1);

    Vector3_Set(&enemy->transform.position, 0, 0.7, 0);

    //Enemy_Body
    struct CollideBox *collideBoxes_EnemyBody = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    Vector3_Set(&minVertex, -0.15, -0.5, -0.15);    //Body
    Vector3_Set(&maxVertex, 0.15, 0.5, 0.15);
    CollideBox_Set(collideBoxes_EnemyBody, &minVertex, &maxVertex);

    Object_Set(&enemy->body, meshes->body, &enemy->transform, ENEMY_BODY,
               collideBoxes_EnemyBody,1);

    Vector3_Set(&enemy->transform.position, 0, -0.15, 0);

    //Enemy_Leg
    struct CollideBox *collideBoxes_EnemyLeg = (struct CollideBox *)malloc(sizeof(struct CollideBox));
    Vector3_Set(&minVertex, -0.37, -0.2, -0.37);    //Leg
    Vector3_Set(&maxVertex, 0.37, 0.2, 0.37);
    CollideBox_Set(collideBoxes_EnemyLeg, &minVertex, &maxVertex);

    Object_Set(&enemy->leg, meshes->leg, &enemy->transform, ENEMY_LEG,
               collideBoxes_EnemyLeg,1);

    Vector3_Set(&enemy->transform.position, 0, -0.85, 0);
}

struct Enemy* New_Enemy(struct EnemyMeshes *meshes){
    struct Enemy *enemy = (struct Enemy*)malloc(sizeof(struct Enemy));
    Enemy_Init(enemy, meshes);
    return enemy;
}

void Del_Enemy(struct Enemy *enemy){
    Del_Transform(&enemy->transform);
}

void EnemyMeshes_Init(struct EnemyMeshes *meshes, struct Mesh *head, struct Mesh *body, struct Mesh *leg){
    meshes->head = head;
    meshes->body = body;
    meshes->leg = leg;
}

struct EnemyMeshes* New_EnemyMeshes(struct Mesh *head, struct Mesh *body, struct Mesh *leg){
    struct EnemyMeshes *meshes = (struct EnemyMeshes*)malloc(sizeof(struct EnemyMeshes));
    EnemyMeshes_Init(meshes, head, body, leg);
    return meshes;
}

void Del_EnemyMeshes(struct EnemyMeshes *meshes){
    Del_Mesh(meshes->head);
    Del_Mesh(meshes->body);
    Del_Mesh(meshes->leg);
}