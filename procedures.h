#pragma once

#include <rpc/rpc.h>
#include <rpc/xdr.h>
#include "map.h"

#define PROGNUM 0x2000abcd

#define PROC_INIT_SERVER 0
#define PROC_GIVE_SERVER_INFO 1
#define PROC_ANNOUNCE_SELF 2
#define PROC_ADD_SERVER 3
#define PROC_GET_MAP 4
#define PROC_SET_MAP 5

#define SERVER_LIST_MAX 16

typedef struct {
    int id[SERVER_LIST_MAX];
    int size;
    map_t map;
} server_info_t;

int * init_server(int * vers);
server_info_t * give_server_info(void * none);
int * announce_self(int *id);
int * add_server(int *id);
map_t * get_map(void *id);
int * set_map(map_t * map);
