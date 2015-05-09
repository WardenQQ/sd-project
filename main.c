#define MAX_ITERATION 10000
#define MAX_CHILDREN 50

#include <stdio.h>

#include "population.h"

int main()
{
    genetic_algorithm(MAX_ITERATION, MAX_CHILDREN);

    return 0;
}
