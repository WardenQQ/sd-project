#include "population.h"

void init_population(population_t *out)
{
    int i;

    out->size = REDUCED_POPULATION_SIZE;
    for (i = 0; i < out->size; i++) {
        random_genotype(&(out->genotypes[i]));
        evaluate(&(out->genotypes[i]));
    }
}
