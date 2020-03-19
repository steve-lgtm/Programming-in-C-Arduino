#include <stdlib.h>
#include <stdio.h>
#include "hof.h"

int load(struct player list[]){
FILE *file =fopen(HOF_FILE,"br");
 if(file == NULL){
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
}

int i=0;
for(i=0;i<10;i++){
    int b=fscanf(file,"%s %d\n",list[i].name, &list[i].score);
    if (b==EOF)
    {
        break;
    }
}
    fclose(file);
    return i;
}