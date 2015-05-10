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
    pid_t pid;

    if (argc == 1) {
        return 1;
    }

    vers = atoi(argv[1]);
    contact = argc > 2 ? atoi(argv[2]) : -1;

    switch (pid = fork()) {
        case -1:
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
    int err;
    err = registerrpc(PROGNUM, vers,
                PROC_INIT_SERVER, init_server,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_int);
    if (err != 0) {
        exit(1);
    }

    err = registerrpc(PROGNUM, vers,
                PROC_GIVE_SERVER_INFO, give_server_info,
                (xdrproc_t)xdr_void, (xdrproc_t)xdr_server_info_t);
    if (err != 0) {
        exit(1);
    }

    err = registerrpc(PROGNUM, vers,
                PROC_ANNOUNCE_SELF, announce_self,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_int);
    if (err != 0) {
        exit(1);
    }

    err = registerrpc(PROGNUM, vers,
                PROC_ADD_SERVER, add_server,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_int);
    if (err != 0) {
        exit(1);
    }


    err = registerrpc(PROGNUM, vers,
                PROC_GET_MAP, get_map,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_map_t);
    if (err != 0) {
        exit(1);
    }

    err = registerrpc(PROGNUM, vers,
                PROC_SET_MAP, set_map,
                (xdrproc_t)xdr_map_t, (xdrproc_t)xdr_int);
    if (err != 0) {
        exit(1);
    }

    svc_run();
}

void client(int vers, int contact)
{
    int err = 10;
    map_t map, map2;
    enum clnt_stat stat;

    while (stat = callrpc("localhost", PROGNUM, vers, PROC_INIT_SERVER,
            (xdrproc_t)xdr_int, (char *)&vers,
            (xdrproc_t)xdr_int, (char *)&err))
        clnt_perrno(stat);

    if (contact < 0) {
        init_map(&map, 20, 5);
        print_map(&map);

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
        print_map(&map);
    }
}
