#include <stdio.h>
#include <stdlib.h>



#define IMAGEH

#define NMAX 3000
#define SIZECOMMENT 5000

typedef struct {
  char nm[5];  /* Nombre magique */
  char comments[SIZECOMMENT]; 
  int nl, nc;  /* Nombre ligne/colonnes */
  int ng;      /* Nombre de gris */
  unsigned char pixels[NMAX*NMAX]; /* Pas top et ... */
				   /* si vous le sentez => heap !  */
                                   /* Par contre le 2D est inutile */
} image;

void image_NB(image *img,int seuil){
for(int i=0;i<(img->nl * img->nc);i++){
    if(img->pixels[i]>seuil)
        img->pixels[i] = img->ng;
    else if (img->pixels[i]!=seuil)
        img->pixels[i] = 0;
   }
}