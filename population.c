#include "population.h"

#include <stdlib.h>

void init_population(population_t *out)
{
    int i;

    out->size = REDUCED_POPULATION_SIZE;
    for (i = 0; i < REDUCED_POPULATION_SIZE; i++) {
        random_genotype(&(out->genotypes[i]));
        evaluate(&(out->genotypes[i]));
    }

    qsort(out->genotypes, REDUCED_POPULATION_SIZE, sizeof(*(out->genotypes)), compare_genotype);
}

void add_to_population(population_t *pop, genotype_t *genotype)
{
    if (pop->size < MAX_POPULATION_SIZE) {
        pop->genotypes[pop->size] = *genotype;
        pop->size++;
    }
}

void reduce_population(population_t *in_out)
{
    qsort(in_out->genotypes, in_out->size, sizeof(*(in_out->genotypes)), compare_genotype);
    in_out->size = REDUCED_POPULATION_SIZE;
}

void tournament_select(genotype_t *parent1, genotype_t *parent2, population_t *pop, int tournament_size)
{
    int i;
    int first = 0, second = 0;

    for (i = 0; i < tournament_size && i < MAX_TOURNAMENT_SIZE; i++) {
        if (pop->genotypes[rand() % REDUCED_POPULATION_SIZE].fitness > pop->genotypes[first].fitness) {
            second = first;
            first = i;
        }
    }

    *parent1 = pop->genotypes[first];
    *parent2 = pop->genotypes[second];
}
