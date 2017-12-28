#include "proj_test.h"

static int new_and_free()
{
  NAT_FUNC_START(ret);
  OBJ *obj=NULL;

  NAT_CHECK_FUNC(OBJ_new(&obj),ret,end);

 end:
  OBJ_free(obj);

  NAT_FUNC_END(ret);
}
static int do_something()
{
  NAT_FUNC_START(ret);
  OBJ *obj=NULL;

  NAT_CHECK_FUNC(OBJ_new(&obj),ret,end);
  NAT_CHECK_FUNC(OBJ_do_something(obj),ret,end);

 end:
  OBJ_free(obj);

  NAT_FUNC_END(ret);
}
int TEST_MAIN(int argc,char **argv)
{
  NAT_FUNC_START(ret);

  /* Test implementations */
  NAT_TEST_RUN(new_and_free(),ret);
  NAT_TEST_RUN(do_something(),ret);

  NAT_TEST_RESULT(OBJ,ret);
  NAT_FUNC_END(ret);
}
