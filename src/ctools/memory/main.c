#include "include.h"

static size_t memory_size = 0;

void *mem_alloc(size_t size){
    memory_size++;
    return malloc(size);
}
void mem_free(void *ptr){
    if(memory_size == 0){ assert(0 && "memory_free() called too many times"); }
    memory_size--;
    free(ptr);
}
size_t mem_size(){
    return memory_size;
}
