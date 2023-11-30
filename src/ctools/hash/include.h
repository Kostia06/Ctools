#ifndef CTOOLS_HASH_H
#define CTOOLS_HASH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../memory/include.h"

typedef struct{
    void** data;
    size_t max;
} Hash;

Hash hash_init(size_t max);
void hash_insert(Hash* hash,size_t index ,void* ptr);
void* hash_get(Hash* hash,size_t index);
int hash_to_index(Hash* hash,char* key);
void hash_free(Hash* hash);
void hash_free_all(Hash* hash);

#endif

