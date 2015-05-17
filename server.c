#include <rpc/rpc.h>
#include <rpc/xdr.h>
#include <stdio.h>

#include "server.h"

#ifdef __cplusplus
extern "C" {
#endif

int registerrpc(unsigned long prognum, unsigned long versnum,
                unsigned long procnum, char *(*procname)(char *),
                xdrproc_t inproc, xdrproc_t outproc);

void server(int vers)
{
    if (registerrpc(PROGNUM, vers,
                    PROC_INIT_SERVER, init_server,
                    (xdrproc_t)xdr_server_address_t, (xdrproc_t)xdr_int) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_INIT_SERVER\n");
	    exit(1);
    }

    if (registerrpc(PROGNUM, vers,
                PROC_GIVE_SERVER_LIST, give_server_list,
                (xdrproc_t)xdr_void, (xdrproc_t)xdr_server_list_t) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_GIVE_SERVER_INFO\n");
	    exit(1);
    }

    if (registerrpc(PROGNUM, vers,
                PROC_ANNOUNCE_SELF, announce_self,
                (xdrproc_t)xdr_server_address_t, (xdrproc_t)xdr_int) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_ANNOUNCE_SELF\n");
	    exit(1);
    }

    if (registerrpc(PROGNUM, vers,
                PROC_ADD_SERVER, add_server,
                (xdrproc_t)xdr_server_address_t, (xdrproc_t)xdr_int) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_ADD_SERVER\n");
	    exit(1);
    }


    if (registerrpc(PROGNUM, vers,
                PROC_GET_MAP, get_map,
                (xdrproc_t)xdr_int, (xdrproc_t)xdr_map_t) != 0) 
    {
	    fprintf(stderr,"Echec de l'enregistrement pour PROC_GET_MAP\n");
	    exit(1);
    }

    if (registerrpc(PROGNUM, vers,
                PROC_SET_MAP, set_map,
                (xdrproc_t)xdr_map_t, (xdrproc_t)xdr_int) != 0) 
    {
        fprintf(stderr,"Echec de l'enregistrement pour PROC_SET_MAP\n");
        exit(1);
    }

    if (registerrpc(PROGNUM, vers,
                PROC_SEND_MIGRANTS, send_migrants,
                (xdrproc_t)xdr_migrants_t, (xdrproc_t)xdr_int) != 0) 
    {
        fprintf(stderr,"Echec de l'enregistrement pour PROC_SEND_MIGRANTS\n");
        exit(1);
    }

    if (registerrpc(PROGNUM, vers,
                PROC_RECEIVE_MIGRANTS, receive_migrants,
                (xdrproc_t)xdr_void, (xdrproc_t)xdr_migrants_t) != 0) 
    {
        fprintf(stderr,"Echec de l'enregistrement pour PROC_RECEIVE_MIGRANTS\n");
        exit(1);
    }

    svc_run();
}


#ifdef __cplusplus
}
#endif
