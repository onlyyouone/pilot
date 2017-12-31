/* 
   COPYRIGHT 
*/

/**
 * @file proj_macro.h
 * This header contains macros used in implementation and tests. 
 */

#ifndef HEADER_PROJ_MACRO_H
#define HEADER_PROJ_MACRO_H

#ifdef  __cplusplus
extern "C" {
#endif

#define Malloc malloc  
#define Memset memset
#define Memcmp memcmp
#define Memcpy memcpy
#define Free   free
#define Strlen    strlen
#define Strncmp   strncmp
#define Strncpy   strncpy
  
#define NAT_FUNC_START(r)      int r=0;
#define NAT_FUNC_END(r)        return r;
#define NAT_FUNC_VOID_END()    return;
#define NAT_MALLOC_STRUCT(pt,str,r,lab) pt=Malloc(sizeof(str)); \
  if (!pt){r=PROJ_ERROR_ALLOC_FAILURE;goto lab;}		  \
  Memset(pt,0x00,sizeof(str));

#define NAT_CHECK_IS_NOT_NULL(d,r,tag) if(d==NULL)	\
    {r=PROJ_ERROR_NULL_DATA;goto tag;}

#define NAT_CHECK_FUNC(func,param,label)  param=func;\
  if( param != PROJ_ERROR_NONE)						\
    {									\
      goto label ;							\
    }

#define NAT_CHECK_IS_NOT_ZERO_LEN(str,ret, label) if( Strlen(str) == 0) \
    {									\
      ret=PROJ_ERROR_BAD_DATA;						\
      goto label ;							\
    }

#define NAT_STRDUP(from,to)  proj_strdup(from,to);
  
#define NAT_FREE(a) if(a) Free(a)
  
#define NAT_TRUE     1
#define NAT_FALSE    0

#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_MACRO_H */
