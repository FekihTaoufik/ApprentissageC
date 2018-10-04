#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main (int argc , char *argv[]){
pid_t pids[10];
int exit_cond , i,n = 10;

for (i = 0; i < n; ++i) {
  if ((pids[i] = fork()) < 0) {
    perror("fork");
    abort();
  } else if (pids[i] == 0) {
    printf("Je suis le fils %d et mon pere est %d\n",getpid(),getppid());
    sleep(30);
    exit(0);
  }
}

int status;
pid_t pid;
while (n > 0) {
  pid = wait(&status);
  printf("Mon fils %d a terminé avec le résultat %d\n",pid,status);
  --n;
}
}

