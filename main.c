#define MAX_ITERATION 10000
#define MAX_CHILDREN 50

#include <stdio.h>

#include "population.h"

int main()
{
    int i, j;
    population_t pop;
    genotype_t parent1, parent2, child;

    init_population(&pop);

    /* TOP TEN */
    for (i = 0; i < 10; i++) {
        printf("Top ten\n");
        printf("%d: fitness %g\n", i, pop.genotypes[i].fitness);
    }

    for (i = 0; pop.genotypes[0].fitness != 1600; i++) {
        for (j = 0; j < MAX_CHILDREN; j++) {
            tournament_select(&parent1, &parent2, &pop, 5);
            crossover(&child, &parent1, &parent2);
            mutate(&child, 10);
            evaluate(&child);
            add_to_population(&pop, &child);
            reduce_population(&pop);
        }
        printf("Generation %d!!first: %g, second %g\n", i, pop.genotypes[0].fitness, pop.genotypes[1].fitness);
    }

    printf("Ended at generation %d!!\n", i);

    /* TOP TEN */
    for (i = 0; i < 10; i++) {
        printf("Top ten\n");
        printf("%d: fitness %g\n", i, pop.genotypes[i].fitness);
    }

    return 0;
}
