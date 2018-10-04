#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void eliminer_zombie(int sig){
    int exit_cond;
    pid_t pid;
    printf("Attente de la terminaison du fils...\n");
    pid = wait ($exit_cond);
    #if 0
        while(waitpid (-1,&exit_cond,WNOHANG));
    #endif
        if(WIFEXITED(exit_cond))
            printf("Le fils %d s'est termine correctement : %d\n",pid,WEXITSTATUS(exit_cond));
        else
            printf("Le fils %d s'est mal termine : %d\n",pid,,WTERMSIG(exit_cond));    
}
int main (int argc,char *argv[]){
    struct sigaction action ;
    int i ;
    pid_t pid;

    for(i=0;i<2;i++){
        pid =fork();
        switch(pid){
            case -1 :
                perror("Erreur de création du processus");
                exit(1);
            case 0 :
                printf("Pid du fils = %d\n",getpid());
                if(i==0)
                    sleep(5);
                if(i==1)
                    sleep(10);
                exit(0);
        }
    }
    printf("\nPid du pere = %d\n",getpid());
    memset(&action,0,sizeof(action));
    action.sa_handler = eliminer_zombie;
    sigaction(SIGCHLD,&action,NULL);
    sleep(20);
    sleep(20);
    printf("Mort du pere!\n");
    exit(0);
}