#include <stdio.h>
#include <stdlib.h>

void foo(void)
{
  printf("foo---------------------->%s(), line = %d, Invoke foo() Success!\n",__FUNCTION__,__LINE__);
}

void bar(void)
{
  printf("foo---------------------->%s(), line = %d, Invoke bar() Success!\n",__FUNCTION__,__LINE__);
}
