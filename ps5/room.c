#include "room.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>



struct room* create_room(char *name, char *description){
    if (name==NULL ||description==NULL||strlen(name)==0||strlen(description)==0)
    return NULL;
    struct room* new=calloc(1,sizeof(struct room));
    char *meno=calloc(strlen(name)+10,sizeof(char*));
    char *opis=calloc(strlen(description)+10,sizeof(char*));
    strcpy(meno,name);
strcpy(opis,description);
new->name=meno;
new->description=opis;

return new;

}

struct room* destroy_room(struct room* room){
    if(room==NULL)
    return NULL;
    free(room->name);
    free(room->description);
    free(room);
    return NULL;
}

void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west){
    if (room==NULL){

    }
    else{
    if (room!=north)
    room->north=north;
    if (room!=south)
    room->south=south;
    if (room!=east)
    room->east=east;
    if (room!=west)
    room->west=west;
}}
void show_room(const struct room* room){
printf("%s %s",room->name, room->description);
}
void delete_item_from_room(struct room* room, struct item* item){
if(item==NULL && room==NULL)
	return;
    remove_container(room->items, item);
}
void add_item_to_room(struct room* room, struct item* item){
       if(item==NULL || room==NULL)
       return;
        struct container* add = create_container(room->items, ITEM, item);
    if(room->items!=NULL){
    }
    else{
   room->items = add;}
    
}
struct item* get_item_from_room(const struct room* room, const char* name){
if(room== NULL || name == NULL||strlen(name)==0) 
return NULL;
return get_from_container_by_name(room->items,name);
}

