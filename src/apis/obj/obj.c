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
 * Where possible, this function zerorises the contents
 * before freeing data.
 *
 * @param obj [In]  Allocated OBJ structure to be cleaned..
 *
 */
void OBJ_clear (OBJ *obj)
{
  /* Clear the content of OBJ */
  NAT_FREE(obj->str_data);
  Memset(obj,0x00,sizeof(OBJ));
  NAT_FUNC_VOID_END();
}
/**
 * Sets property data to OBJ structure.
 * Set opration always takes copy of given value. 
 * If the given value is pointer of structure, set operation
 * takes deep copy of the structure. 
 *
 * Copied value are freed in clear() function.
 *
 * @param obj  [In]  Allocated OBJ structure.
 * @param prop [In]  Property identifier. 
 * @param data [In]  Data to be set. 
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
    case OBJ_PROP_INT_DATA:
      obj->int_data = data->d.int_d;
      break;

    case OBJ_PROP_STR_DATA:
      /* Frees previous data in case there. */
      NAT_FREE(obj->str_data);
      NAT_CHECK_FUNC(NAT_STRDUP(data->d.char_p,&(obj->str_data)),ret,end);
      break;

    default:
      ret = PROJ_ERROR_UNSUPPORTED;
      goto end;
    }
  
 end:

  NAT_FUNC_END(ret);
}
/**
 * Gets property data from OBJ structure.
 * Get operation returns values for char, int, long value and 
 * returns pointers for string data, structures(objects).
 *
 * @param obj  [In]   Allocated OBJ structure.
 * @param prop [In]   Property identifier. 
 * @param data [Out]  Data to be returned. 
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
    case OBJ_PROP_INT_DATA:
      data->d.int_d=obj->int_data;
      break;

    case OBJ_PROP_STR_DATA:
      data->d.char_p=obj->str_data;
      break;

    default:
      ret = PROJ_ERROR_UNSUPPORTED;
      goto end;
      
    }
  
 end:

  NAT_FUNC_END(ret);
}
/**
 * Deep copy OBJ.
 *
 * @param fromj [In]  OBJ to copy.
 * @param to    [Out] Copied OBJ.
 *
 * @return
 *         #PROJ_ERROR_NONE indicates success. <br>
 */
int OBJ_dup (OBJ *from,OBJ **to)
{
  NAT_FUNC_START(ret);
  OBJ *tmp=NULL;
  NAT_CHECK_IS_NOT_NULL(from,ret,end);
  NAT_CHECK_IS_NOT_NULL(to,ret,end);
  
  /* Create new object */
   NAT_CHECK_FUNC(OBJ_new(&tmp),ret,end);

  /* Copy contents */ 
   NAT_CHECK_FUNC(OBJ_copy_contents(from,tmp),ret,end);

   *to=tmp;
   tmp=NULL;
 end:
  NAT_FREE(tmp);
   
  NAT_FUNC_END(ret);
}
/**
 * Copy the contents of OBJ. 
 *
 * @param fromj [In]  OBJ to copy.
 * @param to    [Out] Copied OBJ.
 *
 * @return
 *         #PROJ_ERROR_NONE indicates success. <br>
 */
int OBJ_copy_contents (OBJ *from,OBJ *to)
{
  NAT_FUNC_START(ret);
  NAT_CHECK_IS_NOT_NULL(from,ret,end);
  NAT_CHECK_IS_NOT_NULL(to,ret,end);
  
  /* Create deep copy */ 
  NAT_CHECK_FUNC(NAT_STRDUP(from->str_data,&(to->str_data)), ret,end);
  to->int_data=from->int_data;

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
