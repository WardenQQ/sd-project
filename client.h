#pragma once

#include "procedures.h"
#include "types_xdr.h"

#ifdef __cplusplus
extern "C" {
#endif

void client_init(int vers, char *ip, map_t map);
void client_join(server_address_t self, server_address_t contact);
void pair_with_server(server_address_t self);

#ifdef __cplusplus
}
#endif
