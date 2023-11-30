#include "include.h"

Trie* trie_init(){
    Trie* trie = mem_alloc(sizeof(Trie));
    return trie;
}

void trie_add(Trie* trie,void* value,size_t* array){
    Trie* node = trie;
    for(size_t i =0;array[i] != -1;i++){
        size_t index = array[i];
        if(!node->children[index]){ node->children[index] = trie_init(); }
        node = node->children[index];
    }
    node->value = value;
}
void* trie_get(Trie* trie,size_t* array){
    Trie* node = trie;
    for(size_t i =0;array[i] != -1;i++){
        size_t index = array[i];
        if(!node->children[index] ){ return NULL; }
        node = node->children[index];
    }
    return node->value;
}
void trie_remove(Trie* trie,size_t* array){
    size_t size = 0;
    for(size_t i =0;array[i] != -1;++i){ size++; }
    size_t index = array[--size];
    Trie* node = trie;
    for(size_t i =0;i<size;i++){
        size_t index = array[i];
        if(!node->children[index] ){ return; }
        node = node->children[index];
    }
    mem_free(node->children[index]);
}
void trie_mem_free(Trie* trie){
    for(size_t i =0;i<256;i++){
        if(trie->children[i]){
            trie_mem_free(trie->children[i]);
        }
    }
    mem_free(trie);
}
