#pragma once

#include "genotype.h"

#define MAX_POPULATION_SIZE 200
#define REDUCED_POPULATION_SIZE 100

typedef struct {
    genotype_t genotypes[MAX_POPULATION_SIZE];
    int size;
} population_t;

void init_population(population_t *out);
