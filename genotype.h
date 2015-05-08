#pragma once

#include "gene.h"

#define GENOTYPE_SIZE 100

typedef struct {
    gene_t genes[GENOTYPE_SIZE];
    double fitness;
} genotype_t;

void random_genotype(genotype_t *out);

void evaluate(genotype_t *genotype);
