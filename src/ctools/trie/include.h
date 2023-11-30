#ifndef CTOOLS_TRIE_H
#define CTOOLS_TRIE_H

#include "../vector/include.h"
#include "../memory/include.h"

#define TRIE_SIZE 256

typedef struct TrieStruct Trie;

typedef struct TrieStruct{
    Trie* children[256];
    void* value;
} Trie;

Trie* trie_init();
void trie_add(Trie* trie,void* value,size_t* array);
void* trie_get(Trie* trie,size_t* array);
void trie_remove(Trie* trie,size_t* array);
void trie_free(Trie* trie);

#endif

