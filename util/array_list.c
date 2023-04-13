#include "array_list.h"
#include <stdlib.h>
#include <memory.h>
void ArrayList_Init(struct ArrayList *list, unsigned int element_size){
    list->size = 0;
    list->capacity = 2;
    list->element_size = element_size;
    list->data = malloc(element_size * list->capacity);
}

struct ArrayList *New_ArrayList(unsigned int element_size) {
    struct ArrayList *list = (struct ArrayList*)malloc(sizeof(struct ArrayList));
    ArrayList_Init(list, element_size);
    return list;
}

void Del_ArrayList(struct ArrayList *list) {
    free(list->data);
//    free(list);
}

bool ArrayList_Empty(struct ArrayList *list){
    return list->size == 0;
}

void ArrayList_PushBack(struct ArrayList* list, void *element) {
    if (list->size >= list->capacity){
        list->capacity *= 2;
        list->data = realloc(list->data, list->element_size * list->capacity);
    }
    memcpy(list->data + list->size * list->element_size, element, list->element_size);
    list->size++;
}

void ArrayList_PopBack(struct ArrayList *list) {
    if (ArrayList_Empty(list)) return;
    list->size--;
}

void* ArrayList_Back(struct ArrayList *list){
    return list->data + (list->size - 1) * list->element_size;
}

bool ArrayList_DeleteElement(struct ArrayList *list, void* element){
    for (int i = 0; i < list->size; i++){
        void *thisElement = list->data + i * list->element_size;
        if (memcmp(thisElement, element, list->element_size) == 0){
            void *nextElement = thisElement + list->element_size;
            memcpy(thisElement, nextElement, (list->size - i - 1) * list->element_size);
            list->size--;
            return TRUE;
        }
    }
    return FALSE;
}