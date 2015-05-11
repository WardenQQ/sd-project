#define MAX_ITERATION 10000
#define MAX_CHILDREN 50

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <rpc/rpc.h>
#include <rpc/xdr.h>

#include "types_xdr.h"
#include "procedures.h"
#include "population.h"
#include "map.h"

void server(int vers);
void client(int vers, int contact);

int main(int argc, char ** argv)
{
    int vers, contact;

    if (argc == 1) {
    	fprintf(stderr, "Usage: %s version [contact]\n", argv[0]);
        return 1;
    }

    vers = atoi(argv[1]);
    contact = argc > 2 ? atoi(argv[2]) : -1;

    switch (fork()) {
        case -1:
        	fprintf(stderr, "Error: fork() return -1\n");
            break;
        case 0:
            server(vers);
            break;
        default:
            client(vers, contact);
            sleep(100);
            break;
    }

	return 0;
}

void server(int vers)
{
    if ( registerrpc(PROGNUM, vers,
                PROC_INIT_SERVER, init_server,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_int) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_INIT_SERVER\n");
	    exit(1);
    }

    if ( registerrpc(PROGNUM, vers,
                PROC_GIVE_SERVER_INFO, give_server_info,
                (xdrproc_t)xdr_void, (xdrproc_t)xdr_server_info_t) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_GIVE_SERVER_INFO\n");
	    exit(1);
    }

    if ( registerrpc(PROGNUM, vers,
                PROC_ANNOUNCE_SELF, announce_self,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_int) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_ANNOUNCE_SELF\n");
	    exit(1);
    }

    if ( registerrpc(PROGNUM, vers,
                PROC_ADD_SERVER, add_server,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_int) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_ADD_SERVER\n");
	    exit(1);
    }


    if ( registerrpc(PROGNUM, vers,
                PROC_GET_MAP, get_map,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_map_t) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_GET_MAP\n");
	    exit(1);
    }

    if ( registerrpc(PROGNUM, vers,
                PROC_SET_MAP, set_map,
                (xdrproc_t)xdr_map_t, (xdrproc_t)xdr_int) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_SET_MAP\n");
	    exit(1);
    }

    svc_run();
}

void client(int vers, int contact)
{
    int err = 10;
    map_t map;
    enum clnt_stat stat;

    while ( (stat = callrpc("localhost", PROGNUM, vers, PROC_INIT_SERVER,
            (xdrproc_t)xdr_int, (char *)&vers,
            (xdrproc_t)xdr_int, (char *)&err)) ) 
    {
		fprintf(stderr, "Echec de l'appel distant (");
		clnt_perrno(stat);      fprintf(stderr, ")\n");
    }

    if (contact < 0) {
        init_map(&map, 20, 5);

        stat = callrpc("localhost", PROGNUM, vers, PROC_SET_MAP,
                (xdrproc_t)xdr_map_t, (char *)&map,
                (xdrproc_t)xdr_int, (char *)&err);

    } else {
        stat = callrpc("localhost", PROGNUM, vers, PROC_ANNOUNCE_SELF,
                (xdrproc_t)xdr_int, (char *)&contact,
                (xdrproc_t)xdr_int, (char *)&err);
        clnt_perrno(stat);putchar('\n');

        stat = callrpc("localhost", PROGNUM, vers, PROC_GET_MAP,
                (xdrproc_t)xdr_void, (char *)&vers,
                (xdrproc_t)xdr_map_t, (char *)&map);
    }


    int i, new_pos, map_type;
    genotype_t adn, adn2;
    random_genotype(&adn);
    random_genotype(&adn2);
    new_pos = map.start_pos;
    print_map(&map);

    for (i = 0; i < GENOTYPE_SIZE; i++)
    {
    	printf("Press to continue...\n");
	    getchar();
	    new_pos = move(&map, new_pos, adn.genes[i].direction);
	    map_type = map.tab[new_pos];
	    map.tab[new_pos] = 77;
	    print_map(&map);
	    map.tab[new_pos] = map_type;
    }

    evaluate(&adn, &map);
    evaluate(&adn2, &map);
    printf("\nThe fitness of adn1 is : %g\n", adn.fitness);
    printf("The fitness of adn2 is : %g\n", adn2.fitness);

    exit(0);
}
