#pragma once

#include "gene.h"

#ifdef __cplusplus
extern "C" {
#endif


#define GENOTYPE_SIZE 100
#define MAX_TOURNAMENT_SIZE 50
#define MAX_PROBABILITY 1000

typedef struct {
    gene_t genes[GENOTYPE_SIZE];
    double fitness;
} genotype_t;

int compare_genotype(const void *g1, const void *g2);

void random_genotype(genotype_t *out);

void crossover(genotype_t *out, genotype_t *parent1, genotype_t *parent2);

void mutate(genotype_t *in_out, int probability);

#ifdef __cplusplus
}
#endif
