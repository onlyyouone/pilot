/* 
   COPYRIGHT 
*/

/**
 * @file obj.h
 * This file contains internal structure and functions used by obj module. 
 */

#ifndef HEADER_OBJ_H
#define HEADER_OBJ_H

#ifdef  __cplusplus
extern "C" {
#endif

/* Public declaration of OBJ */
typedef struct _obj_st OBJ;

#include <proj_data.h>
  
/* Public data that can be accessed from OBJ */
typedef enum 
{
  OBJ_TYPE,
}OBJ_PROP;

/* API declarations */
int  OBJ_new (OBJ **obj);
void OBJ_free (OBJ *obj);
void OBJ_clear (OBJ *obj);
int  OBJ_set (OBJ *obj,OBJ_PROP prop, PROJ_DATA *data);
int  OBJ_get (OBJ *obj,OBJ_PROP prop, PROJ_DATA *data);
int  OBJ_do_something (OBJ *obj);
  
#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_OBJ_H */
