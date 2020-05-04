#include "container.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct container* create_container(struct container* first, enum container_type type, void* entry){
    if(entry==NULL)
    {
        return NULL;
    }
first->type=type;
first->command=entry;
first->item=entry;
first->room=entry;
first->text=entry;
struct container * new = malloc(sizeof(struct container));
new->type=type;
new->command=entry;
new->item=entry;
new->room=entry;
new->text=entry;
    if (first->type!=new->type)
    {
        return NULL;
    }

   return new; 
}