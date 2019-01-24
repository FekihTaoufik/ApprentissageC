/* * Fichier wait . c :
création / terminaison propre d ’ un processus :
a ) On crée un fils .
b ) Le père attend la fin de celui - ci en testant la condition de sa fin .
On peut simuler une mauvaise fin en effectuant un ’ kill ’ du
processus fils . */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main ( int argc , char * argv []) {
int exit_cond; //pour recuperer le code de retour des fils
pid_t pidOne;

//Gestion du premier fils

pidOne = fork();
if(pidOne == -1){
	perror ("Erreur de création du premier processus");
	exit (1);
}
if(pidOne == 0) {
	printf ("\nPid du premier fils = %d" , getpid());
	sleep (2); /* Duree de vie du premier fils */
} else {

//Gestion du pere

printf ("\nPid du pere = %d" , getpid());
printf ("\nAttente de la terminaison du premier fils...\n");
pidOne = wait(&exit_cond);
if (WIFEXITED(exit_cond))
	printf("\nLe premier fils %d s’est termine correctement : %d\n" ,pidOne, WEXITSTATUS(exit_cond));
else
	printf("\nLe premier fils %d s’est mal termine : %d\n" ,pidOne, WTERMSIG(exit_cond));

//Gestion du second fils !

pid_t pidTwo;
pidTwo = fork();
if(pidTwo == -1){
	perror ("Erreur de création du second processus");
	exit (1);
}
if(pidTwo == 0){
	printf ("\nPid du second fils = %d" , getpid());
	sleep (5); //Duree de vie du second fils
} else {
	printf ("\nAttente de la terminaison du second fils...\n");
	pidTwo = wait(&exit_cond);
	if (WIFEXITED(exit_cond))
		printf ("\nLe second fils %d s’est termine correctement : %d\n" ,pidTwo, WEXITSTATUS(exit_cond));
	else
		printf ("\nLe second fils %d s’est mal termine : %d\n" ,pidTwo, WTERMSIG(exit_cond));
	}
}
exit(0); /* exécuté par les fils et leur père */
}
