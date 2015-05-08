#pragma once

#include "genotype.h"

#define MAX_POPULATION_SIZE 200
#define REDUCED_POPULATION_SIZE 100

typedef struct {
    genotype_t genotypes[MAX_POPULATION_SIZE];
    int size;
} population_t;

void init_population(population_t *out);

void add_to_population(population_t *pop, genotype_t *genotype);

void reduce_population(population_t *in_out);

void tournament_select(genotype_t *parent1, genotype_t *parent2, population_t *pop, int tournament_size);
