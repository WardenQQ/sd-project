#pragma once

#include "map.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_POPULATION_SIZE 200
#define REDUCED_POPULATION_SIZE 100
#define MIGRATION_FREQUENCY 5

typedef struct {
    genotype_t genotypes[MAX_POPULATION_SIZE];
    int size;
} population_t;

genotype_t genetic_algorithm(int nb_iterations, int nb_children, map_t *map, int vers);

void init_population(population_t *out, map_t *map);

void add_to_population(population_t *pop, genotype_t *genotype);

void reduce_population(population_t *in_out);

void tournament_select(genotype_t *parent1, genotype_t *parent2, population_t *pop, int tournament_size);

void emigrate(population_t *pop, int vers);

void immigrate(population_t *out, int vers);


#ifdef __cplusplus
}
#endif
