#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int creation_usine(pthread_t *t);

int main(int argc, char*argv[]){
  int r = 1;
  pthread_t usine;
  r = creation_usine(&usine);

  if (r != 0)
    fprintf(stderr,"Usine echec !");
}