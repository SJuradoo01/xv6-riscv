#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  for (int i = 0; i < 3; i++) {
    if (fork() == 0) {
      int me = getpid();

      for (int r = 0; r < 5; r++) {
        for (volatile long j = 0; j < 50000000; j++);
        printf("hijo %d ronda %d\n", me, r);
      }

      exit(0);
    }
  }

  for (int i = 0; i < 3; i++)
    wait(0);

  exit(0);
}
