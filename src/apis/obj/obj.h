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

/* API declarations */
int  OBJ_new (OBJ **obj);
void OBJ_free (OBJ *obj);
void OBJ_clear (OBJ *obj);
int  OBJ_do_something (OBJ *obj);
  
#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_OBJ_H */
