#include "../include.h"

// initializes a new stack
Stack* stack_init(MemoryGroup* memory, size_t capacity){
    Stack* stack = mem_init(memory, sizeof(Stack));
    stack->data = mem_init(memory, capacity);
    stack->capacity = capacity;
    stack->memory = memory;
    return stack;
}
// add  an element to the top of the stack
void stack_add(Stack* stack, void* element){
    if(stack->top == stack->capacity-1){return;}
    stack->data[stack->top++] = element;
}
// removes the top element from the stack
void* stack_pop(Stack* stack){
    if(stack->top == 0){return NULL;}
    return stack->data[--stack->top];
}
// free stack
void stack_free(Stack* stack){
    for(size_t i=0;i<stack->top;i++){
        mem_free(stack->memory,stack->data[i]);
    }
    mem_free(stack->memory,stack->data);
    mem_free(stack->memory,stack);
}
