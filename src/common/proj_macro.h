/* 
   COPYRIGHT 
*/

/**
 * @file proj_macro.h
 * This file contains macros used for implementation. 
 */

#ifndef HEADER_PROJ_MACRO_H
#define HEADER_PROJ_MACRO_H

#ifdef  __cplusplus
extern "C" {
#endif

#define Malloc malloc  
#define Memset memset
#define Free   free
  
#define NAT_FUNC_START(r)      int r=0;
#define NAT_FUNC_END(r)        return r;
#define NAT_FUNC_VOID_END()    return;
#define NAT_MALLOC_STRUCT(tmp,str,r,lab) tmp=Malloc(sizeof(str)); \
  if (!tmp){r=PROJ_ERROR_ALLOC_FAILURE;goto lab;}		  \
  Memset(tmp,0x00,sizeof(str));

#define NAT_CHECK_IS_NOT_NULL(d,r,tag) if(d==NULL)	\
    {r=PROJ_ERROR_NULL_DATA;goto tag;}

#define NAT_CHECK_FUNC(func,param,label)  param=func;\
  if( param != PROJ_ERROR_NONE)						\
    {									\
      goto label ;							\
    }

#define NAT_CHECK_IS_NOT_ZERO_LEN(param,ret, label) if( Strlen(param) == 0) \
    {									\
      ret=PROJ_ERROR_BAD_DATA;						\
      goto label ;							\
    }


#define NAT_FREE(a) if(a) Free(a)
  
#define NAT_TRUE     1
#define NAT_FALSE    0
	 
#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_MACRO_H */
