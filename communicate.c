// Communication Process Lab3 Project

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigHandler (int);
int main()
{
 pid_t pid = fork();
 
 if (pid < 0) {
 perror("Fork Failed");
 exit(1);
 }

 else if (pid == 0) {
 int random_sec = (rand() % 5) + 1;
 sleep(random_sec);
 raise(SIGUSR1);
 }
 
 else {
 signal (SIGINT, sigHandler);
 signal (SIGUSR1, sigHandler);
 signal (SIGUSR2, sigHandler); 
 printf ("waiting...\n");
 pause();
 return 0;
}
}

void
sigHandler (int sigNum)
{
 if(sigNum == SIGINT){
 printf (" received an interrupt.\n");
 // this is where shutdown code would be inserted
 sleep (1);
 printf ("time to exit\n");
 exit(0);
 }

 else if (sigNum == SIGUSR1) {
 printf("recieved a SIGUSR1 signal");
 }

 else if (sigNum == SIGUSR2) {
 printf("recieved a SIGUSR2 signal");
 }
}
