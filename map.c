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

    int i, j, dice, nbr_of_init = 1;
    out->max_score = (int) pow(2, nbr_of_goals+1) - 1;
    for (i = 0; i < HEIGHT; i++)
    	for (j = 0; j < LENGTH; j++) {
    		dice = rand() % (HEIGHT*LENGTH - (i*LENGTH + j) );
    		if (dice < nbr_of_init) {
    			out->tab[i][j] = START;
                out->start.x = j;
                out->start.y = i;
    			nbr_of_init--;
    		}
    		else if (dice < nbr_of_init + nbr_of_goals) {
    			out->tab[i][j] = GOAL + nbr_of_goals;
    			nbr_of_goals--;
    		}
    		else if (dice < nbr_of_init + nbr_of_goals + nbr_of_blocks) {
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
    printf("\nCarte de taille (%dx%d), depart en (%d, %d) : \n", HEIGHT, LENGTH, out->start.x, out->start.y);
	int i,j, val;
    for (i = 0; i < HEIGHT; i++) {
    	for (j = 0; j < LENGTH; j++) {
            val = out->tab[i][j];
            val > 9 ? printf("%d ", val) : printf(" %d ", val);
    	}
    	printf("\n");
    }
}

coord_t move(map_t *map, coord_t pos, int direction)
{
    /*
     * We assume that moving toward an edge of
     * the map doesn't change the position
     */

    coord_t res = pos;
    if (NORTH_EAST <= direction && direction <= SOUTH_EAST)
        res.x++;

    if (SOUTH_EAST <= direction && direction <= SOUTH_WEST )
        res.y++;

    if (SOUTH_WEST <= direction && direction <= NORTH_WEST )
        res.x--;

    if (direction == NORTH_WEST || direction == NORTH || direction == NORTH_EAST)
        res.y--;

    if (res.x < HEIGHT-1 || res.y < LENGTH-1 || res.x > 0 || res.y > 0)
        res = pos;

    return res;
}
