#include "object.h"
#include "canvas.h"
#include "triangle.h"
#include "matrix.h"
#include "vector.h"

void Object_Set(struct Object *object, struct Mesh *mesh, struct Transform *transform, enum Tag tag,
        int number_of_child, struct Object* child, struct Object* father) {
    object->mesh = mesh;
    object->transform = *transform;
    object->tag = tag;
    object->number_of_child = number_of_child;
    object->childList = child;
    object->father = father;
}

struct Object* Object_New(struct Mesh *mesh, struct Transform *transform, enum Tag tag,
        int number_of_child, struct Object* child, struct Object* father) {
    struct Object *object = malloc(sizeof (struct Object));
    Object_Set(object, mesh, transform, tag, number_of_child, child, father);
    return object;
}

void Del_Object(struct Object *object){
    for (int i = 0; i < object->number_of_child; i++){
        Del_Object(&object->childList[i]);
    }
    free(object);
}

void Object_Show(struct Object *object, struct Canvas *canvas, struct Transform *transform_father) {
    if (Vector3_Distance3D(&object->transform.position, &canvas->camera_transform.position)
        > canvas->render_distance) return;

    struct Transform transform;
    Transform_Init(&transform);

    if (transform_father != NULL){
        transform.position = transform_father->position;
        transform.rotation = transform_father->rotation;
        Transform_RotationMatrixUpdate(&transform);
        transform.scale = transform_father->scale;
    }

    if (object->mesh != NULL){

        Vector3_Add(&transform.position, &object->transform.position);
        Vector3_Add(&transform.rotation, &object->transform.rotation);
        Transform_RotationMatrixUpdate(&transform);
        Vector3_Multiply(&transform.scale, &object->transform.scale);

        for (int face_index = 0; face_index < object->mesh->triangle_count; face_index++){
            struct Triangle triangle;

            unsigned int
                vertex_index1 = object->mesh->triangles[face_index].f1,
                vertex_index2 = object->mesh->triangles[face_index].f2,
                vertex_index3 = object->mesh->triangles[face_index].f3;

            struct Vector3 v1, v2, v3;
            v1 = object->mesh->vertices[vertex_index1];
            v2 = object->mesh->vertices[vertex_index2];
            v3 = object->mesh->vertices[vertex_index3];

            Matrix3x3_Transform(&transform.rotation_matrix, &v1);
            Matrix3x3_Transform(&transform.rotation_matrix, &v2);
            Matrix3x3_Transform(&transform.rotation_matrix, &v3);

            Vector3_Scale(&v1, &transform.scale);
            Vector3_Scale(&v2, &transform.scale);
            Vector3_Scale(&v3, &transform.scale);

            Vector3_Add(&v1, &transform.position);
            Vector3_Add(&v2, &transform.position);
            Vector3_Add(&v3, &transform.position);


            Triangle_Set(&triangle, &v1, &v2, &v3);
            Canvas_DrawTriangle(canvas, &triangle, object->tag);
        }
    }
    if (object->childList != NULL){
        for (int i = 0; i < object->number_of_child; i++){
            Object_Show(&object->childList[i], canvas, &transform);
        }
    }
}

void Object_Rotation(struct Object *object, struct Vector3* rotation) {
    object->transform.rotation.x += rotation->x;
    object->transform.rotation.y += rotation->y;
    object->transform.rotation.z += rotation->z;

    Transform_RotationMatrixUpdate(&object->transform);
}

