#define _SC_PAGESIZE 1
#define _SC_PAGE_SIZE _SC_PAGESIZE
#define _SC_NPROCESSORS_ONLN 2
#define _SC_NPROCESSORS_CONF 2

namespace folly {
namespace portability {
namespace unistd {

long sysconf(int tp) {
  switch (tp) {
    case _SC_PAGESIZE: {
      return 0x1000;
    }
    case _SC_NPROCESSORS_ONLN: {
      return 4;
    }
    default:
      return -1L;
  }
}

}}}

namespace {

  struct timeval {
    long    tv_sec;         /* seconds */
    long    tv_usec;        /* and microseconds */
  };

  struct rusage {
    timeval ru_utime;
    timeval ru_stime;
    long ru_maxrss;
    long ru_ixrss;
    long ru_idrss;
    long ru_isrss;
    long ru_minflt;
    long ru_majflt;
    long ru_nswap;
    long ru_inblock;
    long ru_oublock;
    long ru_msgsnd;
    long ru_msgrcv;
    long ru_nsignals;
    long ru_nvcsw;
    long ru_nivcsw;
  };
}

#include <cstring>

extern "C" {

int getrusage(int /* who */, rusage* usage) {
  memset(usage, 0, sizeof(rusage));
  return 0;
}

}
