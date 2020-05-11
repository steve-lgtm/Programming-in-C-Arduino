#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct item* create_item(char* name, char* description, unsigned int properties){
    if (name==NULL ||description==NULL||strlen(name)==0||strlen(description)==0)
    return NULL;
    struct item* new=calloc(1,sizeof(struct item));
    char *meno=calloc(strlen(name)+10,sizeof(char*));
    char *opis=calloc(strlen(description)+10,sizeof(char*));
    strcpy(meno,name);
strcpy(opis,description);
new->name=meno;
new->description=opis;
new->properties=properties;

return new;
}

struct item* destroy_item(struct item* item){
   if(item==NULL){
    return NULL;}
    free(item->name);
    free(item->description);
    free(item);
    return NULL;
}