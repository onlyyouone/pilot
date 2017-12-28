/* 
   COPYRIGHT 
*/

/**
 * @file obj_int.h
 * This file contains internal structure and functions used by obj module. 
 */

#ifndef HEADER_OBJ_INT_H
#define HEADER_OBJ_INT_H

#ifdef  __cplusplus
extern "C" {
#endif

/* Project internal header */
#include "proj_int.h"

/* Include API layer header */
#include "obj.h"  
  
/** Structure used to specify Embedded RKM local key store configuration. */
struct _obj_st
{
  /* Type of the object */
  PROJ_DATA_TYPE obj_type;

  /* Other members... */
};

#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_OBJ_INT_H */
