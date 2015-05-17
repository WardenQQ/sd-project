#include <stdio.h>
#include <math.h>
#include <float.h>

#include "map.h"

#ifdef __cplusplus
extern "C" {
#endif

int rand();

void random_map(map_t *out, int width, int height, int nbr_of_blocks, int nbr_of_goals, int min_step, int max_step, int min_radius, int max_radius, int mutation_prob, int nb_children, int migration_freq)
{
    int i;
    out->nb_blocks = 0;
    out->nb_goals = 0;
    out->width = width;
    out->height = height;
    out->min_step = min_step;
    out->max_step = max_step;
    out->min_radius = min_radius;
    out->max_radius = max_radius;
    
    out->mutation_prob = mutation_prob;
    out->nb_children = nb_children;
    out->migration_freq = migration_freq;

	for (i = 0; i < nbr_of_blocks; i++) {
        do {
            out->blocks[i].radius = rand() % (max_radius - min_radius + 1) + min_radius;
            out->blocks[i].x = out->blocks[i].radius + rand() % (width - 2 * out->blocks[i].radius);
            out->blocks[i].y = out->blocks[i].radius + rand() % (height - 2 * out->blocks[i].radius);
        } while (is_not_enough_space(out, out->blocks[i]));
		out->nb_blocks++;
	}

	for (i = 0; i < nbr_of_goals; i++) {
		do {
            out->goals[i].radius = rand() % (max_radius - min_radius + 1) + min_radius;
            out->goals[i].x = out->goals[i].radius + rand() % (width - 2 * out->goals[i].radius);
            out->goals[i].y = out->goals[i].radius + rand() % (height - 2 * out->goals[i].radius);
		} while (is_not_enough_space(out, out->goals[i]));
		out->nb_goals++;
	}

	do {
        out->start_pos.radius = min_radius;
        out->start_pos.x = out->start_pos.radius + rand() % (width - 2 * out->start_pos.radius);
        out->start_pos.y = out->start_pos.radius + rand() % (height - 2 * out->start_pos.radius);
	} while (is_not_enough_space(out, out->start_pos));
}

int is_not_enough_space(map_t *map, map_object_t obj)
{
	int res = 0;
	int i;
	for (i=0; i<map->nb_blocks; i++)
		res = res | collides_with(map->blocks[i], obj);
	for (i=0; i<map->nb_goals; i++)
		res = res | collides_with(map->goals[i], obj);
	return res;
}

int collides_with(map_object_t obj1, map_object_t obj2)
{
    return squared_distance(obj1, obj2) < (obj1.radius + obj2.radius) * (obj1.radius + obj2.radius);
}

double squared_distance(map_object_t obj1, map_object_t obj2)
{
    return (obj1.x - obj2.x) * (obj1.x - obj2.x) + (obj1.y - obj2.y) * (obj1.y - obj2.y);
}

map_object_t compute_position(map_object_t pos, int dir)
{
    map_object_t res = pos;

    if (NORTH_EAST <= dir && dir <= SOUTH_EAST)
        res.x+=1;

    if (SOUTH_EAST <= dir && dir <= SOUTH_WEST )
        res.y+=1;

    if (SOUTH_WEST <= dir && dir <= NORTH_WEST )
        res.x-=1;

    if (dir == NORTH_WEST || dir == NORTH || dir == NORTH_EAST)
        res.y-=1;

    return res;
}

int evaluate_gene(gene_t g, map_object_t *pos, map_t *map, unsigned long *reached_goals)
{
    map_object_t new_pos;
    int fitness = 0, i, j;

    for (i = 0; i < g.step; i++) {
        new_pos = compute_position(*pos, g.direction);

        if (!in_boundary(map, new_pos)) {
            return fitness;
        } 

        /* We first iterate over obstacles */
        for (j = 0; j < map->nb_blocks; j++) {
            if (collides_with(new_pos, map->blocks[j])) {
                return fitness;
            }
        }

        /* then over objectives. */
        for (j = 0;j < map->nb_goals; j++) {
            if (!((*reached_goals >> j) & 1) && collides_with(new_pos, map->goals[j])) {
                fitness += (MAX_RADIUS - new_pos.radius) / (MAX_RADIUS - MIN_RADIUS);
                *reached_goals |= 1 << j;
            }
        }

        *pos = new_pos;
    }

    return fitness;
}

void evaluate(genotype_t *genotype, map_t *map)
{
    int i;
    map_object_t pos = map->start_pos;
    unsigned long reached_goals = 0;

    genotype->fitness = 0;
    for (i = 0; i < GENOTYPE_SIZE; i++) {
        genotype->fitness += evaluate_gene(genotype->genes[i], &pos, map, &reached_goals);
    }

    if (pow(2, map->nb_goals) - 1 == reached_goals) {
        double sum;
        for (i = 0; i < GENOTYPE_SIZE; i++) {
            sum += genotype->genes[i].step;
        }
        genotype->fitness += (GENOTYPE_SIZE * MAX_STEP - sum) / (GENOTYPE_SIZE * MAX_STEP - GENOTYPE_SIZE * MIN_STEP);
    } else {
        double maxdist = LENGTH * LENGTH + HEIGHT * HEIGHT;
        double mindist = maxdist;

        for (i = 0; i < map->nb_goals; i++) {
            if (!((reached_goals >> i) & 1)) {
                double dist = squared_distance(pos, map->goals[i]);
                mindist = dist < mindist ? dist : mindist;
            }
        }

        genotype->fitness += (maxdist - mindist) / maxdist;
    }
}

int in_boundary(map_t * map, map_object_t pos)
{
    return pos.x >= pos.radius && pos.x < map->width - pos.radius && pos.y >= pos.radius && pos.y < map->height-pos.radius;
}


#ifdef __cplusplus
}
#endif
