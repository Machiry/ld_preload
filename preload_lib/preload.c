#include <stdio.h>
#define __USE_GNU
#include <dlfcn.h>
typedef FILE* (*orig_fopen_func_type)(const char *path, const char *mode);
FILE *fopen(const char *path, const char *mode) {
    printf("In LD_PELOAD Function\n");
	orig_fopen_func_type orig_func;
    orig_func = (orig_fopen_func_type)dlsym(RTLD_NEXT, "fopen");
    return orig_func(path,mode);
}
