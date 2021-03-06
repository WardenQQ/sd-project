#include <stdio.h>
#include <math.h>
#include <float.h>

#include "map.h"

#ifdef __cplusplus
extern "C" {
#endif

int rand();

void random_map(map_t *out)
{
    int i;
    int blocks = out->nb_blocks;
    int goals = out->nb_goals;
    out->nb_blocks = 0;
    out->nb_goals = 0;
    for (i = 0; i < blocks; i++) {
        do {
            out->blocks[i].radius = rand() % (out->max_radius - out->min_radius + 1) + out->min_radius;
            out->blocks[i].x = out->blocks[i].radius + rand() % (out->width - 2 * out->blocks[i].radius);
            out->blocks[i].y = out->blocks[i].radius + rand() % (out->height - 2 * out->blocks[i].radius);
        } while (is_not_enough_space(out, out->blocks[i]));
        (out->nb_blocks)++;
    }

    for (i = 0; i < goals; i++) {
        do {
            out->goals[i].radius = rand() % (out->max_radius - out->min_radius + 1) + out->min_radius;
            out->goals[i].x = out->goals[i].radius + rand() % (out->width - 2 * out->goals[i].radius);
            out->goals[i].y = out->goals[i].radius + rand() % (out->height - 2 * out->goals[i].radius);
        } while (is_not_enough_space(out, out->goals[i]));
        (out->nb_goals)++;
    }

    do {
        out->start_pos.radius = out->min_radius;
        out->start_pos.x = out->start_pos.radius + rand() % (out->width - 2 * out->start_pos.radius);
        out->start_pos.y = out->start_pos.radius + rand() % (out->height - 2 * out->start_pos.radius);
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

int in_boundary(map_t * map, map_object_t pos)
{
    return pos.x >= pos.radius && pos.x < map->width - pos.radius && pos.y >= pos.radius && pos.y < map->height-pos.radius;
}

collision_info_t look(map_t *map, unsigned long reached_goals, map_object_t pos)
{
    int i;
    collision_info_t info;
    info.block = 0;
    info.goal = 0;
    info.nb_goals = 0;

    if (!in_boundary(map, pos)) {
        info.block = 1;
        return info;
    }

    for (i = 0; i < map->nb_blocks; i++) {
        if (collides_with(pos, map->blocks[i])) {
            info.block = 1;
            return info;
        }
    }

    for (i = 0; i < map->nb_goals; i++) {
        if (((reached_goals >> i) & 1) == 0 && collides_with(pos, map->goals[i])) {
            info.goal |= 1 << i;
            info.nb_goals++;
        }
    }

    return info;
}

map_object_t step_once(map_object_t pos, int dir)
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

double closest_objective(map_t *map, unsigned long reached_goals, map_object_t pos)
{
    double mindist = DBL_MAX;
    int i;

    for (i = 0; i < map->nb_goals; i++) {
        if (((reached_goals >> i) & 1) == 0 && squared_distance(pos, map->goals[i]) < mindist) {
            mindist = squared_distance(pos, map->goals[i]);
        }
            
    }

    return mindist;
}


void evaluate(genotype_t *genotype, map_t *map)
{
    int i, j;
    unsigned long reached_goals = 0;
    int remaining_goals = map->nb_goals;
    double map_diagonal_dist = (map->width * map->width + map->height * map->height);
    collision_info_t collision;
    map_object_t pos = map->start_pos,
                 new_pos;
    double closest = closest_objective(map, reached_goals, pos),
           new_closest;
    int dist = 0,
        maxdist = GENOTYPE_SIZE * map->max_step;
    genotype->fitness = 0;

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        for (j =0; j < genotype->genes[i].step; j++) {
            new_pos = step_once(pos, genotype->genes[i].direction);
            collision = look(map, reached_goals, pos);
            // si la direction est diagonale, le pas compte plus
            dist += 1 + (genotype->genes[i].direction % 2)*(1-(1/sqrt(2)));
            if (!(collision.block)) {
                pos = new_pos;
                if (collision.nb_goals) {
                    genotype->fitness += collision.nb_goals * pow(2, remaining_goals) * (1 + (double)(maxdist - dist) / maxdist);
                    remaining_goals--;
                    reached_goals |= collision.goal;
                }
            }
        }
    }
    if (remaining_goals != 0) {
        closest = closest_objective(map, reached_goals, pos);
        genotype->fitness += (map_diagonal_dist - closest) / (map_diagonal_dist);
    }
}



#ifdef __cplusplus
}
#endif
