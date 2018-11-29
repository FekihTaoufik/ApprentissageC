/*
 * extract MP3 tag frames
 * *
 * Author: Cardini Yannick
 * Created: 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <arpa/inet.h>

#include "util.h"
#include "id3_tagheader.h"
#include "id3_frame.h"
#include "repertoire.h"


/*=====================================================*/
int main(int argc, char *argv[]){
 
  char *filename,*directory;
  int nb_lu;
  int i;


  if (argc != 2){ 
    fprintf(stderr, "Usage: %s mp3file\n", argv[0]);
    exit(1);
  }
  else{
    if (file_exist(argv[1])){
        filename = argv[1];
        directory = get_directory(argv[1]);
    }
    else{
      printf("file:%s dosen't exist\n", argv[1]);
      exit(1);
    }
  }
  
///////////////////Creer un repertoire au nom d'album//////////
creer_repertoire(directory,filename);

  sync();
  return 0;
}
/*=====================================================*/