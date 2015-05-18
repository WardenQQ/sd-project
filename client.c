#include <rpc/rpc.h>
#include <rpc/xdr.h>

#include "client.h"

#ifdef __cplusplus
extern "C" {
#endif

int err = 0;

void client_init(int vers, char *ip, map_t map)
{
	pair_with_server(vers);

	enum clnt_stat stat;
    stat = callrpc("localhost", PROGNUM, vers, PROC_SET_MAP,
            (xdrproc_t)xdr_map_t, (char *)&map,
            (xdrproc_t)xdr_int, (char *)&err);

    genetic_algorithm(100, map.nb_children, &map, vers);
}

void client_join(server_address_t self, server_address_t contact)
{
    pair_with_server(self);

    map_t map;

    enum clnt_stat stat;
    stat = callrpc(self.hostname, PROGNUM, self.id, PROC_ANNOUNCE_SELF,
            (xdrproc_t)xdr_server_address_t, (char *)&contact,
            (xdrproc_t)xdr_int, (char *)&err);

    stat = callrpc(self.hostname, PROGNUM, self.id, PROC_GET_MAP,
            (xdrproc_t)xdr_void, NULL,
            (xdrproc_t)xdr_map_t, (char *)&map);

    genetic_algorithm(100, map.nb_children, &map, self.id);
}

void pair_with_server(server_address_t self)
{
    enum clnt_stat stat;
    while ( (stat = callrpc(self.hostname, PROGNUM, self.id, PROC_INIT_SERVER,
                    (xdrproc_t)xdr_server_address_t, (char *)&self,
                    (xdrproc_t)xdr_int, (char *)&err)) ) 
    {
        clnt_perrno(stat);
        fprintf(stderr, ")\n");
    }
}

#ifdef __cplusplus
}
#endif
