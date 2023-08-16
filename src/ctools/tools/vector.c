#include "../include.h"

// initializes a new vector
Vector* vector_init(MemoryGroup* memory){
    Vector* vector = mem_init(memory,sizeof(Vector));
    vector->memory = memory;
    vector->capacity = 1;
    vector->data = mem_init(memory, vector->capacity*sizeof(void*));
    return vector;
}
// adds an element to the end of the vector
void vector_add(Vector* vector, void* element){
    if(vector->size++ == vector->capacity){
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity*sizeof(void*));
    }
    vector->data[vector->size] = element;
}
// gets element at index
void* vector_get(Vector* vector, int index){
    if(index < 0 || index >= vector->size){return NULL;}
    return vector->data[index];
}
// adds element by index
void vector_insert(Vector* vector, void* element, int index){
    if(index < 0 || index >= vector->size){return;}
    if(vector->size++ == vector->capacity){
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity*sizeof(void*));
    }
    memmove(&vector->data[index+1], &vector->data[index], (vector->size - index)*sizeof(void*));
    vector->data[index] = element;
}
// replaces item at index
void vector_replace(Vector* vector, void* element, int index){
    if(index < 0 || index >= vector->size){return;}
    vector->data[index] = element;
}
// removes element at index
void vector_remove(Vector* vector, int index){
    if(index < 0 || index >= vector->size){return;}
    mem_free(vector->memory,vector->data[index]);
    memmove(&vector->data[index], &vector->data[index+1], (vector->size - index)*sizeof(void*));
    if(--vector->size < vector->capacity / 4){
        vector->capacity /= 2;
        vector->data = realloc(vector->data, vector->capacity*sizeof(void*));
    }
}
// removes last element from the vector and returns the value
void* vector_pop(Vector* vector){
    if(vector->size == 0){return NULL;}
    void* element = vector->data[vector->size - 1];
    if(--vector->size < vector->capacity / 4){
        vector->capacity /= 2;
        vector->data = realloc(vector->data, vector->capacity*sizeof(void*));
    }
    return element;
}
// clears vector
void vector_clear(Vector* vector){
    for(size_t i = 0; i < vector->size; i++){
        void* element = vector->data[i];
        if(element != NULL){mem_free(vector->memory,element);}
    }
    vector->size = 0;
    vector->capacity = 1;
    vector->data = realloc(vector->data, vector->capacity*sizeof(void*));
}
// destroys vector
void vector_free(Vector* vector){
    vector_clear(vector);
    mem_free(vector->memory,vector->data);
}
