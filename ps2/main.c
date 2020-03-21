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
        {'A', ' ', ' ', ' '},
        {'B', ' ', ' ', 'B'},
        {'C', 'C', 'C', ' '},
        {'D', 'D', 'D', 'D'}
    },
    .score = 0
};
bool result = update(&game, 0, 1);
add_random_tile(&game);
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
printf("result %d\n", result);
printf("is won %d\n", is_game_won(game));
printf("is move possible %d\n", is_move_possible(game));

struct player *list=malloc(sizeof(struct player)*10);
printf("%d\n", load(list));
//printf("%d\n", save(list,10));


free(list);
	return 0;
}
