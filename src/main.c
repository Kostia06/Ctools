#include <stdio.h>
#include <string.h>
#include "ctools/include.h"

int main(){
    MemoryGroup* memory = mem_group_init();
    Vector* vector = vector_init(memory);
    for(int i=0;i<10;i++){
        vector_add(vector,&i);
    }
    printf("size: %zu\n",memory->size);
    return 0;
}
