#pragma once

#include <rpc/rpc.h>
#include <rpc/xdr.h>
#include "map.h"
#include "genotype.h"

#define PROGNUM 0x2000abcd

#define PROC_INIT_SERVER 1
#define PROC_GIVE_SERVER_INFO 2
#define PROC_ANNOUNCE_SELF 3
#define PROC_ADD_SERVER 4
#define PROC_GET_MAP 5
#define PROC_SET_MAP 6
#define PROC_SEND_MIGRANTS 7
#define PROC_RECEIVE_MIGRANTS 8

#define SERVER_LIST_MAX 16
#define MIGRATION_SIZE 3

typedef struct {
    int id[SERVER_LIST_MAX];
    int size;
    map_t map;
} server_info_t;

typedef struct {
    genotype_t pop[MIGRATION_SIZE];
} migrants_t;

int * init_server(int * vers);
server_info_t * give_server_info(void * none);
int * announce_self(int *id);
int * add_server(int *id);
map_t * get_map(void *id);
int * set_map(map_t * map);
int * send_migrants(migrants_t * m);
migrants_t * receive_migrants(void * none);
