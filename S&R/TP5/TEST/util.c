#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#include "util.h"
#include "id3_frame.h"
#include "id3_tagheader.h"

/*================================================*/
/* read_error -- print msgs + system error message and 
   exit */
int read_error(int fd, char *buff, int nb_alire, const char *msg){
  int nb_lu  = read(fd, buff, nb_alire);
  if (nb_lu == -1) perror(msg);
  return(nb_lu);
}

/*================================================*/
/* Affichage d'un buffer octet par octet      
   On peut choisir le format pour que cet octet 
   soit affiché comme un caractère (si on sait
   qu'il contient un code ASCII) ou comme un hexa
   si on n'a pas trop idée du codage utilisé
*/
void printf_buff(char *buf, int nb, char *format, char *label){
  int i;
  printf("\n%s : ", label); 
  for (i=0; i<nb; i++){
    printf(format, buf[i]); 
  }
  fflush(stdout);  
}


/*================================================*/
/* Decodage de la taille (sur 4 octets) d'un 
   tag ID3V2 
*/
int decode_taille(char t[4]){
  int i;
  int r = 0;
  for (i=3 ; i>=0 ; i--){
    /*printf("\n%x\n",t[i]);*/
    int masque = 0;
    masque = t[i] & 0x7FFFFFFF;
    masque <<= 7*(3-i);    
    r |=  masque;
  }
  return r;
}
/*================================================*/
/* Donne la taille du id3
*/
int sizeOfTag(int fd){

  char buff[4];
  lseek(fd, 6, SEEK_SET);
  read(fd, buff, 4);
  int res = decode_taille(buff);
  return res;

}
/*=====================================================*/
char *get_directory(char* argv){

  char *res = malloc(sizeof(argv));
  strcpy(res,argv);
  char tmp;
  int first = 1;
  for (int i = strlen(res); i > 0 ; i--){
    tmp = res[i];
    if (tmp == '/'){
      first = 0;
      break;
    }
    res[i] = '\0';
  }
  if(first)
    return ".";
  return res;
}
/*=====================================================*/
int file_exist(char * filename)
{
  FILE *file;
  char *point;
  if((point = strrchr(filename,'.')) != NULL ) {
      if(strcmp(point,".mp3")){
        printf("Erreur, le stdin doit etre un fichier MP3\n");
        exit(1); 
      }
                
  }
  if (file = fopen(filename, "r"))
    {
        fclose(file);
        return 1;
    }
    return 0;
}