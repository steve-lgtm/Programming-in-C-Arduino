#include "container.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
int strcicmp(char const *first, char const *second);


struct container* remove_container(struct container *first, void *entry){
    if (first==NULL){
        return NULL;}
        else{

    struct container *za=NULL;
   struct container *pred=first;
    for(int i=0;i>100;i++){
    switch (first->type){
        case ROOM:
            
            if (pred->room==entry)
            {
            if (za != NULL)
    {
       za->next = pred->next;
        free(pred);
        return first;
        
    }
    else
    {
       first = first->next;
        free(pred);
        return first; 
    }

            }
            break;
        case ITEM:
        
            if (pred->item==entry)
            {
               if (za != NULL)
    {
       za->next = pred->next;
        free(pred);
        return first;
        
    }
    else
    {
       first = first->next;
        free(pred);
        return first; 
    }
            }
            break;
        case COMMAND:
        
            if (pred->command==entry)
            {
              if (za != NULL)
    {
       za->next = pred->next;
        free(pred);
        return first;
        
    }
    else
    {
       first = first->next;
        free(pred);
        return first; 
    }
            }
            break;
        case TEXT:
            
            if (pred->text==entry)
            {
              if (za != NULL)
    {
       za->next = pred->next;
        free(pred);
        return first;
        
    }
    else
    {
       first = first->next;
        free(pred);
        return first; 
    }
            }
            break;
        }}
        za=pred;
        pred=pred->next;
   

    return first;
        }
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
                   
                        new->text = entry;
    

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
                free(first);
            }
            break;
            case ITEM:
            if (first->type==ITEM && first->item!=NULL)
            {
                destroy_item(first->item);
                free(first);
            }
            case COMMAND:
            if (first->type==COMMAND && first->command!=NULL)
            {
                destroy_command(first->command);
                free(first);
            }
            case TEXT:
            if (first->type==TEXT && first->text!=NULL)
            {
                
                free(first);
                
            }
            
        }
        destroy_containers(new);
        
    }
    
    return NULL;
}
int strcicmp(const char *first, const char *second){
	if(first == NULL || second == NULL) 
    return -1;
	int compare = 0;
    		compare = tolower((unsigned int)*first) - tolower((unsigned int)*second);			
	if(compare==0)
	return compare;
    else 
    return 1;
}


void* get_from_container_by_name(struct container *first, const char *name){
if(name == NULL ||first==NULL ||strlen(name)==0){ 
    return NULL;
}

switch (first->type){    



case ROOM:
    for(int i=0;i<50;i++){
    if(strcicmp(first->room->name,name)==0)
    return first;
    else
    first=first->next;}
    break;
case ITEM:
for(int i=0;i<50;i++){
    if(strcicmp(first->item->name,name)==0)
    return first;
    else
    first=first->next;}
    break;
case COMMAND:
for(int i=0;i<50;i++){
    if(strcicmp(first->command->name,name)==0)
    return first;
    else
    first=first->next;}
    break;
case TEXT:
for(int i=0;i<50;i++){
    if(strcicmp(first->text,name)==0)
    return first;
    else
    first=first->next;}
    break;
}


return NULL;
}