#include "../include.h"

// init node tree
NodeTree* node_init(MemoryGroup* memory,size_t size){
    NodeTree* tree = mem_init(memory, sizeof(NodeTree));
    tree->memory = memory;
    tree->size = size;
    tree->head = mem_init(memory, sizeof(Node));
    tree->head->roots = mem_init(memory, sizeof(Node*) * size);
    tree->head->slots = mem_init(memory, sizeof(Node*) * size);
    return tree;
}
// create new node add to targer node roots
Node* node_add(NodeTree* tree, Node* node, size_t index, void* element){
    if(node->roots[index]){return node->roots[index];}
    Node* new_node = mem_init(tree->memory, sizeof(Node));
    new_node->element = element;
    new_node->roots = mem_init(tree->memory, sizeof(Node*) * tree->size);
    new_node->slots = mem_init(tree->memory, sizeof(int) * tree->size);
    node->roots[index] = new_node;
    node->slots[node->size++] = index;
    return new_node;
}
// get node from target node roots
void* node_get_value(NodeTree* tree, size_t* indexs, size_t index){
    Node* node = tree->head;
    int worked = 1;
    for(size_t i = 0; i < index; i++){
        if(!node->roots[indexs[i]]){worked = 0;break;}
        node = node->roots[indexs[i]];
    }
    if(worked){return node->element;}
    return NULL;
}
// remove node from target node roots
void node_remove(NodeTree* tree,Node* node){
    for(int i=0;i<node->size;i++){
        int index = node->slots[i];
        node_remove(tree,node->roots[index]);
    }
    mem_free(tree->memory,node->roots);
    mem_free(tree->memory,node->element);
    mem_free(tree->memory,node->slots);
    mem_free(tree->memory,node);
}
// free node tree
void node_free(NodeTree* tree){
    node_remove(tree,tree->head);
    mem_free(tree->memory,tree);
}
