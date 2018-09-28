#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main (int argc , char *argv[]){
  int pid ;
  switch (pid = fork()){
    case -1 : 
      perror("Erreur du fork");
      exit(1);
    case 0:
      printf("Je suis le fils : PID %d et le PID de mon pere est %d\n",getpid(),getppid());
      printf("Je suis le fils et je meurs : PID %d\n",getpid());
      break;
    default : 
      printf("\nJe suis le pere : PID %d\n",getpid());
      printf("Qu'est devenu mon fils %d\n",pid);
      printf("Vous avez 30 sec pour lancer un ""pis -e -f"" et constater qu'il est zombi !\n");
      sleep(40);
      printf("Je suis le pere, et je meurs : PID %d\n",getpid());
  }
  printf("\n");
  exit(0);
}

