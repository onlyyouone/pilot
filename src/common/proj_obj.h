/* 
   COPYRIGHT 
*/

/**
 * @file proj_obj.h
 * This file contains objs used for implementation. 
 */

#ifndef HEADER_PROJ_OBJ_H
#define HEADER_PROJ_OBJ_H

#ifdef  __cplusplus
extern "C" {
#endif

typedef enum
  {
    PROJ_OBJ_TYPE_NONE,
#include "obj_list"
  }PROJ_OBJ_TYPE;
	 
#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_OBJ_H */
