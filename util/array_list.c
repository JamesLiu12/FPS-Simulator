#include "array_list.h"
#include "stdlib.h"

void ArrayList_Init(struct ArrayList *list, unsigned int element_size){
    list->size = 0;
    list->capacity = 2;
    list->element_size = element_size;
    list->node = (struct ArrayListNode*)malloc(element_size * list->capacity);
}

struct ArrayList *New_ArrayList(unsigned int element_size) {
    struct ArrayList *list = malloc(sizeof(struct ArrayList));
    ArrayList_Init(list, element_size);
    return list;
}


void Del_ArrayList(struct ArrayList *list) {
    while (!ArrayList_Empty(list)) ArrayList_PopBack(list);
    free(list->node);
    free(list);
}

bool ArrayList_Empty(struct ArrayList *list){
    return list->size == 0;
}

char ArrayList_Append(struct ArrayList* list, void *element) {
    if (list->size >= list->capacity){
        list->capacity *= 2;
        list->node = realloc(list->node, list->element_size * list->capacity);
    }
    struct ArrayListNode *data;
    data = (struct ArrayListNode*)malloc(sizeof(struct ArrayListNode));
    *data = *(struct ArrayListNode*)element;
    list->node[list->size++].data = element;
}

void ArrayList_PopBack(struct ArrayList *list) {
    if (ArrayList_Empty(list)) return;
    free(list->node[list->size - 1].data);
    list->size--;
}

void* ArrayList_Back(struct ArrayList *list){
    return list->node[list->size - 1].data;
}