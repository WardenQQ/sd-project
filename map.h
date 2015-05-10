#pragma once

#include "gene.h"

#define HEIGHT 20
#define LENGTH 20

enum {
    NORMAL = 0,
    BLOCK = 1,
    START = 7,
    GOAL = 10,
};

typedef struct {
    int x;
    int y;
} coord_t;

typedef struct {
    int tab[HEIGHT][LENGTH];
    coord_t start;
    int max_score;
} map_t;

void init_map(map_t *out, int nbr_of_block, int nbr_of_goals);

void print_map(map_t *out);

coord_t move(map_t *map, coord_t pos, int direction);
