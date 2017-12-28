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
/* TODO: I should not have this include file..  */
#include <stdio.h>
  
#include "../src/common/proj_macro.h"
#define TEST_MAIN main
#define PASS "passed"
#define FAIL "failed"

  
/* TODO: Implement proper TEST_printf that handles non-stdio */
#define TEST_printf fprintf
#define NAT_TEST_RUN(func,r) {int rr=0; rr=func; r+=rr;	\
    TEST_printf(stdout,"%s %s\n",#func, r==0? PASS:FAIL); }

#define NAT_TEST_RESULT(mod,r)  TEST_printf(stdout,"%s %s\n",#mod,r==0? PASS:FAIL);
  
#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_TEST_MACRO_H */
