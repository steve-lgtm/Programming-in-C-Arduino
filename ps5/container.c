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
    if(first==NULL){
        struct container * new=malloc(sizeof(struct container));
        char *text;
        new->type=type;
        switch (type)
        {
        case ROOM:
            new->room=entry;
            break;
        
        case ITEM:
            new->item=entry;
            break;
        
        case COMMAND:
            new->command=entry;
            break;
        
        case TEXT:
            text=malloc((strlen(entry)+1));
            strcpy(text,entry);
            new->text=text;
            break;
        
        }
        return new;
    }
   return first; 
   if(first!=NULL){
       if(first->type!=type)
           return NULL;
           else{
        struct container * new=malloc(sizeof(struct container));
        char *text;
        new->type=type;
        switch (type)
        {
        case ROOM:
            new->room=entry;
            break;
        
        case ITEM:
            new->item=entry;
            break;
        
        case COMMAND:
            new->command=entry;
            break;
        
        case TEXT:
            text=malloc((strlen(entry)+1));
            strcpy(text,entry);
            new->text=text;
            break;
        }
        while(first->next!=NULL){
            first=first->next;
        }
        first->next=new;
        return new;
           }
           
       }

   }


struct container* destroy_containers(struct container* first){
    free(first);
    return NULL;
}
