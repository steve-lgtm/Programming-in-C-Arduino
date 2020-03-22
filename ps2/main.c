#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "k.h"
#include "hof.h"
#include "ui.h"

int main(int argc, char const *argv[])
{
		struct game game = {
    .board = {
        {'C', 'I', 'F', 'I'},
	{'H', 'B', 'D', 'C'},
	{'C', 'I', 'E', 'A'},
	{'I', 'B', 'F', 'H'}
    },
    .score = 0
};

update(&game, 0, 1);
//add_random_tile(&game);
for (int i = 0; i < SIZE; ++i)
{
	printf("|");
	for (int j = 0; j < SIZE; ++j)
	{
		printf("%c|", game.board[i][j]);
	}
	printf("\n");
}

printf("\n");
render(game);
printf("is won %d\n", is_game_won(game));

printf("is move possible %d\n", is_move_possible(game));
if (is_move_possible(game)==true)
add_random_tile(&game);
struct player *list=calloc(sizeof(struct player)*10,sizeof(struct player*));

printf("%d\n", load(list));
//printf("%d\n", save(list,10));



free(list);
	return 0;
}
