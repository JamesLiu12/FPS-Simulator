#include "object.h"
#include "canvas.h"
#include "triangle.h"
#include "matrix.h"
#include "vector.h"

void Object_Set(struct Object *object, struct Mesh *mesh, struct Transform *transform, enum Tag tag) {
    object->mesh = mesh;
    object->transform = *transform;
    object->tag = tag;
}

struct Object* Object_New(struct Mesh* mesh, enum Tag tag) {
    struct Object *object = malloc(sizeof (struct Object));
    object->mesh = mesh;
    Transform_Init(&object->transform);
    object->tag = tag;
    return object;
}

void Object_Show(struct Object *object, struct Canvas *canvas) {
    if (Vector3_Distance3D(&object->transform.position, &canvas->camera_transform.position)
        > canvas->render_distance) return;

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

        Matrix3x3_Transform(&object->transform.rotation_matrix, &v1);
        Matrix3x3_Transform(&object->transform.rotation_matrix, &v2);
        Matrix3x3_Transform(&object->transform.rotation_matrix, &v3);

        Vector3_Add(&v1, &object->transform.position);
        Vector3_Add(&v2, &object->transform.position);
        Vector3_Add(&v3, &object->transform.position);


        Triangle_Set(&triangle, &v1, &v2, &v3);
        Canvas_DrawTriangle(canvas, &triangle, object->tag);
    }
}

void Object_Rotation(struct Object *object, struct Vector3* rotation) {
    object->transform.rotation.x += rotation->x;
    object->transform.rotation.y += rotation->y;
    object->transform.rotation.z += rotation->z;

    Transform_RotationMatrixUpdate(&object->transform);
}

void Object_Move(struct Object *object, struct Vector3* move){
    object->transform.position.x += move->x;
    object->transform.position.y += move->y;
    object->transform.position.z += move->z;
}