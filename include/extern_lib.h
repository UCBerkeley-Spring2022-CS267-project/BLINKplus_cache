#pragma once
#include <cstdlib>
#include <string>

#include <dlfcn.h>

extern void* handle;

static void check_dl_error() {
    char* error = dlerror();
    if (error != NULL) {
      fprintf(stderr, "%s\n", error);
      exit(EXIT_FAILURE);
    }
}

// TODO: Caching for dlsym
// dlsym does not cache it's results. May lead to bad performance
template<typename T>
T execute_loaded_function(std::string func_name) {
  T c;
  *(void **)(&c) = dlsym(handle, func_name.c_str());
  check_dl_error();
  return std::move(c);
}

#define EXTERN_LIB(name, ...) execute_loaded_function<decltype(&name)>(#name)(__VA_ARGS__)
