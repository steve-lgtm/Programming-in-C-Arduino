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
    struct container *new=first;
   
    
    switch (first->type){
    
        
        
        case ROOM:
            for(int i=0;i<100;i++){
            if (new->room==entry)
            {
                first=first->next;
                return first;
                i++;
            }}
            break;
        case ITEM:
        for(int i=0;i<100;i++){
            if (new->item==entry)
            {
                first=first->next;
                return first;
                i++;
            }}
            break;
        case COMMAND:
        for(int i=0;i<100;i++){
            if (new->command==entry)
            {
                first=first->next;
                return first;
                i++;
            }}
            break;
        case TEXT:
            for(int i=0;i<100;i++){
            if (new->text==entry)
            {
                first=first->next;
                return first;
                i++;
            }}
            break;
        }
        new=new->next;
    
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
                   text=calloc(100,1);     
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
                free(first->text);
                free(first);
                
            }
            
        }
        destroy_containers(new);
        
    }
    
    return NULL;
}
int strcicmp(const char *first, const char *second){
	if(first == NULL || second == NULL) return -1;
	int diff = 0;
	for(; diff == 0 && *first != '\0' ;++first, ++second){
		diff = tolower((unsigned int)*first) - tolower((unsigned int)*second);			
	}
	return diff;
}


void* get_from_container_by_name(struct container *first, const char *name){
if(name == NULL ||first==NULL){ 
    return NULL;
}
struct container *finded =first; 
switch (finded->type){    



case ROOM:
    for(int i=0;i<100;i++){
    if(strcicmp(finded->room->name,name)==0)
    return finded;
    else
    finded=finded->next;}
    break;
case ITEM:
for(int i=0;i<100;i++){
    if(strcicmp(finded->item->name,name)==0)
    return finded;
    else
    finded=finded->next;}
    break;
case COMMAND:
for(int i=0;i<100;i++){
    if(strcicmp(finded->command->name,name)==0)
    return finded;
    else
    finded=finded->next;}
    break;
case TEXT:
for(int i=0;i<100;i++){
    if(strcicmp(finded->text,name)==0)
    return finded;
    else
    finded=finded->next;}
    break;
}


return NULL;
}