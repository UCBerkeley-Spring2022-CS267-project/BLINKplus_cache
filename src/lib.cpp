#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <dlfcn.h>

#include "extern_lib.h"

void* handle;
// see https://stackoverflow.com/questions/9759880/automatically-executed-functions-when-loading-shared-libraries
static void lib_con() __attribute__((constructor));

static void lib_con() {
  // TODO: Better way to find out dependent
  handle = dlopen("/usr/lib/x86_64-linux-gnu/libnccl.so.2", RTLD_LAZY);
  check_dl_error();
}

static void lib_dis() __attribute__((destructor));

static void lib_dis() {
    dlclose(handle);
    check_dl_error();
    exit(EXIT_SUCCESS);
}
