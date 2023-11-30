#include "include.h"

// init a vector
void* vec_init(){
    Vector* vector = mem_alloc(sizeof(Vector));
    vector->size = 0;
    vector->length = 0;
    return &vector->data;
}
size_t vec_size(void* vector){
    Vector* vec = _vec_get(vector);
    return vec->length;
}
void vec_clear(void* vector){
    Vector* vec = _vec_get(vector);
    vec->length = 0;
    vec->size = 0;
}
void vec_free(void* vector){
    Vector* vec = _vec_get(vector);
    mem_free(vec);
}
void* vec_copy(void* vector){
    Vector* vec = _vec_get(vector);
    Vector* new_vec = mem_alloc(sizeof(Vector) + vec->size);
    memcpy(new_vec, vec, sizeof(Vector) + vec->size);
    return &new_vec->data;
}
// private
Vector* _vec_get(void* vector){
    Vector* vec = &((Vector*)vector)[-1];
    assert(vec && "Vector is NULL");
    return vec; 
}
int _vec_has_space(Vector* vector){ return vector->size - vector->length > 0; }
void* _vec_add(void** vector, size_t size){
    Vector* vec = _vec_get(*vector);
    if(!_vec_has_space(vec)){
        size_t new_size = (vec->size == 0) ? 1 : vec->size * 2;
        vec = realloc(vec, sizeof(Vector) + new_size * size);
        vec->size = new_size;
        *vector = &vec->data;
    }
   return (void*)&vec->data[size * vec->length++];
}
void* _vec_insert(void** vector, size_t size, size_t pos){
	Vector* vec = _vec_get(*vector);
    size_t new_length = vec->length + 1;
	if(!_vec_has_space(vec)){
        size_t new_size = (vec->size == 0) ? 1 : vec->size * 2;
        vec = realloc(vec, sizeof(Vector) + new_size * size);
        vec->size = new_size;
        *vector = &vec->data;
	}
	memmove(&vec->data[(pos + 1) * size], &vec->data[pos * size], (vec->length - pos) * size);
	vec->length = new_length;
	return &vec->data[pos * size];
}
void _vec_remove(void** vector,size_t pos,size_t size){
    Vector* vec = _vec_get(*vector);
    memmove(&vec->data[pos * size], &vec->data[(pos + 1) * size], (vec->length - pos) * size);
    vec->length--;
}
