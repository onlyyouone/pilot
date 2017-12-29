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

#define NAT_TEST_EQL_INT(a,b,r,label)  if(a!=b) {TEST_printf(stdout,"Expected %d but got %d\n",b,a);r=PROJ_ERROR_FAILED;goto label;}

#define NAT_TEST_EQL_STR(a,b,r,label)  if(Strncmp(a,b,strlen(b))) {TEST_printf(stdout,"Expected %s but got %s\n",b,a);r=PROJ_ERROR_FAILED;goto label;}

  
#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_TEST_MACRO_H */
