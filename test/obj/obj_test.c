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
static int set_get()
{
  NAT_FUNC_START(ret);
  OBJ *obj=NULL;
  PROJ_DATA set_data;
  PROJ_DATA get_data;
  int int_expected=0xff;
  char *str_expected="Hello OBJ";
  
  NAT_CHECK_FUNC(OBJ_new(&obj),ret,end);

  /* Set data to OBJ  */
  Memset(&set_data,0x00,sizeof(set_data));
  set_data.d.int_d=int_expected;
  NAT_CHECK_FUNC(OBJ_set(obj,OBJ_PROP_INT_DATA,&set_data),ret,end);

  Memset(&set_data,0x00,sizeof(set_data));
  set_data.d.char_p=str_expected;
  NAT_CHECK_FUNC(OBJ_set(obj,OBJ_PROP_STR_DATA,&set_data),ret,end);

  /* Get data from OBJ and ensure they are expected */
  Memset(&get_data,0x00,sizeof(get_data));
  NAT_CHECK_FUNC(OBJ_get(obj,OBJ_PROP_INT_DATA,&get_data),ret,end);
  NAT_TEST_EQL_INT(get_data.d.int_d,int_expected,ret,end);
  
  Memset(&get_data,0x00,sizeof(get_data));
  NAT_CHECK_FUNC(OBJ_get(obj,OBJ_PROP_STR_DATA,&get_data),ret,end);
  NAT_TEST_EQL_STR(get_data.d.char_p,str_expected,ret,end);

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
  NAT_TEST_RUN(set_get(),ret);
  NAT_TEST_RUN(do_something(),ret);

  NAT_TEST_RESULT(OBJ,ret);
  NAT_FUNC_END(ret);
}
