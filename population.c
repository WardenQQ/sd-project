#include "population.h"
#include "procedures.h"
#include "types_xdr.h"

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


void genetic_algorithm(int nb_iterations, int nb_children, map_t *map, genotype_t *best, int vers)
{
    int i, j;
    population_t pop;
    genotype_t parent1, parent2, child;

    init_population(&pop, map);

    for (i = 0; i < nb_iterations; i++) {
        if (i % MIGRATION_FREQUENCY == 0)
//            emigrate(&pop, vers);
        for (j = 0; j < nb_children; j++) {
            tournament_select(&parent1, &parent2, &pop, 10);
            crossover(&child, &parent1, &parent2);
            mutate(&child, 10);
            evaluate(&child, map);
            add_to_population(&pop, &child);
        }
        if (i % MIGRATION_FREQUENCY == 0)
//            immigrate(&pop, vers);

        reduce_population(&pop);
        *best = pop.genotypes[0];
    }
}

void init_population(population_t *out, map_t *map)
{
    int i;

    out->size = REDUCED_POPULATION_SIZE;
    for (i = 0; i < REDUCED_POPULATION_SIZE; i++) {
        random_genotype(&(out->genotypes[i]));
        evaluate(&(out->genotypes[i]), map);
    }

    qsort(out->genotypes, REDUCED_POPULATION_SIZE, sizeof(*(out->genotypes)), compare_genotype);
}

void add_to_population(population_t *pop, genotype_t *genotype)
{
    if (pop->size < MAX_POPULATION_SIZE) {
        pop->genotypes[pop->size] = *genotype;
        pop->size++;
    }
}

void reduce_population(population_t *in_out)
{
    qsort(in_out->genotypes, in_out->size, sizeof(*(in_out->genotypes)), compare_genotype);
    in_out->size = REDUCED_POPULATION_SIZE;
}

void tournament_select(genotype_t *parent1, genotype_t *parent2, population_t *pop, int tournament_size)
{
    int i;
    int first = 0, second = 0;

    for (i = 0; i < tournament_size && i < MAX_TOURNAMENT_SIZE; i++) {
        if (pop->genotypes[rand() % REDUCED_POPULATION_SIZE].fitness > pop->genotypes[first].fitness) {
            second = first;
            first = i;
        }
    }

    *parent1 = pop->genotypes[first];
    *parent2 = pop->genotypes[second];
}

void emigrate(population_t *pop, int vers)
{
//    int i, err;
//    migrants_t m;
//    enum clnt_stat stat;
//    for (i = 0; i < MIGRATION_SIZE; i++)
//        m.pop[i] = pop->genotypes[i];
    
//    if ( (stat = callrpc("localhost", PROGNUM, vers, PROC_SEND_MIGRANTS,
//            (xdrproc_t)xdr_migrants_t, (char *)&m,
//            (xdrproc_t)xdr_int, (char *)&err)) )
//    {
//        fprintf(stderr, "Echec de l'appel distant (");
//        clnt_perrno(stat);      fprintf(stderr, ")\n");
//    }
}


void immigrate(population_t *out, int vers)
{
//    int i, dice;
//    migrants_t m;
//    server_info_t info;
//    enum clnt_stat stat;
    
//    callrpc("localhost", PROGNUM, vers, PROC_GIVE_SERVER_INFO,
//            (xdrproc_t)xdr_void, NULL, (xdrproc_t)xdr_server_info_t, (char *)&info);

//    if (info.size != 0)
//    {
//        dice = rand() % info.size;

//        if ( (stat = callrpc("localhost", PROGNUM, info.id[dice], PROC_RECEIVE_MIGRANTS,
//                (xdrproc_t)xdr_void, NULL,
//                (xdrproc_t)xdr_migrants_t, (char *)&m)) )
//        {
//            fprintf(stderr, "Echec de l'appel distant (");
//            clnt_perrno(stat);      fprintf(stderr, ")\n");
//        }
    
//        for (i = 0; i < MIGRATION_SIZE; i++)
//            add_to_population(out, &(m.pop[i]) );
//    }
}


#ifdef __cplusplus
}
#endif
