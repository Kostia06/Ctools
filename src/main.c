#include <stdio.h>
#include <string.h>
#include "ctools/include.h"

int main(){
    MemoryGroup* memory = mem_group_init();
    NodeTree* tree = node_init(memory,100);
    Node* main = tree->head; 
    Node* main1 = node_add(tree, main, 0, "main");
    Node* hello = node_add(tree, main1, 1, "hello");
    node_remove(tree,hello);
    printf("size: %zu\n",memory->size);
    return 0;
}
