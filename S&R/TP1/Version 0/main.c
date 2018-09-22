#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
Version 1 :
  1 - On rajoute les fichiers "concession.c" et "entrepot.c" a la commande de compilation dans le fichier Makefile
*/
int creation_usine(pthread_t *t);

int main(int argc, char *argv[])
{
  int r = 1;

  pthread_t usine;

  r = creation_usine(&usine);

  pthread_join(usine, NULL);

  if (r != 0)
    fprintf(stderr, "Usine echec !");
}
