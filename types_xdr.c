/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "types_xdr.h"

#ifdef __cplusplus
extern "C" {
#endif

bool_t
xdr_gene_t (XDR *xdrs, gene_t *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->step))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->direction))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_genotype_t (XDR *xdrs, genotype_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->genes, GENOTYPE_SIZE,
		sizeof (gene_t), (xdrproc_t) xdr_gene_t))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->fitness))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_map_object_t (XDR *xdrs, map_object_t *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->x))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->y))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->radius))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->type))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->x);
			IXDR_PUT_LONG(buf, objp->y);
			IXDR_PUT_LONG(buf, objp->radius);
			IXDR_PUT_LONG(buf, objp->type);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->x))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->y))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->radius))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->type))
				 return FALSE;
		} else {
			objp->x = IXDR_GET_LONG(buf);
			objp->y = IXDR_GET_LONG(buf);
			objp->radius = IXDR_GET_LONG(buf);
			objp->type = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->x))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->y))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->radius))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->type))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_map_t (XDR *xdrs, map_t *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_int (xdrs, &objp->width))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->height))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->blocks, MAX_BLOCKS_NBR,
			sizeof (map_object_t), (xdrproc_t) xdr_map_object_t))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nb_blocks))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->goals, MAX_GOALS_NBR,
			sizeof (map_object_t), (xdrproc_t) xdr_map_object_t))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nb_goals))
			 return FALSE;
		 if (!xdr_map_object_t (xdrs, &objp->start_pos))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 7 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->min_step))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->max_step))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->min_radius))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->max_radius))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->mutation_prob))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->nb_children))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->migration_freq))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->min_step);
			IXDR_PUT_LONG(buf, objp->max_step);
			IXDR_PUT_LONG(buf, objp->min_radius);
			IXDR_PUT_LONG(buf, objp->max_radius);
			IXDR_PUT_LONG(buf, objp->mutation_prob);
			IXDR_PUT_LONG(buf, objp->nb_children);
			IXDR_PUT_LONG(buf, objp->migration_freq);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_int (xdrs, &objp->width))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->height))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->blocks, MAX_BLOCKS_NBR,
			sizeof (map_object_t), (xdrproc_t) xdr_map_object_t))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nb_blocks))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->goals, MAX_GOALS_NBR,
			sizeof (map_object_t), (xdrproc_t) xdr_map_object_t))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nb_goals))
			 return FALSE;
		 if (!xdr_map_object_t (xdrs, &objp->start_pos))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 7 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->min_step))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->max_step))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->min_radius))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->max_radius))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->mutation_prob))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->nb_children))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->migration_freq))
				 return FALSE;
		} else {
			objp->min_step = IXDR_GET_LONG(buf);
			objp->max_step = IXDR_GET_LONG(buf);
			objp->min_radius = IXDR_GET_LONG(buf);
			objp->max_radius = IXDR_GET_LONG(buf);
			objp->mutation_prob = IXDR_GET_LONG(buf);
			objp->nb_children = IXDR_GET_LONG(buf);
			objp->migration_freq = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->width))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->height))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->blocks, MAX_BLOCKS_NBR,
		sizeof (map_object_t), (xdrproc_t) xdr_map_object_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nb_blocks))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->goals, MAX_GOALS_NBR,
		sizeof (map_object_t), (xdrproc_t) xdr_map_object_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nb_goals))
		 return FALSE;
	 if (!xdr_map_object_t (xdrs, &objp->start_pos))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->min_step))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->max_step))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->min_radius))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->max_radius))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->mutation_prob))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nb_children))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->migration_freq))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_server_address_t (XDR *xdrs, server_address_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->hostname, 64,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_server_list_t (XDR *xdrs, server_list_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->addr, SERVER_LIST_MAX,
		sizeof (server_address_t), (xdrproc_t) xdr_server_address_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_migrants_t (XDR *xdrs, migrants_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->pop, MIGRATION_SIZE,
		sizeof (genotype_t), (xdrproc_t) xdr_genotype_t))
		 return FALSE;
	return TRUE;
}


#ifdef __cplusplus
}
#endif
