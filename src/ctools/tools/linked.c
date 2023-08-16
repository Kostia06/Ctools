#include "../include.h"

// removes the item without freeing the element, only linked item
static void linked_remove_item(Linked* linked, int index){
    int end = linked->size - index;
    int start = index;
    LinkedItem* item;
    // handle out of bounds
    if(index < 0 || index >= linked->size){return;}
    // handle the start of the list
    else if(index == 0){
        item = linked->start;
        linked->start = item->next;
        linked->start->prev = NULL;
    }
    // handle the end of the list
    else if(index == linked->size){
        item = linked->end;
        linked->end = item->prev;
        linked->end->next = NULL;
    }
    // handle anywhere else
    else{
        // it is closer to the start
        if(index > end){
            LinkedItem* next = linked->start;
            for(int i=0;i<start;i++){next = next->next;}
            LinkedItem* prev = next->prev;
            prev->next = next->next;
            next->next->prev = prev;
            item = next;
        }
        // it is closer to the end
        else{
            LinkedItem* prev = linked->end;
            for(int i=0;i<end;i++){prev = prev->prev;}
            LinkedItem* next = prev->next;
            prev->next = next->next;
            next->next->prev = prev;
            item = next;
        }
    }
    mem_free(linked->memory, item);
    linked->size--;
}



// initializes a new linked list
Linked* linked_init(MemoryGroup* memory){
    Linked* linked = mem_init(memory, sizeof(Linked));
    linked->memory = memory; 
    return linked;
}
// adds an element to the end of the linked list
void linked_add(Linked* linked, void* element){
    LinkedItem* item = mem_init(linked->memory, sizeof(LinkedItem));
    item->element = element;
    // handle the fist element in the list
    if(linked->size++ == 0){
        linked->start = item;
        linked->end = item;
        return;
    }
    // handle any other element in the list
    linked->end->next = item;
    item->prev = linked->end;
    linked->end = item;
}
// adds an element to the linked list at the specified index
void linked_insert(Linked* linked, void* element, int index){
    LinkedItem* item = mem_init(linked->memory, sizeof(LinkedItem));
    item->element = element;
    // handle out of bounds
    if(index < 0 || index >= linked->size){return;}
    // handle the start of the list
    else if(index == 0){
        item->next = linked->start;
        linked->start->prev = item;
        linked->start = item;
    }
    // handle the end of the list
    else if(index == linked->size){
        linked->end->next = item;
        item->prev = linked->end;
        linked->end = item;
    }
    // handle anywhere else
    else{
        int end = linked->size - index;
        int start = index;
        // it is closer to the start
        if(index > end){
            LinkedItem* next = linked->start;
            for(int i=0;i<start;i++){next = next->next;}
            LinkedItem* prev = next->prev;
            prev->next = item;
            item->prev = prev;
            item->next = next;
            next->prev = item;
        }
        // it is closer to the end
        else{
            LinkedItem* prev = linked->end;
            for(int i=0;i<end;i++){prev = prev->prev;}
            LinkedItem* next = prev->next;
            prev->next = item;
            item->prev = prev;
            item->next = next;
            next->prev = item;
        }
    }
    linked->size++;
}
// removes an element from the linked list
void linked_remove(Linked* linked, int index){
    int end = linked->size - index;
    int start = index;
    LinkedItem* item;
    // handle out of bounds
    if(index < 0 || index >= linked->size){return;}
    // handle the start of the list
    else if(index == 0){
        item = linked->start;
        linked->start = item->next;
        linked->start->prev = NULL;
    }
    // handle the end of the list
    else if(index == linked->size){
        item = linked->end;
        linked->end = item->prev;
        linked->end->next = NULL;
    }
    // handle anywhere else
    else{
        // it is closer to the start
        if(index > end){
            LinkedItem* next = linked->start;
            for(int i=0;i<start;i++){next = next->next;}
            LinkedItem* prev = next->prev;
            prev->next = next->next;
            next->next->prev = prev;
            item = next;
        }
        // it is closer to the end
        else{
            LinkedItem* prev = linked->end;
            for(int i=0;i<end;i++){prev = prev->prev;}
            LinkedItem* next = prev->next;
            prev->next = next->next;
            next->next->prev = prev;
            item = next;
        }
    }
    mem_free(linked->memory, item->element);
    mem_free(linked->memory, item);
    linked->size--;
}
// remove the last element from the linked list and get value
void* linked_pop(Linked* linked){
    if(linked->size == 0){return NULL;}
    LinkedItem* item = linked->end;
    linked->end = item->prev;
    linked->end->next = NULL;
    void* element = item->element;
    mem_free(linked->memory, item);
    linked->size--;
    return element;
}
// get the element at the specified index
void* linked_get(Linked* linked, int index){
    LinkedItem* item;
    // handle out of bounds
    if(index < 0 || index >= linked->size){return NULL;}
    // handle the start of the list
    else if(index == 0){item = linked->start;}
    // handle the end of the list
    else if(index == linked->size){item = linked->end;}
    // handle anywhere else
    else{
        int end = linked->size - index;
        int start = index;
        // it is closer to the start
        if(start > end){
            LinkedItem* next = linked->start;
            for(int i=0;i<start;i++){next = next->next;}
            item = next;
        }
        // it is closer to the end
        else{
            LinkedItem* prev = linked->end;
            for(int i=0;i<end;i++){prev = prev->prev;}
            item = prev;
        }
    }
    return item->element;
}
// get and remove the element at the specified index
void* linked_get_and_remove(Linked* linked, int index){
    LinkedItem* item;
    // handle out of bounds
    if(index < 0 || index >= linked->size){return NULL;}
    // handle the start of the list
    else if(index == 0){item = linked->start;}
    // handle the end of the list
    else if(index == linked->size){item = linked->end;}
    // handle anywhere else
    else{
        int end = linked->size - index;
        int start = index;
        // it is closer to the start
        if(start > end){
            LinkedItem* next = linked->start;
            for(int i=0;i<start;i++){next = next->next;}
            item = next;
        }
        // it is closer to the end
        else{
            LinkedItem* prev = linked->end;
            for(int i=0;i<end;i++){prev = prev->prev;}
            item = prev;
        }
    }
    void* element = item->element;
    linked_remove_item(linked, index);
    return element;
}
// replace the element at the specified index
void linked_replace(Linked* linked, void* element, int index){
    LinkedItem* item;
    // handle out of bounds
    if(index < 0 || index >= linked->size){return;}
    // handle the start of the list
    else if(index == 0){item = linked->start;}
    // handle the end of the list
    else if(index == linked->size){item = linked->end;}
    // handle anywhere else
    else{
        int end = linked->size - index;
        int start = index;
        // it is closer to the start
        if(start > end){
            LinkedItem* next = linked->start;
            for(int i=0;i<start;i++){next = next->next;}
            item = next;
        }
        // it is closer to the end
        else{
            LinkedItem* prev = linked->end;
            for(int i=0;i<end;i++){prev = prev->prev;}
            item = prev;
        }
    }
    mem_free(linked->memory, item->element);
    item->element = element;
}
void linked_free(Linked* linked){
    LinkedItem* item = linked->start;
    while(item != NULL){
        LinkedItem* next = item->next;
        mem_free(linked->memory, item->element);
        mem_free(linked->memory, item);
        item = next;
    }
    mem_free(linked->memory, linked);
}
