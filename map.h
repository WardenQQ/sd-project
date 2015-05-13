#pragma once

#include "genotype.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HEIGHT 600
#define LENGTH 600
#define MAX_BLOCKS_NBR 10
#define MAX_GOALS_NBR 10
#define MAX_RADIUS 100
#define MIN_RADIUS 15

typedef enum {
    NONE,
    BLOCK,
    GOAL
} object_type;

typedef struct {
    int x;
    int y;
    int radius;
    int type;
} map_object_t;

typedef struct {
    map_object_t blocks[MAX_BLOCKS_NBR];
    int nb_blocks;
    map_object_t goals[MAX_GOALS_NBR];
    int nb_goals;
    map_object_t start_pos;
} map_t;

void random_map(map_t *out, int nbr_of_block, int nbr_of_goals);

int is_not_enough_space(map_t *map, map_object_t obj);
int collides_with(map_object_t obj1, map_object_t obj2);
int compute_distance(map_object_t obj1, map_object_t obj2);

map_object_t compute_position(map_object_t pos, int dir);

void evaluate(genotype_t *genotype, map_t *map);

int evaluate_gene(gene_t g, map_object_t *pos, map_t *map);

int in_boundary(map_t * map, map_object_t pos);
/* 
void print_map(map_t *out);

void print_walk(map_t map, genotype_t adn);
*/

#ifdef __cplusplus
}
#endif
