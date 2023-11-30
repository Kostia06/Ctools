#ifndef CTOOLS_VECTOR_H
#define CTOOLS_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../std/include.h"
#include "../memory/include.h"

typedef struct{
    size_t size, length;
    char data[];
} Vector;

#define _vec_add_asg(vec_ptr)      \
	((typeof(*vec_ptr))(_vec_add((void**)vec_ptr, sizeof(**vec_ptr)))) 
#define vec_insert_asg(vec_ptr,pos) \
    ((typeof(*vec_ptr))(_vec_insert((void**)vec_ptr, sizeof(**vec_ptr), pos)))

#define vec_add(vec_ptr,value) (*_vec_add_asg(vec_ptr) = value)
#define vec_insert(vec_ptr,pos,value) (*vec_insert_asg(vec_ptr,pos) = value)
#define vec_remove(vec_ptr,pos) _vec_remove((void**)vec_ptr,pos,sizeof(**vec_ptr))

void* vec_init();
void vec_set_size(void* vector,size_t size);
size_t vec_size(void* vector);
void vec_free(void* vector);
void vec_clear(void* vector);
void* vec_copy(void* vector);
// private
Vector* _vec_get(void* vector);
int _vec_has_space(Vector* vector);
void* _vec_add(void** vector, size_t size);
void* _vec_insert(void** vector, size_t size, size_t pos);
void _vec_remove(void** vector,size_t pos,size_t size);

#endif
