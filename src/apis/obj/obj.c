/* 
   COPYRIGHT 
*/

/* Module internal header */
#include "obj_int.h"

/**
 * @file obj.c
 * OBJ_DESCRIPTION
 */

/**
 * Allocate a new OBJ structure.
 * If *data_array is not null, it is assumed that an existing R_KM_DATA_ARRAY
 * structure is referenced and this structure will be cleared for reuse.
 *
 * @param obj [Out]  Allocated OBJ reference.
 *
 * @return
 *         #PROJ_ERROR_NONE indicates success. <br>
 */
int OBJ_new (OBJ **obj)
{
  NAT_FUNC_START(ret);
  OBJ *tmp = NULL;

  NAT_MALLOC_STRUCT(tmp,OBJ,ret,end);

  tmp->obj_type=PROJ_TYPE_OBJ;
  *obj = tmp;
  tmp=NULL;

 end:

  NAT_FREE(tmp);
  NAT_FUNC_END(ret);
}
/**
 * Free OBJ structure.
 *
 * @param obj [In]  Allocated OBJ structure.
 *
 */
void OBJ_free (OBJ *obj)
{
  /* Clear the internal data with zerorized */
  OBJ_clear(obj);

  NAT_FREE(obj);

  NAT_FUNC_VOID_END();
}
/**
 * Clear contents of OBJ structure.
 *
 * @param obj [In]  Allocated OBJ structure to be cleaned..
 *
 */
void OBJ_clear (OBJ *obj)
{
  /* Clear the content of OBJ */

  NAT_FUNC_VOID_END();
}
/**
 * Sets property data to OBJ structure.
 *
 * @param obj [In]  Allocated OBJ structure.
 *
 * @return
 *         #PROJ_ERROR_NONE indicates success. <br>
 */
int OBJ_set (OBJ *obj,OBJ_PROP prop,PROJ_DATA *data)
{
  NAT_FUNC_START(ret);
  NAT_CHECK_IS_NOT_NULL(obj,ret,end);

  switch (prop)
    {
      
    default:
      ret = PROJ_ERROR_UNSUPPORTED;
      goto end;
      
    }
  
 end:

  NAT_FUNC_END(ret);
}
/**
 * Gets property data from OBJ structure.
 *
 * @param obj [In]  Allocated OBJ structure.
 *
 * @return
 *         #PROJ_ERROR_NONE indicates success. <br>
 */
int OBJ_get (OBJ *obj,OBJ_PROP prop,PROJ_DATA *data)
{
  NAT_FUNC_START(ret);
  NAT_CHECK_IS_NOT_NULL(obj,ret,end);

  switch (prop)
    {
      
    default:
      ret = PROJ_ERROR_UNSUPPORTED;
      goto end;
      
    }
  
 end:

  NAT_FUNC_END(ret);
}

/**
 * TODO: Do something from allocated OBJ object.
 *
 * @param obj [In]  Allocated OBJ structure.
 *
 * @return
 *         #PROJ_ERROR_NONE indicates success. <br>
 */
int OBJ_do_something (OBJ *obj)
{
  NAT_FUNC_START(ret);
  NAT_CHECK_IS_NOT_NULL(obj,ret,end);

 end:

  NAT_FUNC_END(ret);
}
