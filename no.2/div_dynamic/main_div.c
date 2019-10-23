#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

void main() 
{ 
  void *handle; 
  int (*div)(int, int); 
  char *error;
  handle = dlopen ("./lib/lib_div.so", RTLD_LAZY); 
  if (!handle) 
  { 
    fputs (dlerror(), stderr); 
    exit(1); 
  }
  div = dlsym(handle, "div"); 
  if ((error = dlerror()) != NULL) 
  { 
    fprintf (stderr, "%s", error); 
    exit(1); 
  }
  printf ("div(1,2)=%d\n", (*div)(1,2));
  dlclose(handle);
}

