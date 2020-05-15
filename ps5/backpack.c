#include "backpack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct backpack* create_backpack(const int capacity){
    struct backpack* batoh=calloc(1,sizeof(struct backpack));
    batoh->capacity=capacity;
    return batoh;
}

    
struct backpack* destroy_backpack(struct backpack* backpack){
    free(backpack);
    return NULL;
}

bool add_item_to_backpack(struct backpack* backpack, struct item* item){
    if(backpack==NULL || item==NULL)
    return 0;
    if(backpack->capacity>backpack->size){
        if (backpack->items!=NULL)
        {
                        create_container(backpack->items, ITEM, item);
            backpack->size++;
    return 1;   
    }
    else
    {
     backpack->items=create_container(backpack->items, ITEM, item);
     return 1;
    
    }
    }
    else
        
        return 0;
}
