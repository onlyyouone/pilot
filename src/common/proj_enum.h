/* 
   COPYRIGHT 
*/

/**
 * @file proj_enum.h
 * This file contains enumration to determine the data type. 
 */

#ifndef HEADER_PROJ_ENUM_H
#define HEADER_PROJ_ENUM_H

#ifdef  __cplusplus
extern "C" {
#endif

#define DATA_GEN(NAME)   NAME,			\
    NAME ## _P,					\
    NAME ## _PP 
  
typedef enum
    {
      /* Defailt data */
      PROJ_TYPE_NONE,
      DATA_GEN(PROJ_TYPE_INT),
      DATA_GEN(PROJ_TYPE_UINT),
      DATA_GEN(PROJ_TYPE_CHAR),
      DATA_GEN(PROJ_TYPE_UCHAR),

      /* Generated  */
      DATA_GEN(PROJ_TYPE_OBJ),

}PROJ_DATA_TYPE;

#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_ENUM_H */
