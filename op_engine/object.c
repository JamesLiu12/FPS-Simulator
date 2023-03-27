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

struct Object* Object_New(struct Mesh *mesh, struct Transform *transform, enum Tag tag) {
    struct Object *object = malloc(sizeof (struct Object));
    Object_Set(object, mesh, transform, tag);
    return object;
}

void Del_Object(struct Object *object){
    free(object);
}

void Object_Show(struct Object *object, struct Canvas *canvas, struct Transform *transform_father) {
    if (Vector3_Distance3D(&object->transform.position, &canvas->camera_transform.position)
        > canvas->render_distance) return;

    Transform_UpdateGlobal(&object->transform);

    if (object->mesh != NULL){

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

            Matrix3x3_Transform(&object->transform.globalRotationMatrix, &v1);
            Matrix3x3_Transform(&object->transform.globalRotationMatrix, &v2);
            Matrix3x3_Transform(&object->transform.globalRotationMatrix, &v3);

            Vector3_Scale(&v1, &object->transform.globalScale);
            Vector3_Scale(&v2, &object->transform.globalScale);
            Vector3_Scale(&v3, &object->transform.globalScale);

            Vector3_Add(&v1, &object->transform.globalPosition);
            Vector3_Add(&v2, &object->transform.globalPosition);
            Vector3_Add(&v3, &object->transform.globalPosition);


            Triangle_Set(&triangle, &v1, &v2, &v3);
            Canvas_DrawTriangle(canvas, &triangle, object->tag);
        }
    }
}

void Object_Rotation(struct Object *object, struct Vector3* rotation) {
    object->transform.rotation.x += rotation->x;
    object->transform.rotation.y += rotation->y;
    object->transform.rotation.z += rotation->z;

    Transform_RotationMatrixUpdate(&object->transform);
}

