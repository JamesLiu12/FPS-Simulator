#include "array_list.h"
#include "stdlib.h"

struct ArrayList *New_ArrayList(unsigned int element_size) {
    struct ArrayList *list = malloc(sizeof(struct ArrayList));

    list->size = 0;
    list->capacity = 2;
    list->element_size = element_size;
    list->data = malloc(element_size * 2);

    return list;
}

void Del_ArrayList(struct ArrayList* list) {
    free(list->data);
    free(list);
}

char ArrayList_Append(struct ArrayList* list, void *element) {

}

void* ArrayList_Pop() {

}
