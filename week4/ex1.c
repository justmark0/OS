#include <stdio.h>
#include <unistd.h>

int main() {   
    for(int i = 0 ; i < 10; i++){ // running for 10 times
        int n = getpid();
        
        pid_t pid = n;
        n = fork();
    
        if (n < 0)
          continue; // if some error appeard  just skip this iteration 
        else if (n > 0) // condition for parent process 
          printf("Hello from parent [PID - %d]\n", n);
        else // itf it is greater than 0 it is child
          printf("Hello from child [PID - %d]\n", n);
    }
  return 0;
}
