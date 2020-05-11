#include "world.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


struct container* add_room_to_world(struct container* world, struct room* room){


    if (room == NULL || world==NULL)
    return NULL;
    
    if (get_room(world, room->name) != NULL)
                return NULL;
        
        return create_container(world, ROOM, room);
    
    
}



struct room* get_room(struct container* world, char* name){
	return get_from_container_by_name(world, name);
}
