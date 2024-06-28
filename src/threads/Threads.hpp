#include <pthread.h>

class Threads {
private:
  pthread_t threads_list;

public:
  Threads();
  ~Threads();
};
