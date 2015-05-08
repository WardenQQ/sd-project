#pragma once

#define HEIGHT 6
#define LENGTH 6

enum {
    NORMAL = 0,
    BLOCK = 1,
    GOAL = 2,
    INIT = 3
};

typedef struct {
    int tab[HEIGHT][LENGTH];
} map_t;

void init_map(map_t *out, int nbr_of_block, int nbr_of_goals);

void print_map(map_t *out);