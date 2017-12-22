/* 
   COPYRIGHT 
*/

/* Project internal header */
#include "proj_int.h"

/* Module internal header */
#include "obj_int.h"

/**
 * @file obj.c
 * OBJ_DESCRIPTION
 */

/**
 * Allocate an uninitialised OBJ structure
 */
int OBJ_new (OBJ **obj)
{
  NAT_FUNC_START(ret);
  OBJ *tmp = NULL;

  NAT_MALLOC_STRUCT(tmp,OBJ,ret,end);

  *obj = tmp;
  tmp=NULL;

 end:

  NAT_FREE(tmp);
  NAT_FUNC_END(ret);
}
void OBJ_free (OBJ *obj)
{
  /* Clear the internal data with zerorized */
  OBJ_clear(obj);

  NAT_FREE(obj);

  NAT_FUNC_VOID_END();
}
void OBJ_clear (OBJ *obj)
{
  /* Clear the content of OBJ */

  NAT_FUNC_VOID_END();
}
int OBJ_do_something (OBJ *obj)
{
  NAT_FUNC_START(ret);
  NAT_CHECK_IS_NOT_NULL(obj,ret,end);

  /* Write operation for this object here.  */
 end:

  NAT_FUNC_END(ret);
}

