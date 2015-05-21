#include "population.h"
#include "procedures.h"
#include "types_xdr.h"

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


genotype_t genetic_algorithm(map_t *map, population_t *pop, server_address_t addr)
{
    int i, j;
    genotype_t parent1, parent2, child;

    i = 0;
    while (1) {
        if (i % map->migration_freq == 0) {
            emigrate(pop, addr);
        }

        for (j = 0; j < map->nb_children; j++) {
            tournament_select(&parent1, &parent2, pop, 3);
            crossover(&child, &parent1, &parent2);
            mutate(&child, map->mutation_prob, map->min_step, map->max_step);
            evaluate(&child, map);
            add_to_population(pop, &child);
        }

        if (i % map->migration_freq == 0) {
            immigrate(pop, addr);
        }

        reduce_population(pop);
        i = (i + 1) % map->migration_freq;
    }
}

void init_population(population_t *out, map_t *map)
{
    int i;

    out->size = REDUCED_POPULATION_SIZE;
    for (i = 0; i < REDUCED_POPULATION_SIZE; i++) {
        random_genotype(&(out->genotypes[i]), map->min_step, map->max_step);
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
    int size = in_out->size - REDUCED_POPULATION_SIZE;
    memmove(&(in_out->genotypes[REDUCED_POPULATION_SIZE - size]),
            &(in_out->genotypes[REDUCED_POPULATION_SIZE]),
            size * sizeof(*(in_out->genotypes)));

    qsort(in_out->genotypes, REDUCED_POPULATION_SIZE, sizeof(*(in_out->genotypes)), compare_genotype);

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

void emigrate(population_t *pop, server_address_t addr)
{
    int i, err;
    migrants_t m;
    enum clnt_stat stat;
    for (i = 0; i < MIGRATION_SIZE; i++)
        m.pop[i] = pop->genotypes[i];
    
    if ( (stat = callrpc(addr.hostname, PROGNUM, addr.id, PROC_SEND_MIGRANTS,
            (xdrproc_t)xdr_migrants_t, (char *)&m,
            (xdrproc_t)xdr_int, (char *)&err)) )
    {
        fprintf(stderr, "Echec de l'appel distant (");
        clnt_perrno(stat);      fprintf(stderr, ")\n");
    }
}


void immigrate(population_t *out, server_address_t addr)
{
    int i, dice;
    migrants_t m;
    server_list_t list;
    enum clnt_stat stat;
    
    callrpc(addr.hostname, PROGNUM, addr.id, PROC_GIVE_SERVER_LIST,
            (xdrproc_t)xdr_void, NULL, (xdrproc_t)xdr_server_list_t, (char *)&list);

    if (list.size != 0)
    {
        dice = rand() % list.size;

        if ( (stat = callrpc(list.addr[dice].hostname, PROGNUM, list.addr[dice].id, PROC_RECEIVE_MIGRANTS,
                (xdrproc_t)xdr_void, NULL,
                (xdrproc_t)xdr_migrants_t, (char *)&m)) )
        {
            fprintf(stderr, "Echec de l'appel distant (");
            clnt_perrno(stat);      fprintf(stderr, ")\n");
        }
    
        for (i = 0; i < MIGRATION_SIZE; i++)
            add_to_population(out, &(m.pop[i]) );
    }
}


#ifdef __cplusplus
}
#endif
