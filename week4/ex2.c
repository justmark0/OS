#include <stdio.h>
#include <unistd.h>

// start  this program as backgroung process using &
// and run pstree as was mentioned in the task
int main() {
  int pid;
  for (int i = 0; i < 3; i++)
    fork();
  sleep(5);
  return 0;
}
// This program created 8 processes when i < 3 because on each iteration it forked
// And each new process will start one more(using fork), so number of such processes is power of 2

// When i < 5 it will create 32 processes because of the same reason
