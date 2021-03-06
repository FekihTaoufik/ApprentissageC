#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LSH_TOK_BUFSIZE 64 //taille du bloc initial alloué pour l'input de l'user
#define LSH_TOK_DELIM " \t\n"

/*======================================================*/
char* sh_read_line(void) {
	char* line = NULL;
	ssize_t bufsize = 0; // donc getline realise l’allocation
	getline (&line, &bufsize, stdin);
	return line;
}

/*======================================================*/
char** sh_split_line (char* line) { //Parse l'input en utilisant strtok() pour faire des tokens a partir du contenu de LSH_TOK_DELIM
	int bufsize = LSH_TOK_BUFSIZE , position = 0;
	char** tokens = malloc (bufsize *sizeof (char*));
	char* token;
	if (!tokens) {
		fprintf (stderr, "lsh : allocation error\n" );
		exit(EXIT_FAILURE);
	}
	token = strtok(line, LSH_TOK_DELIM) ;
	while (token != NULL) {
		tokens [position] = token;
		position++;
		if (position >= bufsize) { //Si on depasse du buffer, on refait une allocation
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				fprintf (stderr, "lsh : allocation error \n");
				exit (EXIT_FAILURE);
			}
		}
		token = strtok (NULL, LSH_TOK_DELIM);
	}
	tokens [position] = NULL;
	return tokens;
}
/*======================================================*/
int sh_execute (char ** args) {
	int exit_cond;
	pid_t pid;
	pid = fork();
	if(pid == -1){
		perror ("Erreur fork");
		exit (1);
	} 
	if(pid == 0) {
		//printf ("\nPid du premier fils = %d", getpid());
		if(execvp(args[0], args) == -1){
			perror("Erreur exec ");
			exit (EXIT_FAILURE);
		}
	} else {
		pid = wait(&exit_cond);
		if (WIFEXITED(exit_cond))
			printf("Le processus fils %d s’est termine correctement : %d\n" ,pid, WEXITSTATUS(exit_cond));
		else
			printf("Le processus fils %d s’est mal termine : %d\n" ,pid, WTERMSIG(exit_cond));
	}
	return 1;
}
/*======================================================*/
void sh_loop (void) {
	char *prompt = "l3miage shell > " ;
	char *line ;
	char **args ;
	int status ;
	int check;
	do {
		printf("%s", prompt); //Afficher le prompt
		fflush (stdout); //Nettoyer le buffer de sortie
		line = sh_read_line(); //Lire la ligne
		check = check_forbidden(line);
		if(check != -1){
			args = sh_split_line(line); //Parse la ligne
			status = sh_execute (args); //Executer la ligne
		} else {
			printf("Commande interdite !\n");
		}
		/*sh_free(line); */
		/*sh_free(args); */
	} while (status);
}

/*======================================================*/

int check_forbidden(char * args){
	char *forbiddenWords[4] = {"mp3", "mp4", "youtube", "avi"};
	char *controlParental;
	int i;
	for(i = 0; i < 4; i++){
		controlParental = strstr(args, forbiddenWords[i]);
		//printf("valeur i : %d\n", i);
		if(controlParental != NULL)
			return -1;
	} 
	return 1;
}

/*======================================================*/

int main (int argc, char *argv[]) {
	// Init : Load config files, if any
	// Interp : Run Command loop
	sh_loop();
	// Termin : Perform any shutdown / cleanup
	return EXIT_SUCCESS ;
}
