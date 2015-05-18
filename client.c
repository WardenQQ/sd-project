#include <rpc/rpc.h>
#include <rpc/xdr.h>

#include "client.h"

#ifdef __cplusplus
extern "C" {
#endif

int err = 0;

void client_init(server_address_t self, map_t map)
{
    population_t pop;

    pair_with_server(self);

    enum clnt_stat stat;
    stat = callrpc(self.hostname, PROGNUM, self.id, PROC_SET_MAP,
            (xdrproc_t)xdr_map_t, (char *)&map,
            (xdrproc_t)xdr_int, (char *)&err);

    init_population(&pop, &map);
    emigrate(&pop, self);

    genetic_algorithm(&map, &pop, self);
}

void client_join(server_address_t self, server_address_t contact)
{
    population_t pop;

    pair_with_server(self);

    map_t map;

    enum clnt_stat stat;
    stat = callrpc(self.hostname, PROGNUM, self.id, PROC_ANNOUNCE_SELF,
            (xdrproc_t)xdr_server_address_t, (char *)&contact,
            (xdrproc_t)xdr_int, (char *)&err);

    stat = callrpc(self.hostname, PROGNUM, self.id, PROC_GET_MAP,
            (xdrproc_t)xdr_void, NULL,
            (xdrproc_t)xdr_map_t, (char *)&map);

    init_population(&pop, &map);
    emigrate(&pop, self);

    genetic_algorithm(&map, &pop, self);
}

void pair_with_server(server_address_t self)
{
    enum clnt_stat stat;
    sleep(1);
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
