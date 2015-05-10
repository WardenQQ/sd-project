#pragma once

#include <rpc/xdr.h>

bool_t xdr_coord_t (XDR *xdrs, coord_t *objp);
bool_t xdr_map_t (XDR *xdrs, map_t *objp);
bool_t xdr_server_info_t (XDR *xdrs, server_info_t *objp);