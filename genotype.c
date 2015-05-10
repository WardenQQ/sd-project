#include "genotype.h"
#include <math.h>

int rand();

int compare_genotype(const void *genotype1, const void *genotype2)
{
    const genotype_t *g1 = genotype1;
    const genotype_t *g2 = genotype2;

    if (g1->fitness < g2->fitness) {
        return 1;
    } else if (g1->fitness > g2->fitness) {
        return -1;
    } else {
        return 0;
    }
}

void random_genotype(genotype_t *out)
{
    int i;

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        out->genes[i] = random_gene();
    }
}

void evaluate(genotype_t *genotype, map_t *map)
{
    int i, map_type, goal_val;
    genotype->fitness = 0;
    coord_t pos = map->start;

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        pos = move(map, pos, genotype->genes[i].direction);
        map_type = map->tab[pos.y][pos.x];
        if (map_type > GOAL) {
            goal_val = (int) pow(2, (map_type - GOAL));
            /* A goal is counted only once. */
            genotype->fitness += goal_val - ((int)genotype->fitness & goal_val);
            if (genotype->fitness == map->max_score)
                break;
        }
    }
    genotype->fitness *= GENOTYPE_SIZE;

    /* If all goals have not been reached */
    if (i == GENOTYPE_SIZE)
        genotype->fitness += sqrt( pow((pos.x - map->start.x),2) + pow((pos.y - map->start.y), 2) );
    else
        genotype->fitness += GENOTYPE_SIZE - i;

    /*
    for (i = 0; i < GENOTYPE_SIZE; i++) {
        genotype->fitness += genotype->genes[i].step;
    }
    */
}

void crossover(genotype_t *out, genotype_t *parent1, genotype_t *parent2)
{
    int i = 0;
    int cutpoint;

    /*
     * We want to have the cutpoint in [1;MAX_GENES-1] so that the crossover
     * always includes parent1 and parent2 genes.
    */
    cutpoint = rand() % (GENOTYPE_SIZE - 1) + 1;

    for (i = 0; i < cutpoint; i++) {
        out->genes[i] = parent1->genes[i];
    }
    for (i = cutpoint; i < GENOTYPE_SIZE; i++) {
        out->genes[i] = parent2->genes[i];
    }
}

void mutate(genotype_t *in_out, int probability)
{
    int p, i;

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        p = rand() % MAX_PROBABILITY;

        if (p < probability) {
            in_out->genes[i] = random_gene();
        }
    }
}
