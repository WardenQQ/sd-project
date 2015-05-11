#include "procedures.h"

#include "types_xdr.h"

server_info_t info;
int version;
migrants_t pop;

int * init_server(int * vers)
{
    static int ret = 0;
    int i;

    info.size = 0;
    version = *vers;

    for (i = 0; i < MIGRATION_SIZE; i++) {
        pop.pop[i].fitness = -1;
    }
    return &ret;
}

server_info_t * give_server_info(void * none)
{
    return &info;
}

int * announce_self(int *id)
{
    static int ret = 0;

    int i;

    callrpc("localhost", PROGNUM, *id, PROC_GIVE_SERVER_INFO,
            (xdrproc_t)xdr_void, (char *)&ret, (xdrproc_t)xdr_server_info_t, (char *)&info);
    
    add_server(id);
    for (i = 0; i < info.size; i++) {
        callrpc("localhost", PROGNUM, info.id[i], PROC_ADD_SERVER,
                (xdrproc_t)xdr_int, (char *)&version, (xdrproc_t)xdr_int, (char *)&ret);
    }

    return &ret;
}

int * add_server(int *id)
{
    static int ret = 0;

    if (info.size < SERVER_LIST_MAX) {
        info.id[info.size] = *id;
        info.size++;
        printf("<SERVER> Adding of a new instance: %d\n", *id);
    }

    return &ret;
}

map_t * get_map(void *id)
{
    return &(info.map);
}

int * set_map(map_t * map)
{
    static int ret = 0;

    info.map = *map;

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