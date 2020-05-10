#include "container.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


struct container* remove_container(struct container *first, void *entry){
    if (entry==NULL || first==NULL){
        return NULL;}
    struct container *new=first;
    int i=0;
    
    while (i>1)
    {
        switch (first->type)
        {
        case ROOM:
            if (new->room==entry)
            {
                first=first->next;
                return first;
                i++;
            }
            break;
        case ITEM:
            if (new->item==entry)
            {
                first=first->next;
                return first;
                i++;
            }
            break;
        case COMMAND:
            if (new->command==entry)
            {
                first=first->next;
                return first;
                i++;
            }
            break;
        case TEXT:
            if (new->text==entry)
            {
                first=first->next;
                return first;
                i++;
            }
            break;
        }
        new=new->next;
    }
    if(first==NULL)
    return NULL;

    return first;
    
}

struct container* create_container(struct container* first, enum container_type type, void* entry){
    if(entry==NULL)
    {
        return NULL;
    }
    if(first==NULL){
        struct container * new=calloc(10,sizeof(struct container));
        
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
            
            
            new->text=entry;
            break;
        
        }
       
        return new;
    }
   if(first!=NULL){
       if(first->type!=type)
           return NULL;
           else{
        struct container * new=calloc(10,sizeof(struct container));
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
            text = calloc(100,strlen(entry)+1);
                        strcpy(text, entry);
                        new->text = text;

            break;
        }
        while(first->next!=NULL){
            first=first->next;
        }
        first->next=new;
        
        return new;
           }
           
       }
       
return NULL;
   }


struct container* destroy_containers(struct container* first){
    if(first!=NULL){
        struct container *new=first->next;
        switch(first->type){
            case ROOM:
            if (first->type ==ROOM &&first->room!=NULL)
            {
                destroy_room(first->room);
                
            }
            break;
            case ITEM:
            if (first->type==ITEM && first->item!=NULL)
            {
                destroy_item(first->item);
                
            }
            case COMMAND:
            if (first->type==COMMAND && first->command!=NULL)
            {
                destroy_command(first->command);
                
            }
            case TEXT:
            if (first->type==TEXT && first->text!=NULL)
            {
                free(first->text);
                
            }
            
        }
        destroy_containers(new);
        
    }
    
    return NULL;
}
void* get_from_container_by_name(struct container *first, const char *name){
if(first == NULL || name == NULL){ 
    return NULL;
}
struct container *finded =first; 
while (finded !=NULL)
{
    switch (finded->type)
{
case ROOM:
    if(strcasecmp(finded->room->name,name)==0)
    return finded;
    else
    finded=finded->next;
    break;
case ITEM:
    if(strcasecmp(finded->item->name,name)==0)
    return finded;
    else
    finded=finded->next;
    break;
case COMMAND:
    if(strcasecmp(finded->command->name,name)==0)
    return finded;
    else
    finded=finded->next;
    break;
case TEXT:
    if(strcasecmp(finded->text,name)==0)
    return finded;
    else
    finded=finded->next;
    break;
}
}

return NULL;
}