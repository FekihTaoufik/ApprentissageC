#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LSH_TOK_BUFSIZE 64 //taille du bloc initial alloué pour l'input de l'user
#define LSH_TOK_DELIM " \t\n"

int intern_cmd(char **args);
int check_forbidden(char * args);

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
char **split_forbidden_words(char *forbiddenWords) { //reprise de sh_split_line adaptée pour découper notre var env FORBIDDEN
    int bufsize = LSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;
    char *delimiter = ":";
    char *forbiddenToStrtok = malloc(strlen(forbiddenWords) + 1);
    strcpy(forbiddenToStrtok, forbiddenWords);
    if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(forbiddenToStrtok, delimiter);
    while (token != NULL) {
        tokens[position] = token;
        position++;
        if (position >= bufsize) {
            bufsize += LSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, delimiter);
    }
    tokens[position] = NULL;
    return tokens;
}
/*======================================================*/
int sh_execute (char ** args) {
	int i, exit_cond;
	pid_t pid;
	pid = fork();
	if(pid == -1){
		perror ("\nErreur fork\n");
		exit(1);
	} 
	if(pid == 0) {
		if(intern_cmd(args) == -1){ //intern_cmd est supposée renvoyer 0 ou 1
			perror("\nErreur syntaxe intern_cmd : newf arg OU rmf arg\n");
			exit(1);
		} 
		if(execvp(args[0], args) == -1){
			perror("\nErreur exec\n");
			exit(1);
		}
	}else{
		pid = wait(&exit_cond);
		if (exit_cond == SIGINT) //Si le code de retour du fils correspond a un SIGINT, on interrompt le pere (= on exit notre Shell)
			exit(0);
		else
			printf("\nLe processus fils %d a pris fin : %d\n\n" ,pid, WTERMSIG(exit_cond));
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
			printf("\nCommande interdite !\n\n");
		}
		/*sh_free(line); */
		/*sh_free(args); */
	} while (status);
}
/*======================================================*/
int intern_cmd(char **args){
	char *myOwnCmd[3] = {"exit", "newf", "rmf"};
	int i;
	int switchParam;
	for(i = 0; i < 3; i++){
		if(strcmp(args[0], myOwnCmd[i]) == 0){
			switchParam = i + 1;
			break;
		}
	}
	switch(switchParam){
		case 1:
			printf("\nCommande exit ! Bye\n\n");
			kill(getpid(), SIGINT); //On interrompt le processus courant (= fils zombie impossible + envoie du code de retour au pere)
			break;
		case 2:
			if (args[1] == NULL) {
            			return -1;
        		}
			printf("\nCommande newf !");
			if(getenv("FORBIDDEN")){
				char *forbiddenEnv = getenv("FORBIDDEN");
				char *addedForbidden = malloc(strlen(forbiddenEnv) + strlen(args[1]) + 2); //creation d'une nouvelle chaine avec la taille adaptée
				char exp[6] = "export";
				printf("\nOn a %s\n", exp);
				strcat(addedForbidden, forbiddenEnv); //On passera par notre chaine "buffer" addedForbidden pour faire nos modifications
				strcat(addedForbidden, ":"); //On met ensuite a jour FORBIDDEN a partir notre chaine modifiée via strcat()
				strcat(addedForbidden, args[1]); //Resultat devrait etre "mp3:mp4:youtube:avi:arg1"
				setenv("FORBIDDEN", addedForbidden, 1); //On met a jour notre var env FORBIDDEN avec cette nouvelle chaine
				printf(" Le mot %s a été ajouté dans FORBIDDEN !\n\n", args[1]);
				return 1;
			} else {
				perror(" Erreur $FORBIDDEN non defini "); //Si l'user oublie de faire export FORBIDDEN="mp3 :mp4 :youtube :avi" en amont dans le Shell qui lance notre Shell !
				exit(1);
			} 
		case 3:
			if (args[1] == NULL) {
            			return -1;
        		}
			printf("\nCommande rmf ! ");
			if(getenv("FORBIDDEN")){
				char *forbiddenEnv = getenv("FORBIDDEN");
				char *removedForbidden = malloc(strlen(forbiddenEnv) - strlen(args[1]) - 2); //Meme principe que pour la commande newf
				char **forbiddenTab = split_forbidden_words(forbiddenEnv);
				int sizeTab = sizeof(forbiddenTab)/sizeof(char**); //taille de forbiddenTab
				int i;
				for (i = 0; i < sizeTab - 1; i++) {
				    strcat(removedForbidden, forbiddenTab[i]);
				    if (i != sizeTab - 2)
					strcat(removedForbidden, ":");
				}
				setenv("FORBIDDEN", removedForbidden, 1);
				printf(" Le mot %s a été retiré de FORBIDDEN !\n", args[1]);
				return 1;
			} else {
				perror(" Erreur $FORBIDDEN non defini "); //Si l'user oublie de faire export FORBIDDEN="mp3 :mp4 :youtube :avi" en amont dans le Shell qui lance notre Shell !
				exit(1);
			} 
		default : 
			return 0; //Quand aucune commande interne ne correspond a l'input de l'utilisateur
	}
	return -1; //On ne devrait théoriquement jamais arriver à ce return ou bien c'est qu'il y a un probleme dans la fonction
}
/*======================================================*/
int check_forbidden(char * args){ //Fonction identique a celle de la V1 mais utilisant la var env FORBIDDEN au lieu d'un array codé en dur
	if(getenv("FORBIDDEN")){
		char *forbiddenEnv = getenv("FORBIDDEN");
		char **forbiddenWords = split_forbidden_words(forbiddenEnv); //On split la var env FORBIDDEN avec délimeur ":" pour conserver un array
		char *controlParental;
		int i;
		int sizeTab = sizeof(forbiddenWords)/sizeof(char**); //taille de forbidden
		for(i = 0; i < sizeTab; i++){
			controlParental = strstr(args, forbiddenWords[i]);
			if(controlParental != NULL)
				return -1;
		}
	} else {
		perror("Erreur $FORBIDDEN non defini "); //Si l'user oublie de faire export FORBIDDEN="mp3 :mp4 :youtube :avi" en amont dans le Shell qui lance notre Shell !
		exit(1);
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
