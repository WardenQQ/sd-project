#pragma once

#include "procedures.h"
#include "types_xdr.h"

#ifdef __cplusplus
extern "C" {
#endif

void client_init(server_address_t self, map_t map);
void client_join(int vers, char *ip, int contact_vers, char *contact_ip);
void pair_with_server(int vers);

#ifdef __cplusplus
}
#endif
