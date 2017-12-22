#include "proj_test.h"

static int new_and_free()
{
  NAT_FUNC_START(ret);
  OBJ *obj=NULL;

  ret = OBJ_new(&obj);
  
  
  NAT_FUNC_END(ret);
}
int TEST_MAIN(int argc,char **argv)
{
  NAT_FUNC_START(ret);
  NAT_TEST_RUN(new_and_free,ret)
  
  NAT_FUNC_END(ret);
}
