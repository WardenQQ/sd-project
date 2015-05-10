#ifndef PARAM
#define PARAM  

#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>
#define PROGNUM 0x20000100
#define VERSNUM 1
#define PROCNUM_INIT_MAP 1
#define PROCNUM_NEIGHBOR 2
typedef struct { int tab[10][10]; } map_t;
typedef struct { char addresse_des_voisins[10][32]; } neighbors_t;

#endif /* PARAM */


bool_t xdr_map_t(XDR *xdrs, map_t * p) {
	bool_t res;
	/* A completer */
	return res;
}
bool_t xdr_neighbors_t(XDR *xdrs, neighbors_t * p) {
	bool_t res;
	/* A completer */
	return res;
}


map_t * initialiser_carte(map_t *p) {
	static map_t res;
	/* A completer */
	return &res;
}
neighbors_t * diffuser_voisins(neighbors_t *p) {
	static neighbors_t res;
	/* A completer */
	return &res;
}

int main(void)
{
	if (fork() == 0)
		thread_serveur();
	else
		thread_client();

	return 0;
}


int thread_serveur (void) {
	bool_t stat;
	stat = registerrpc(PROGNUM, VERSNUM, PROCNUM_INIT_MAP, 
			initialiser_carte, (xdrproc_t) xdr_map_t, (xdrproc_t) xdr_map_t);
	if (stat != 0) {
		fprintf(stderr,"Echec de l'enregistrement\n");
		exit(1);
	}
	stat = registerrpc(PROGNUM, VERSNUM, PROCNUM_NEIGHBOR, 
			diffuser_voisins, (xdrproc_t) xdr_neighbors_t, (xdrproc_t) xdr_neighbors_t);
	if (stat != 0) {
		fprintf(stderr,"Echec de l'enregistrement\n");
		exit(1);
	}
	svc_run();
	return(0);
}

int thread_client (void) {
	int stat;
	map_t donnees, res;
	neighbors_t donnees_2, res_2;
	stat = callrpc("127.0.0.1",PROGNUM, VERSNUM, PROCNUM_INIT_MAP, 
			(xdrproc_t)xdr_map_t, (char*) &donnees, (xdrproc_t)xdr_map_t, (char*) &res);

	if (stat != RPC_SUCCESS) { 
		fprintf(stderr, "Echec de l'appel distant\n");
		clnt_perrno(stat);      fprintf(stderr, "\n");
	}
	else
		printf("Appel réussi !\n");

	stat = callrpc("127.0.0.1",PROGNUM, VERSNUM, PROCNUM_NEIGHBOR, 
			(xdrproc_t)xdr_neighbors_t, (char*) &donnees_2, (xdrproc_t)xdr_neighbors_t, (char*) &res_2);

	if (stat != RPC_SUCCESS) { 
		fprintf(stderr, "Echec de l'appel distant\n");
		clnt_perrno(stat);      fprintf(stderr, "\n");
	}
	else
		printf("Appel réussi !\n");
	return(0);
}