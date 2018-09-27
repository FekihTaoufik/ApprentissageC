/* -----------------------------------------------------------------
* file : fork0.c 
* This program illustrates the use of fork() and
* getpid() system calls.  

* Note that write() is used instead of * printf() since the latter
* is buffered while the former is not. 
*
*  ps , pstree , top , kill
----------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 1000
#define BUF_SIZE 50
int main(void)
{
    pid_t pid;
    int i;
    char buf[BUF_SIZE];

    fork();
    pid = getpid();

    for (i = 1; i <= MAX_COUNT; i++)
    {
        sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
        write(1, buf, strlen(buf)); /* write pour eviter la bufferisation */
        //usleep(100000);
    }
        sprintf(buf, "JE SUIS EN MODE ZOMBIE pid %d\n", pid, i);
        write(1, buf, strlen(buf)); /* write pour eviter la bufferisation */


}

/* 
1. Comprendre et Expérimenter ce code.
2. Augmenter d’un facteur 10 le nombre d’itérations (MAX_COUNT).Qu’est-ce qui se passe ?
3. Vous obtenez un résultat/affichage ? Pouvez vous garantir que tout lancement à venir produira le même
résultat ?
4. Une fois que vous avez compris que c’est l’ordonnanceur (scheduler) du système Linux qui décide
de l’ordre d’exécution, est-ce que vous pouvez proposer un critère qui selon vous est utilisé par cet
ordonnanceur pour prendre ses décisions ?
*/
