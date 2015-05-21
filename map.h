#pragma once

#include "genotype.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_BLOCKS_NBR 16
#define MAX_GOALS_NBR 16

typedef struct {
    int x;
    int y;
    int radius;
    int type;
} map_object_t;

typedef struct {
    int width;
    int height;
    map_object_t blocks[MAX_BLOCKS_NBR];
    int nb_blocks;
    map_object_t goals[MAX_GOALS_NBR];
    int nb_goals;
    map_object_t start_pos;
    int min_step;
    int max_step;
    int min_radius;
    int max_radius;
    
    int mutation_prob;
    int nb_children;
    int migration_freq;
} map_t;

typedef struct collision_info {
    int block;
    int nb_goals;
    unsigned long goal;
} collision_info_t;

void random_map(map_t *out);

int is_not_enough_space(map_t *map, map_object_t obj);

int collides_with(map_object_t obj1, map_object_t obj2);

double squared_distance(map_object_t obj1, map_object_t obj2);

void evaluate(genotype_t *genotype, map_t *map);

int in_boundary(map_t * map, map_object_t pos);

map_object_t step_once(map_object_t pos, int dir);

double closest_objective(map_t *map, unsigned long reached_goals, map_object_t pos);

collision_info_t look(map_t *map, unsigned long reached_goals, map_object_t pos);

#ifdef __cplusplus
}
#endif
