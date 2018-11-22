/*
 * extract MP3 tag frames
 * *
 * Author: Gilles MENEZ
 * Created: 2018
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <errno.h>

extern int errno ;

#include "util.h"
#include "id3_tagheader.h"
#include "id3_frame.h"


/*============================================*/
void fill_frame(frame_data *frame, int fd){
 int ID3Size = sizeOfTag(fd);
 char tmp[10000];
 //on suppose qu'il n'y a pas d'extend header donc +10
 lseek(fd,10,SEEK_SET);
 ID3Size -= 10;
 while(ID3Size > 0){//si ya pas de padding
	 read(fd,tmp,1);
	 if (tmp[0] == 0)//si padding
	 	break;
	 tmp[0] = '\0';
	 lseek(fd,3,SEEK_CUR);
	 read(fd,tmp,4);
	 frame->tailleframe[frame->nbr_frame] = decode_taille(tmp) +10;//+10 cause size of header
	 frame->nbr_frame += 1;
	 ID3Size -= decode_taille(tmp) +10; 
	 lseek(fd,decode_taille(tmp)+2,SEEK_CUR);//+2 a cause des flags
 }
}
/*============================================*/
int mp3_get_frame_from_id(int fd,char* id,char* contenu){

  int parcourir = 0,nb_lu = 10;


  //on suppose qu'il n'y a pas de extended tagheader
  frame_data *frame = malloc(sizeof(frame_data));
  frame->nbr_frame = 0;
  fill_frame(frame,fd);
  char tmp[4] = "";
  lseek(fd, 10, SEEK_SET);//on passe le taghseader

  while(parcourir < frame->nbr_frame ){

  	int err;
    err = read(fd, tmp, 4);//read renvoie le nbr d'octect lu, si erreur renvoie -1
    if (err == -1)fprintf(stderr, "Value of errno: %d\n", errno);
    
    if (!strcmp(tmp,id)){
    	lseek(fd, 7, SEEK_CUR);//6 pour le header + 1 octet pour donner le type de codage utilisé pour le texte qui va suivre,
    	err = read(fd, contenu, frame->tailleframe[parcourir] - 11);//taille du frame - (header + codage)
    	if (err == -1)fprintf(stderr, "Value of errno: %d\n", errno);
      return 0;
    }
    lseek(fd,frame->tailleframe[parcourir] -4,SEEK_CUR);//-4 car read fait avancer de 4
  	parcourir++;
  }


  return -1;
}0;
    }
    lseek(fd,frame->tailleframe[parcourir] -4,SEEK_CUR);//-4 car read fait avancer de 4
  	parcourir++;
  }


  return -1;
}