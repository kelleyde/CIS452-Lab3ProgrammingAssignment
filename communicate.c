// Communication Process Lab3 Project

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

void sigHandler (int);
int main()
{
 signal (SIGINT, sigHandler);
 signal (SIGUSR1, sigHandler);
 signal (SIGUSR2, sigHandler);
 pid_t pid = fork();

 if (pid < 0) {
 perror("Fork Failed");
 exit(1);
 }
 
 else if (pid == 0) {
 while(true){
 int random_sec = (rand() % 5) + 1;
 sleep(random_sec);

 int ran_sig = rand();
 if((ran_sig % 2) == 1){
 kill(getppid(), SIGUSR1);
 }

 if((ran_sig % 2) == 0){
 kill(getppid(), SIGUSR2);
 }

 }
 }

 
 else {
 while(true){ 
 printf ("waiting...\n");
 pause();
 // return 0;
}
}
}

void
sigHandler (int sigNum)
{
 if(sigNum == SIGINT){
 printf (" received an interrupt.\n");
 sleep (1);
 printf ("That's it, I'm shutting you down...\n");
 exit(0);
 }

 else if (sigNum == SIGUSR1) {
 printf("recieved a SIGUSR1 signal");
 }

 else if (sigNum == SIGUSR2) {
 printf("recieved a SIGUSR2 signal");
 }
}
