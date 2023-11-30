#include "include.h"

// create hash table
Hash hash_init(size_t max){
    Hash hash;
    hash.max = max;
    hash.data = mem_alloc(sizeof(void*)*max);
    return hash;
}
// add item to the hash table
void hash_insert(Hash* hash,size_t index ,void* ptr){
    assert(hash && "hash is NULL");
    assert(ptr && "ptr is NULL");
    assert(index < hash->max && "index out of range");
    assert(!hash->data[index] && "index is not empty");
    hash->data[index] = ptr;
}
// get item from the hash table
void* hash_get(Hash* hash,size_t index){
    assert(hash && "hash is NULL");
    assert(index < hash->max && "index out of range");
    return hash->data[index];
}
// turn a string into a hash index
int hash_to_index(Hash* hash,char* key){
    assert(hash && "hash is NULL");
    assert(key && "key is NULL");
    unsigned long new_key = 5381;
    int c;
    while ((c = *key++)) {
        new_key = ((new_key << 5) + new_key) + c; 
    }
    return new_key % hash->max;
}
// free hash table
void hash_free(Hash* hash){
    assert(hash && "hash is NULL");
    free(hash->data);
}
// free all hash table
void hash_free_all(Hash* hash){
    assert(hash && "hash is NULL");
    for(int i=0;i<hash->max;i++){ 
        if(hash->data[i]){ free(hash->data[i]); } 
    }
    free(hash->data);
}
