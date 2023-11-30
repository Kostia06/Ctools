#ifndef CTOOLS_MEMORY_H
#define CTOOLS_MEMORY_H

#include <stdlib.h>
#include <assert.h>

void *mem_alloc(size_t size);
void mem_free(void *ptr);
size_t mem_size();


#endif

