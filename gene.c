#include "gene.h"

#ifdef __cplusplus
extern "C" {
#endif

int rand();

gene_t random_gene(int min_step, int max_step)
{
    gene_t g;

    g.direction = rand() % 8;
    g.step = min_step + rand() % (max_step - min_step + 1);

    return g;
}

#ifdef __cplusplus
}
#endif
