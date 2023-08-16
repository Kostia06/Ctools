#ifndef CTOOLS_H
#define CTOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemoryGroupStruct MemoryGroup;
typedef struct MemoryStruct Memory;

typedef struct LinkedStruct Linked;
typedef struct LinkedItemStruct LinkedItem;

typedef struct VectorStruct Vector;

typedef struct StackStruct Stack;

/*
    ****** NOTES ******
    - Memory
        takes 1, but it will not show up in the memory slots
    - Vector
        always takes up 2 memory slots, the amount of items do not matter
        For example, if you have a vector of 10 integers, it will take up 12 memory slots
    - Linked
        always takes up 1 memory slots
        or each item, it takes up 2 memory slots
        For example, if you have a linked list of 10 integers, it will take up 21 memory slots 
    - Stack
        always takes up 2 memory slots, the amount of items do not matter
        For example, if you have a stack of 10 integers, it will take up 2 memory slots
*/


// vector ---------------------------------------------------------------------
typedef struct VectorStruct{
    MemoryGroup* memory;
    void** data;
    size_t size, capacity;
}Vector;

Vector* vector_init(MemoryGroup* memory);
void vector_add(Vector* vector, void* element);
void* vector_get(Vector* vector, int index);
void vector_insert(Vector* vector, void* element, int index);
void vector_replace(Vector* vector, void* element, int index);
void vector_remove(Vector* vector, int index);
void* vector_pop(Vector* vector);
void vector_clear(Vector* vector);
void vector_free(Vector* vector);
// linked list ---------------------------------------------------------------
typedef struct LinkedItemStruct{
    LinkedItem* prev, *next;
    void* element;
} LinkedItem;
typedef struct LinkedStruct{
    MemoryGroup* memory;
    LinkedItem* start, *end;
    size_t size;
} Linked;

Linked* linked_init(MemoryGroup* memory);
void linked_add(Linked* linked, void* element);
void linked_insert(Linked* linked, void* element, int index);
void linked_remove(Linked* linked, int index);
void* linked_pop(Linked* linked);
void* linked_get(Linked* linked, int index);
void* linked_get_and_remove(Linked* linked, int index);
void linked_replace(Linked* linked, void* element, int index);
void linked_free(Linked* linked);
// stack ----------------------------------------------------------------------
typedef struct StackStruct{
    MemoryGroup* memory;
    void** data;
    size_t capacity, top;
} Stack;

Stack* stack_init(MemoryGroup* memory, size_t capacity);
void stack_add(Stack* stack, void* element);
void* stack_pop(Stack* stack);
void stack_free(Stack* stack);
// memory ---------------------------------------------------------------------
typedef struct MemoryStruct{
    Memory* prev, *next;
    void* element;
} Memory;
typedef struct MemoryGroupStruct{
    Memory* start, *end;
    size_t size;
} MemoryGroup;

MemoryGroup* mem_group_init();
void* mem_init(MemoryGroup* memory, int size);
void mem_free(MemoryGroup* memory, void* ptr);
void* mem_copy(MemoryGroup* memory, void* ptr, int size);
#endif

