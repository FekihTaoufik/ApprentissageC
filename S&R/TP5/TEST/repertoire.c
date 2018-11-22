#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>


#include "util.h"
#include "id3_frame.h"

/*=====================================================*/
char** ls_mp3files_inarray(char * directory){
  DIR *dir,*diri;
  struct dirent *dp;
  char *point;
  int cmpt = 0,i =0;
  dir = opendir(directory);
  int taille_du_malloc;


  if (ENOENT == errno)
  {
    printf("Repertoire \" %s \" inexistant\n",directory);
    exit(1);
  }

  while ((dp=readdir(dir)) != NULL) {
    if((point = strrchr(dp->d_name,'.')) != NULL ) {
        if(!strcmp(point,".mp3"))
            cmpt+=sizeof(dp->d_name);       
    }
  }
  closedir(dir);
  char **res = malloc(cmpt);
  diri = opendir(directory);

  while ((dp=readdir(diri)) != NULL) {
    if((point = strrchr(dp->d_name,'.')) != NULL ) {
        if(!strcmp(point,".mp3")){
          res[i] = dp->d_name;
          i++;
        }            
    }
  }

  closedir(diri);
  return res;
}
/*=====================================================*/
char* get_album(char* directory,char* filename){

  char** lf = ls_mp3files_inarray(directory);

  char nom_album[10000];
  char* path = malloc(sizeof(directory) + sizeof(lf[0]) + 1);

  strcpy(path,directory);//start with strcpy, never start strcat with null pointer
  strcat(path,"/");
  strcat(path,lf[0]);
  FILE *f;
  if (! (f = fopen(filename, "r"))){
    perror(filename);
    exit(1);
  }
  int fd = fileno(f);
  mp3_get_frame_from_id(fd, "TALB", nom_album);
  fclose(f);
  char* res = nom_album;
  free(path);
  free(lf);

  return res;
}
/*=====================================================*/
void move_files(char* directory,char* path){//pas tres propre voir avec le prof si viable

  FILE *f;
  int fd;
  char **files = ls_mp3files_inarray(directory);
  
  int len = sizeof(files);


  char new_name[100];
  char new_path[100];
  char old_path[100];//je n'ai pas reussi avec malloc et realloc demander au prof
  char trck[10] = ""; 
  char tit2[100] = ""; 
  strcpy(old_path,directory);


  for (int i=0;i < len; i++){
       
    strcpy(old_path,directory);  
    strcat(old_path,"/");
    strcat(old_path,files[i]);
     printf("%s\n",files[i]);
    printf("old_path:%s\n",old_path );

    if (! (f = fopen(old_path, "r"))){
      perror(old_path);
      exit(1);
    }
    fd = fileno(f);

    mp3_get_frame_from_id(fd, "TIT2", tit2);
    mp3_get_frame_from_id(fd, "TRCK", trck);

    fclose(f);
    
    strcpy(new_name,tit2);
    strcat(new_name,"_");
    strcat(new_name,trck);
    strcat(new_name,".mp3");
    printf("new_name:%s\n",new_name );

    strcpy(new_path,path);
    strcat(new_path,"/");
    strcat(new_path,new_name);


    int err = rename(old_path,new_path);
    if (err == -1)fprintf(stderr, "Echec deplacement du fichier: %s\n", strerror(errno));

  }
}
/*=====================================================*/
void creer_repertoire(char* directory,char* filename){

  char* album = get_album(directory,filename);

  int err;
  char *path;

  if(strlen(album) > 10){
    char new_album[10] = "";
    for (int i = 0; i< 10; i++)
      new_album[i] = album[i];
    path = malloc(sizeof(directory) + sizeof(new_album) + 1);
    strcpy(path,directory);
    strcat(path,"/");
    strcat(path,new_album);
  }
  else{
    path = malloc(sizeof(directory) + sizeof(album) + 1);
    strcpy(path,directory);
    strcat(path,"/");
    strcat(path,album);
  }
  // Create the directory
  err = mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  /* S_IRWXU owner has read, write, and execute permission
     S_IRWXG group has read, write, and execute permission
     S_IROTH others have read permission
     S_IXOTH others have execute permission */
  if (err == -1)fprintf(stderr, "Folder creation failed: %s\n", strerror(errno));
  move_files(directory,path);
  
}
