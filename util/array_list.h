# ifndef UTIL_ARRAY_LIST
#include "util.h"

struct ArrayList {
    unsigned int size, capacity;
    void *data;
    unsigned char element_size;
};

//Initialize an arraylist
void ArrayList_Init(struct ArrayList *list, unsigned int element_size);

struct ArrayList *New_ArrayList(unsigned int element_size);

//Free the memory of the arraylist from heap
void Del_ArrayList(struct ArrayList* list);

//Return <=> the list is empty
bool ArrayList_Empty(struct ArrayList *list);

//Append the element to the back of the list
void ArrayList_Append(struct ArrayList *list, void *element);

//Delete the element at the back of the list
void ArrayList_PopBack(struct ArrayList *list);

//Return the pointer of the last element of the list
void* ArrayList_Back(struct ArrayList *list);

# define UTIL_ARRAY_LIST
#endif