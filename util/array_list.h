# ifndef UTIL_ARRAY_LIST
#include "util.h"

struct ArrayListNode {
    void *data;
};

struct ArrayList {
    unsigned int size, capacity;
    struct ArrayListNode *node;
    unsigned char element_size;
};

void ArrayList_Init(struct ArrayList *list, unsigned int element_size);
struct ArrayList *New_ArrayList(unsigned int element_size);
void Del_ArrayList(struct ArrayList* list);

bool ArrayList_Empty(struct ArrayList *list);
char ArrayList_Append(struct ArrayList *list, void *element);
void ArrayList_PopBack(struct ArrayList *list);
void* ArrayList_Back(struct ArrayList *list);

# define UTIL_ARRAY_LIST
#endif