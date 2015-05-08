#pragma once

#define MIN_STEP 0
#define MAX_STEP 16

enum {
    NORTH = 0,
    NORTH_EAST = 1,
    EAST = 2,
    SOUTH_EAST = 3,
    SOUTH = 4,
    SOUTH_WEST = 5,
    WEST = 6,
    NORTH_WEST = 7
};

typedef struct {
    int step;
    int direction;
} gene_t;

gene_t random_gene();
