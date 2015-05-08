#include "genotype.h"

void random_genotype(genotype_t *out)
{
    int i;

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        out->genes[i] = random_gene();
    }
}

void evaluate(genotype_t *genotype)
{
    int i;

    genotype->fitness = 0;
    for (i = 0; i < GENOTYPE_SIZE; i++) {
        genotype->fitness += genotype->genes[i].step;
    }
}
