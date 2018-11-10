#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "image.h"
#include <math.h>
/*
RAPPEL ****************
typedef struct {
char nm[5];  // Nombre magique
char comments[SIZECOMMENT]; 
int nl, nc;  // Nombre ligne/colonnes
int ng;      // Nombre de gris
unsigned char pixels[NMAX*NMAX]; // Pas top et ...
                // si vous le sentez => heap ! 
                                // Par contre le 2D est inutile
} image;
*/
image *lecture_image(FILE *f){
    char line[256];
    int i=0;
    int i_comms=0;
    int i_pix=0;
    image *m = malloc(sizeof(image));
    char oldLine[SIZECOMMENT];
    while (1) {
        fgets(line, sizeof(line), f);
        if(feof(f))
            break;

        if(i==0){
            strcpy(m->nm, line);
        }
        else if(line[0]=='#'){
            strcat(m->comments,line);
            i_comms++;

        }else if (strstr(line, " ")){
            m->nl=atoi(strstr(line, " "));
            m->nc=atoi(line);
        }else if(strstr((oldLine), " ")){
            m->ng=atoi(line);
        }
        else {
            m->pixels[i_pix]=atoi((line));
            i_pix++;
        }
        i++;
        strcpy(oldLine,line);
    }
    return m;
  
};
void inverse_image(image *img){
    
   for(int i=0;i<(img->nl * img->nc);i++){
     img->pixels[i] = img->ng - img->pixels[i];
   }
}


void ecriture_image(FILE *f,image *img){
    // Le nombre magique
    fprintf(f,"%s", img->nm);
    // Les commentaires
    fprintf(f,"%s", img->comments);
    // Les dimensions
    fprintf(f,"%d ", img->nc);
    fprintf(f,"%d\n", img->nl);
    // Le nombre de gris
    fprintf(f,"%d\n", img->ng);
    // les prixels
    for(int i = 0; i < (img->nl * img->nc); i++)
        fprintf(f,"%d\n", img->pixels[i]);
}