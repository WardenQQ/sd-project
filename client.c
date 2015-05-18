#include <rpc/rpc.h>
#include <rpc/xdr.h>

#include "client.h"

#ifdef __cplusplus
extern "C" {
#endif

	int err = 0;

void client_init(server_address_t self, map_t map)
{
    pair_with_server(self.id);

    enum clnt_stat stat;
    stat = callrpc(self.hostname, PROGNUM, self.id, PROC_SET_MAP,
            (xdrproc_t)xdr_map_t, (char *)&map,
            (xdrproc_t)xdr_int, (char *)&err);

    genetic_algorithm(100, map.nb_children, &map, self.id);
}

void client_join(int vers, char *ip, int contact_vers, char *contact_ip)
{
	pair_with_server(vers);
	
	server_address_t contact;
	contact.id = contact_vers;
//	contact.hostname = contact_ip;

	map_t map;
	
	enum clnt_stat stat;
    stat = callrpc("localhost", PROGNUM, vers, PROC_ANNOUNCE_SELF,
            (xdrproc_t)xdr_server_address_t, (char *)&contact,
            (xdrproc_t)xdr_int, (char *)&err);

    stat = callrpc("localhost", PROGNUM, vers, PROC_GET_MAP,
            (xdrproc_t)xdr_void, (char *)&vers,
            (xdrproc_t)xdr_map_t, (char *)&map);



    genetic_algorithm(100, map.nb_children, &map, vers);
}

void pair_with_server(int vers)
{
	server_address_t my_addr;
	my_addr.id = vers;












//	my_addr.hostname = "quellle est la taille d'une adresse ip (v4 ?) ???????";









	enum clnt_stat stat;
    while ( (stat = callrpc("localhost", PROGNUM, vers, PROC_INIT_SERVER,
            (xdrproc_t)xdr_server_address_t, (char *)&my_addr,
            (xdrproc_t)xdr_int, (char *)&err)) ) 
    {
		fprintf(stderr, "Cannot connect to the server (");
		clnt_perrno(stat);      fprintf(stderr, ")\n");
    }
}

#ifdef __cplusplus
}
#endif
