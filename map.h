#pragma once

#include "gene.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HEIGHT 600
#define LENGTH 600
#define MAX_BLOCKS_NBR 10
#define MAX_GOALS_NBR 10
#define MAX_BLOCK_RADIUS 100
#define MIN_GOAL_RADIUS 15

enum {
    NORMAL = 0,
    BLOCK = 1,
    START = 7,
    GOAL = 10,
};

typedef struct {
    int x;
    int y;
    int radius;
} circle_t;

typedef struct {
    circle_t blocks[MAX_BLOCKS_NBR];
    int nbr_of_blocks;

    circle_t goals[MAX_GOALS_NBR];
    int nbr_of_goals;

    circle_t start_pos;
} map_t;

void random_map(map_t *out, int nbr_of_block, int nbr_of_goals);

int is_not_enough_space(map_t *map, circle_t obj);
int is_collision(circle_t obj1, circle_t obj2);
int compute_distance(circle_t obj1, circle_t obj2);

circle_t move(map_t *map, circle_t pos, gene_t gene);

/*
void print_map(map_t *out);

void print_walk(map_t map, genotype_t adn);
*/

#ifdef __cplusplus
}
#endif
