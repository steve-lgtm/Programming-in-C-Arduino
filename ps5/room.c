#include "room.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct room* destroy_room(struct room* room){
    return 0;
}

struct room* create_room(char *name, char *description){
    struct room* new=calloc(1,sizeof(struct room));
    char *meno=calloc(strlen(name)+10,sizeof(char*));
    char *opis=calloc(strlen(description)+10,sizeof(char*));
    strcpy(meno,name);
strcpy(opis,description);
new->name=meno;
new->description=opis;

return new;

}