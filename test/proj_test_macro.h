/* 
   COPYRIGHT 
*/

/**
 * @file proj_test_macro.h
 */

#ifndef HEADER_PROJ_TEST_MACRO_H
#define HEADER_PROJ_TEST_MACRO_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "../src/common/proj_macro.h"
#define TEST_MAIN main
#define NAT_TEST_RUN(func,r) r=func();if(r!=0) goto end;
  
#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_TEST_MACRO_H */
