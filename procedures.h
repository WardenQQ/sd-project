#pragma once

#include <rpc/rpc.h>
#include <rpc/xdr.h>
#include "map.h"
#include "genotype.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PROGNUM 0x2000abcd

#define PROC_INIT_SERVER 1
#define PROC_GIVE_SERVER_LIST 2
#define PROC_ANNOUNCE_SELF 3
#define PROC_ADD_SERVER 4
#define PROC_GET_MAP 5
#define PROC_SET_MAP 6
#define PROC_SEND_MIGRANTS 7
#define PROC_RECEIVE_MIGRANTS 8

#define SERVER_LIST_MAX 16
#define MIGRATION_SIZE 3

typedef struct {
    char hostname[64];
    int id;
} server_address_t;

typedef struct {
    server_address_t addr[SERVER_LIST_MAX];
    int size;
} server_list_t;

typedef struct {
    genotype_t pop[MIGRATION_SIZE];
} migrants_t;

int * init_server(server_address_t * addr);
server_list_t * give_server_list(void * none);
int * announce_self(server_address_t *addr);
int * add_server(server_address_t * addr);
map_t * get_map(void *id);
int * set_map(map_t * m);
int * send_migrants(migrants_t * m);
migrants_t * receive_migrants(void * none);


#ifdef __cplusplus
}
#endif
