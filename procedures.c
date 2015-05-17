#include "procedures.h"

#include "types_xdr.h"

#ifdef __cplusplus
extern "C" {
#endif

server_list_t list;
migrants_t pop;
server_address_t address;
map_t map;

int * init_server(server_address_t * addr)
{
    static int ret = 0;

    list.size = 0;
    address = *addr;

    return &ret;
}

server_list_t * give_server_list(void * none)
{
    return &list;
}

int * announce_self(server_address_t *addr)
{
    static int ret = 0;

    int i;

    callrpc(addr->hostname, PROGNUM, addr->id, PROC_GIVE_SERVER_LIST,
            (xdrproc_t)xdr_void, (char *)&ret, (xdrproc_t)xdr_server_list_t, (char *)&list);
    
    add_server(addr);
    for (i = 0; i < list.size; i++) {
        callrpc(list.addr[i].hostname, PROGNUM, list.addr[i].id, PROC_ADD_SERVER,
                (xdrproc_t)xdr_server_address_t, (char *)&address, (xdrproc_t)xdr_int, (char *)&ret);
    }

    return &ret;
}

int * add_server(server_address_t * addr)
{
    static int ret = 0;

    if (list.size < SERVER_LIST_MAX) {
        list.addr[list.size] = *addr;
        list.size++;
    }

    return &ret;
}

map_t * get_map(void *id)
{
    return &(map);
}

int * set_map(map_t * m)
{
    static int ret = 0;

    map = *m;

    return &ret;
}

int * send_migrants(migrants_t * m)
{
    static int ret = 0;

    pop = *m;

    return &ret;
}

migrants_t * receive_migrants(void * none)
{
    return &(pop);
}


#ifdef __cplusplus
}
#endif
