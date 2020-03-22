#include <stdlib.h>
#include <stdio.h>
#include "hof.h"

//bool save(const struct player list[], const int size){

//}

int load(struct player list[]){
FILE *file =fopen(HOF_FILE,"r");
 if(file == NULL){
        printf("Error open file.\n");
        fclose(file);
        return -1;
}

int i=0;
int b=fscanf(file,"%s %d\n",list[i].name, &list[i].score);
 if (b==EOF)
    {
         fclose(file);
        return -1;
    }
 
for(i=1;i<10;i++){
    b=fscanf(file,"%s %d\n",list[i].name, &list[i].score);
    
    
    if (b==EOF)
    {
        
        break;
    }
}
    fclose(file);
    return i;
}