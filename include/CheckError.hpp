// CHECKERROR_HPP
#ifndef __CHECKERROR_HPP_21543
#define __CHECKERROR_HPP_21543

#include <cstdio>

static const char *_getErrorEnum(cudaError_t error) {
		return cudaGetErrorName(error);
}

template <typename T>
void Check(T result, char const * const func, const char * const file, int const line) {
  if (result) {
    fprintf(stderr, "Error at %s:%d code=%d(%s) \"%s\" \n", file, line, static_cast<unsigned int>(result), _getErrorEnum(result), func);
    exit(EXIT_FAILURE);
  }
}

#define CheckErrors(val) Check((val), #val, __FILE__, __LINE__)

inline void CheckKernelError() {

  // always check for synchronous errors from kernel launch
  CheckErrors(cudaGetLastError());
  
  // only wat to do cuda device synchronize when we're debugging DISABLE before release
  #ifndef NDEBUG
    CheckErrors(cudaDeviceSynchronize());
  #endif

}

#endif // CHECKERROR_HPP_21543
