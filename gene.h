#pragma once

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

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

gene_t random_gene(int min_step, int max_step);

#ifdef __cplusplus
}
#endif
