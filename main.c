#define MAX_ITERATION 10000
#define MAX_CHILDREN 50

#include <stdio.h>

#include "population.h"

int main()
{
	/*
    genetic_algorithm(MAX_ITERATION, MAX_CHILDREN);
    */
    
    map_t map;
    init_map(&map, 20, 5);
    print_map(&map);

    return 0;
}
