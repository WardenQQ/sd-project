#include "population.h"

int rand();

void init_population(population_t *out)
{
    int i;

    out->size = REDUCED_POPULATION_SIZE;
    for (i = 0; i < out->size; i++) {
        random_genotype(&(out->genotypes[i]));
        evaluate(&(out->genotypes[i]));
    }
}

void tournament_select(genotype_t *parent1, genotype_t *parent2, population_t *pop, int tournament_size)
{
    int i;
    int first, second;

    first = 0;
    for (i = 0; i < tournament_size && i < MAX_TOURNAMENT_SIZE; i++) {
        if (pop->genotypes[rand() % REDUCED_POPULATION_SIZE].fitness > pop->genotypes[first].fitness) {
            second = first;
            first = i;
        }
    }

    *parent1 = pop->genotypes[first];
    *parent2 = pop->genotypes[second];
}
