#include <stdio.h>
#include <hybris/dlfcn/dlfcn.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
  void *handle;
  void (*bar)(void);
  void (*foo)(void);
  handle = hybris_dlopen("libfoo.so",0x02); //RTLD_LAZY = 0x00001; RTLD_NOW = 0x00002
  printf("xxx----------------------------->%s(), line = %d\n",__FUNCTION__,__LINE__);
  if(NULL == handle){
    printf("%s(), line = %d, hybris_dlopen failed: %s\n",__FUNCTION__,__LINE__,strerror(errno));
    return -1;
  }
  printf("xxx----------------------------->%s(), line = %d\n",__FUNCTION__,__LINE__);
  bar = (void(*)(void))hybris_dlsym(handle,"_Z3barv");

  if(NULL == bar){
    printf("%s(), line = %d, hybris_dlsym failed: %s\n",__FUNCTION__,__LINE__,strerror(errno));
    return -1;
  }
  foo = (void(*)(void))hybris_dlsym(handle,"_Z3foov");
  if(NULL == foo){
    printf("%s(), line = %d, hybris_dlsym failed: %s\n",__FUNCTION__,__LINE__,strerror(errno));
    return -1;
  }
     
  foo();
  printf("xxx----------------------------->%s(), line = %d\n",__FUNCTION__,__LINE__);
  bar();
  hybris_dlclose(handle);
  printf("xxx----------------------------->%s(), line = %d\n",__FUNCTION__,__LINE__);
  return 0;
}
