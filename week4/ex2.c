#include <stdio.h>
#include <unistd.h>

// start  this program with as backgroung process using &
// and run pstree as was mwntioned in task
int main() {
  int pid;
  for (int i = 0; i < 3; i++)
    fork();
  sleep(5);
  return 0;
}
// this program created 8 processes when i < 3 because on each iteration it fork (start one new process)
// And each new process will start one more, so number of such processes is power of 2

// When i < 5 it will create 32 processes because of the same reason
