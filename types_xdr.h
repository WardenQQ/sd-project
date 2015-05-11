#pragma once

#include <rpc/xdr.h>

#include "map.h"
#include "procedures.h"

bool_t xdr_map_t (XDR *xdrs, map_t *objp);
bool_t xdr_server_info_t (XDR *xdrs, server_info_t *objp);
bool_t xdr_migrants_t (XDR *xdrs, migrants_t *objp);
bool_t xdr_genotype_t (XDR *xdrs, genotype_t *objp);
bool_t xdr_gene_t (XDR *xdrs, gene_t *objp);