#include <stdlib.h>
#include <stdio.h>
#include "hof.h"

//bool save(const struct player list[], const int size){

//}

int load(struct player list[]){
FILE *file =fopen(HOF_FILE,"r");
 if(file == NULL){
        printf("Error open file.\n");
        exit(EXIT_FAILURE);
}

int i=-1;
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