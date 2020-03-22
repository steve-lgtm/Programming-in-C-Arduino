#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "hof.h"
int cmp_by_score(const void* p1, const void* p2){
    struct player* player1 = (struct player*)p1;
    struct player* player2 = (struct player*)p2;

    int result = player2->score-player1->score;
    // printf("comparing %s vs %s = %d\n", person1->score, person2->score, result);
    return result;
}

//bool save(const struct player list[], const int size){

//}



int load(struct player list[]){
FILE *file =fopen(HOF_FILE,"r");
 if(file == NULL){
      
        
        return -1;
}
 else{
int i=0;
size_t size=0;

 
for(i=0;i<10;i++){
    int b=fscanf(file,"%s %d\n",list[i].name, &list[i].score);
    
    size++;
    if (b==EOF)
    {
        
        break;
    }
}



   qsort(list, size, sizeof(struct player), cmp_by_score);

    fclose(file);
    return i;}
}