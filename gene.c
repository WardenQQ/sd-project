#include "gene.h"

int rand();

gene_t random_gene()
{
    gene_t g;

    g.direction = rand() % 8;
    g.step = MIN_STEP + rand() % (MAX_STEP - MIN_STEP + 1);

    return g;
}
