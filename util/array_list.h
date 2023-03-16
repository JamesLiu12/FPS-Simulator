# ifndef UTIL_ARRAY_LIST

struct ArrayList {
    unsigned int size, capacity;
    void *data;
    unsigned char element_size;
};

struct ArrayList *New_ArrayList(unsigned int element_size);
void Del_ArrayList(struct ArrayList* list);

char ArrayList_Append(struct ArrayList* list, void *element);
void* ArrayList_Pop();


# define UTIL_ARRAY_LIST
#endif