#include <stdio.h>
#include <math.h>

#include "map.h"

#ifdef __cplusplus
extern "C" {
#endif

int rand();

void random_map(map_t *out, int nbr_of_blocks, int nbr_of_goals)
{
	if (nbr_of_blocks >= MAX_BLOCKS_NBR || nbr_of_goals >= MAX_GOALS_NBR)
	{
		fprintf(stderr, "Invalid parameters for map creation. Blocks: %d (MAX: %d), goals: %d (MAX: %d), size: %dx%d\n",
		 nbr_of_blocks, MAX_BLOCKS_NBR, nbr_of_goals, MAX_GOALS_NBR, HEIGHT, LENGTH);
		return;
	}

	int i;
	out->nbr_of_blocks = 0;
	out->nbr_of_goals = 0;

	for (i = 0; i < nbr_of_blocks; i++) {
		out->blocks[i].radius = rand() % MAX_BLOCK_RADIUS;
		out->blocks[i].x = out->blocks[i].radius + rand() % (LENGTH - 2 * out->blocks[i].radius);
		out->blocks[i].y = out->blocks[i].radius + rand() % (HEIGHT - 2 * out->blocks[i].radius);
		out->nbr_of_blocks++;
	}

	for (i = 0; i < nbr_of_goals; i++) {
		do {
			out->goals[i].radius = MIN_GOAL_RADIUS + nbr_of_goals-i;
			out->goals[i].x = out->goals[i].radius + rand() % (LENGTH - 2 * out->goals[i].radius);
			out->goals[i].y = out->goals[i].radius + rand() % (HEIGHT - 2 * out->goals[i].radius);
		} while (is_not_enough_space(out, out->goals[i]));
		out->nbr_of_goals++;
	}

	do {
        out->start_pos.radius = 10;
		out->start_pos.x = out->start_pos.radius + rand() % (LENGTH - 2 * out->start_pos.radius);
		out->start_pos.y = out->start_pos.radius + rand() % (HEIGHT - 2 * out->start_pos.radius);
	} while (is_not_enough_space(out, out->goals[i]));
}

int is_not_enough_space(map_t *map, circle_t obj)
{
	int res = 0;
	int i;
	for (i=0; i<map->nbr_of_blocks; i++)
		res = res | is_collision(map->blocks[i], obj);
	for (i=0; i<map->nbr_of_goals; i++)
		res = res | is_collision(map->goals[i], obj);
	return res;
}

int is_collision(circle_t obj1, circle_t obj2)
{
	if (compute_distance(obj1, obj2) < obj1.radius + obj2.radius)
		return 1;
	else
		return 0;
}

int compute_distance(circle_t obj1, circle_t obj2)
{
	return sqrt( pow((obj1.x - obj2.x),2) + pow((obj1.y - obj2.y), 2) );
}

circle_t move(map_t *map, circle_t pos, gene_t gene)
{
	circle_t res = pos;
	/*
	circle_t res = pos;

	if (NORTH_EAST <= gene.direction && gene.direction <= SOUTH_EAST) {
		if (pos%LENGTH == LENGTH-1)
			out_of_border = 1;
		else
			res++;
	}

	if (SOUTH_EAST <= gene.direction && gene.direction <= SOUTH_WEST ) {
		if (pos/LENGTH == HEIGHT-1)
			out_of_border = 1;
		else
			res+=LENGTH;
	}

	if (SOUTH_WEST <= gene.direction && gene.direction <= NORTH_WEST ) {
		if (pos%LENGTH == 0)
			out_of_border = 1;
		else
			res--;
	}

	if (gene.direction == NORTH_WEST || gene.direction == NORTH || gene.direction == NORTH_EAST) {
		if (pos/LENGTH == 0)
			out_of_border = 1;
		else
			res-=LENGTH;
	}

	if (out_of_border == 1 || map->tab[res] == BLOCK)
		res = pos;

	*/
	return res;
}

/*
void print_map(map_t *out)
{

}

void print_walk(map_t map, genotype_t adn)
{
	int i, new_pos, map_type;
	new_pos = map.start_pos;
	print_map(&map);

	for (i = 0; i < GENOTYPE_SIZE; i++)
	{
		printf("Press <ENTER> to continue...\n");
	    getchar();
	    new_pos = move(&map, new_pos, adn.genes[i].direction);
	    map_type = map.tab[new_pos];
	    map.tab[new_pos] = 7;
	    print_map(&map);
	    map.tab[new_pos] = map_type;
	}
}
*/

#ifdef __cplusplus
}
#endif
