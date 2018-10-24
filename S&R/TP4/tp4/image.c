#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include <string.h>
#include <math.h>


image *lecture_image(FILE *f){

	image *img = malloc(sizeof(image));
	int ch ; 
  char tmp[SIZECOMMENT];
  char bob[3];
  int i = 0;

  fscanf(f,"%s",img->nm);

  do{
    ungetc(ch,f);
    fgets(tmp,SIZECOMMENT,f);
    strcat(img->comments,tmp);
    ch = fgetc(f);
  }while(ch == '#');

  ungetc(ch,f);
  fscanf(f,"%d",&img->nl);//550
  fscanf(f,"%d",&img->nc);//386
  fscanf(f,"%d",&img->ng);//255

  ch = fgetc(f);
  while (ch != EOF){
    ch = fgetc(f);
    img->pixels[i] = ch;
    i++;
  }
  
  return img;
}
////////////////////////////////////////////////
void inverse_image(image *img){

  int i,n,o,u,j,pos,new_pixel,gris,old_pixel;
  char boby[900000];//quand je remplace 900.000 par NMAX*NMAX => segmentation fault
  for(u =0;u < 900000;u++)//Si j'initialise pas toutes les valeurs => segmentation fault
    boby[u] = 48;
  char *buff = malloc(sizeof(char) * 3);//Si je met char buff[3] => segmentation fault
	gris = img->ng;
  j= 0;pos = 0;i = 0;

	while (img->pixels[i] != '\0'){

		if (img->pixels[i] == '\n'){

			old_pixel = atoi(buff);
			new_pixel = gris - old_pixel;	
      n = log10(new_pixel) + 1;

      if(!new_pixel){
        boby[pos] = 48;
        pos++;
        boby[pos] = '\n';
      }
      else{
        for (o = n-1; o >= 0; --o, new_pixel /= 10 )
          boby[pos + o] = 48 +new_pixel % 10;
        pos += n;
        boby[pos] = '\n'; 
      }  

      pos++;
			j = 0;
			memset(buff,'\0',sizeof(buff));
		}
    else{
			buff[j] = img->pixels[i];
			j++;		
		}
    i++;  
	}

  for(u =0;u < pos;u++)
    img->pixels[u] = boby[u];

}


////////////////////////////////////////////////
void ecriture_image(FILE *f,image *img){

  fprintf(f,"%s\n", img->nm);
  fprintf(f,"%s\n", img->comments);
  fprintf(f,"%d\n", img->nl);
  fprintf(f,"%d\n", img->nc);
  fprintf(f,"%d\n", img->ng);
  fprintf(f,"%s\n", img->pixels);


}