/* 
   COPYRIGHT 
*/

/* Module internal header */
#include "proj_int.h"

/**
 * @file proj_common.c
 * Bunch of utility functions commonly used in the project. 
 */

/**
 * Take copy of string. 
 *
 * @param obj [In]  Allocated OBJ structure.
 *
 * @return
 *         #PROJ_ERROR_NONE indicates success. <br>
 */
int proj_strdup(char *from, char **to)
{
  NAT_FUNC_START(ret);
  char *tmp=NULL;
  unsigned int size;
  NAT_CHECK_IS_NOT_NULL(from,ret,end);

  size=Strlen(from)+1;
  tmp=Malloc(size);
  if(tmp==NULL)
    {
      ret = PROJ_ERROR_ALLOC_FAILURE;
      goto end;
    }
  Memset(tmp,0x00,size);
  Memcpy(tmp,from,size-1);

  *to=tmp;
  tmp=NULL;

 end:
  NAT_FREE(tmp);
  
  NAT_FUNC_END(ret);
}
