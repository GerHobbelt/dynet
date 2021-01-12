#ifndef DYNET_MEM_DEBUG_H
#define DYNET_MEM_DEBUG_H

// See https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019 .

#ifdef _MSC_VER
#  define _CRTDBG_MAP_ALLOC
#endif

#include <stdlib.h>

#ifdef _MSC_VER
#  include <crtdbg.h>
#endif

void debugMem(const char* file, int line);

class MemDebug {
public:
  MemDebug(bool atExit = true);
  ~MemDebug();

  void debug();
};

#if defined(_DEBUG) && defined(_MSC_VER)
   // Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
   // allocations to be of _CLIENT_BLOCK type.
#  define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#  define DBG_NEW new
#endif

#endif
