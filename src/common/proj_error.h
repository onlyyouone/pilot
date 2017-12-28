/* 
   COPYRIGHT 
*/

/**
 * @file proj_error.h
 * This file contains the error definitions for __product__ .
 */

#ifndef HEADER_PROJ_ERROR_H
#define HEADER_PROJ_ERROR_H

#ifdef  __cplusplus
extern "C" {
#endif

typedef enum
{
    PROJ_ERROR_NONE=0,
    PROJ_ERROR_FAILED,
    PROJ_ERROR_ALLOC_FAILURE,
    PROJ_ERROR_NULL_DATA,
    PROJ_ERROR_BAD_DATA,
    PROJ_ERROR_UNSUPPORTED,
}PROJ_ERR_ENUM;

#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_ERROR_H */

