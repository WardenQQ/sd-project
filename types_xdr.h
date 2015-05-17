#pragma once

#include <rpc/xdr.h>

#include "map.h"
#include "procedures.h"

#ifdef __cplusplus
extern "C" {
#endif

extern  bool_t xdr_gene_t (XDR *, gene_t*);
extern  bool_t xdr_genotype_t (XDR *, genotype_t*);
extern  bool_t xdr_map_object_t (XDR *, map_object_t*);
extern  bool_t xdr_map_t (XDR *, map_t*);
extern  bool_t xdr_server_address_t (XDR *, server_address_t*);
extern  bool_t xdr_server_list_t (XDR *, server_list_t*);
extern  bool_t xdr_migrants_t (XDR *, migrants_t*);

#ifdef __cplusplus
}
#endif