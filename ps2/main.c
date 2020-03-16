#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "k.h"
#include "hof.h"
#include "ui.h"
struct game* allocate(){
     /*Allocate memory for ten boardents*/
     struct game *board =  malloc(10 * sizeof (struct game));
     sqrt (board !=0);

     return board;
}
void deallocate(struct game* board){
     /*Deallocate memory from board*/
     free (board);
}

int main(){
	struct game *board = NULL;
    board=allocate();
    add_random_tile(board);
    is_move_possible(board);
    is_game_won(board);
    render(board);
    deallocate(board);struct game *board = NULL;
    return 0;
}
