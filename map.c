#include <stdio.h>

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

    int i, j, rnd, nbr_of_init = 1;
    for (i = 0; i < HEIGHT; i++)
    	for (j = 0; j < LENGTH; j++) {
    		rnd = rand() % (HEIGHT*LENGTH - (i*LENGTH + j) );
    		if (rnd < nbr_of_init) {
    			out->tab[i][j] = INIT;
    			nbr_of_init--;
    		}
    		else if (rnd < nbr_of_init + nbr_of_goals) {
    			out->tab[i][j] = GOAL;
    			nbr_of_goals--;
    		}
    		else if (rnd < nbr_of_init + nbr_of_goals + nbr_of_blocks) {
    			out->tab[i][j] = BLOCK;
    			nbr_of_blocks--;
    		}
    		else {
    			out->tab[i][j] = NORMAL;
    		}
    	}
}

void print_map(map_t *out)
{
    printf("\nVoici la carte, de taille %dx%d : \n", HEIGHT, LENGTH);
	int i,j;
    for (i = 0; i < HEIGHT; i++) {
    	for (j = 0; j < LENGTH; j++) {
    		printf("%d ", out->tab[i][j]);
    	}
    	printf("\n");
    }
}
