#include "../include.h"

// initializes a new memory group
MemoryGroup* mem_group_init(){
    MemoryGroup* memory = malloc(sizeof(MemoryGroup));
    return memory;
}
// initializes a new memory element
void* mem_init(MemoryGroup* memory, int size){
    void* element = malloc(size);
    Memory* mem = malloc(sizeof(Memory));
    mem->element = element;
    if(memory->size++ == 0){
        memory->start = mem;
        memory->end = mem;
        return element;
    }
    memory->end->next = mem;
    mem->prev = memory->end;
    memory->end = mem;
    return element;
}
// frees the memory at ptr
void mem_free(MemoryGroup* memory, void* ptr){

    if(!ptr){return;}
    Memory* mem = memory->start;
    int i = 0,worked = 0;
    for(;i<memory->size;i++){
        if(mem->element == ptr){worked=1;break;}
        mem = mem->next;
    }
    if(!worked){return;}
    memory->size--;
    if(i == 0){
        Memory* next = mem->next;
        memory->start = next;
    }
    else if(i == memory->size){
        Memory* prev = mem->prev;
        memory->end = prev;
    }
    else{
        mem->prev->next = mem->next;
        mem->next->prev = mem->prev;
    }
    free(ptr);
    free(mem);
}
// copies the memory from ptr to a new location
void* mem_copy(MemoryGroup* memory, void* ptr, int size){
    void* new_ptr = mem_init(memory,size);
    memcpy(new_ptr,ptr,size);
    return new_ptr;
}
