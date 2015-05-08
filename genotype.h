#pragma once

#include "gene.h"

#define GENOTYPE_SIZE 100
#define MAX_TOURNAMENT_SIZE 50

typedef struct {
    gene_t genes[GENOTYPE_SIZE];
    double fitness;
} genotype_t;

void random_genotype(genotype_t *out);

void evaluate(genotype_t *genotype);

void crossover(genotype_t *out, genotype_t *parent1, genotype_t *parent2);
