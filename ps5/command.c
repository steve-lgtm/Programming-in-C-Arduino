#include "command.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include<regex.h>

struct command* create_command(char* name, char* description, char* pattern, size_t nmatch){
    if (name==NULL ||description==NULL||strlen(name)==0||strlen(description)==0)
    return NULL;
    struct command* new=calloc(1,sizeof(struct command));
    char *meno=calloc(strlen(name)+10,sizeof(char*));
    char *opis=calloc(strlen(description)+10,sizeof(char*));


    strcpy(meno,name);
strcpy(opis,description);

new->name=meno;
new->description=opis;
//regex? try #include <regex.h> int regcomp(regex_t *preg, const char *pattern, int cflags);
if (pattern==NULL){}
else{
regex_t comp;
regcomp(&comp, pattern, 0);
new->preg = comp;}
new->nmatch=nmatch;

return new;
}

struct command* destroy_command(struct command* command){
    if(command==NULL)
    return NULL;
    free(command->name);
    free(command->description);
   
    free(command);
    return NULL;
}