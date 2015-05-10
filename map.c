#include <stdio.h>
#include <math.h>

#include "map.h"

int rand();

void init_map(map_t *out, int nbr_of_blocks, int nbr_of_goals)
{
	if (nbr_of_blocks + nbr_of_goals + 1 >= HEIGHT*LENGTH
		|| nbr_of_goals < 1)
	{
		fprintf(stderr, "Invalid parameters for map creation. Blocks : %d, goals : %d, size : %dx%d\n",
		 nbr_of_blocks, nbr_of_goals, HEIGHT, LENGTH);
		return;
	}

	int i, dice, nbr_of_init = 1;
	out->max_score = (int) pow(2, nbr_of_goals+1) - 1;
	for (i = 0; i < HEIGHT*LENGTH; i++) {
		dice = rand() % (HEIGHT*LENGTH - i );
		if (dice < nbr_of_init) {
			printf("start_pos = %d\n", i);
			out->tab[i] = START;
			out->start_pos = i;
			nbr_of_init--;
		}
		else if (dice < nbr_of_init + nbr_of_goals) {
			out->tab[i] = GOAL + nbr_of_goals;
			nbr_of_goals--;
		}
		else if (dice < nbr_of_init + nbr_of_goals + nbr_of_blocks) {
			out->tab[i] = BLOCK;
			nbr_of_blocks--;
		}
		else {
			out->tab[i] = NORMAL;
		}
	}
}

void print_map(map_t *out)
{
	printf("\nCarte de taille (%dx%d), depart en (%d, %d) : \n", HEIGHT, LENGTH, out->start_pos%LENGTH, out->start_pos/LENGTH);
	int i,j, val;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < LENGTH; j++) {
			val = out->tab[i*LENGTH + j];
			val > 9 ? printf("%d ", val) : printf(" %d ", val);
		}
		printf("\n");
	}
}

int move(map_t *map, int pos, int direction)
{
	/*
	 * We assume that moving toward an edge of
	 * the map doesn't change the position
	 */

	int res = pos, wrong_move = 0;
	if (NORTH_EAST <= direction && direction <= SOUTH_EAST) {
		if (pos%LENGTH == LENGTH-1)
			wrong_move = 1;
		else
			res++;
	}

	if (SOUTH_EAST <= direction && direction <= SOUTH_WEST ) {
		if (pos/LENGTH == HEIGHT-1)
			wrong_move = 1;
		else
			res+=LENGTH;
	}

	if (SOUTH_WEST <= direction && direction <= NORTH_WEST ) {
		if (pos%LENGTH == 0)
			wrong_move = 1;
		else
			res--;
	}

	if (direction == NORTH_WEST || direction == NORTH || direction == NORTH_EAST) {
		if (pos/LENGTH == 0)
			wrong_move = 1;
		else
			res-=LENGTH;
	}

	if (wrong_move == 1)
		res = pos;

	return res;
}
