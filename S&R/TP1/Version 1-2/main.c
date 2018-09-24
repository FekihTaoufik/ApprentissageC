#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_CONCESSION 3
// on définit les signatures des fonctions a utiliser
int creation_usine(pthread_t *t, int *s);
int creation_concession(pthread_t *t, int *pid, int *s);
int creation_entrepot(pthread_t *t, int *s);

int main(int argc, char *argv[])
{
  // Initialisation du stock de l'entrepot
  int stock_entrepot = 0;
  int r = 1;
  int i;

  pthread_t usine;
  pthread_t entrepot;
  pthread_t concession[NB_CONCESSION];
  // Création d'une usine
  r = creation_usine(&usine, &stock_entrepot);
  if (r != 0)
    fprintf(stderr, "Usine echec !");

  // Création d'un entrepot
  r = creation_entrepot(&entrepot, &stock_entrepot);
  if (r != 0)
    fprintf(stderr, "Entrepot echec !");

  // Création de N Concessions
  for (i = 0; i < NB_CONCESSION; i++)
  {
    int *pid = malloc(sizeof(int));
    *pid = i;
    r = creation_concession(&(concession[i]), pid, &stock_entrepot);
    if (r != 0)
      fprintf(stderr, "Concession echec !");
  }

  // On fait attendre la methode main jusqu'a ce que les threads terminent leurs taches
  pthread_join(usine, NULL);
  pthread_join(entrepot, NULL);

  for (i = 0; i < NB_CONCESSION; i++)
  {
    pthread_join(concession[i], NULL);
  }

  return 0;
}
