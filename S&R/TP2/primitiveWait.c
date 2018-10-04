
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main (int argc , char *argv[]){
pid_t pids[10];
int i;
int n = 10;

for (i = 0; i < n; ++i) {
  if ((pids[i] = fork()) < 0) {
    perror("fork");
    abort();
  } else if (pids[i] == 0) {
    printf("Je suis le fils %d et mon pere est %d\n",getpid(),getppid());
    sleep(10);
    exit(0);
  }
}

int status;
pid_t pid;
while (n > 0) {
    printf("Pid du pere = %d\n",getpid());
    printf("Attente de la terminaison du fils...\n");
  pid = wait(&status);
  if(WIFEXITED(status)){
      printf("Le fils %d s'est terminé correctement : %d\n",pid,WEXITSTATUS(status));
  }else{
      printf("Le fils %d s'est mal termine :%d\n",pid, WTERMSIG(status));
  }
  --n;
}
}