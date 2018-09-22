#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_CONCESSION 3

int creation_usine(pthread_t *t, int *s);
int creation_concession(pthread_t *t, int *pid, int *s);
int creation_entrepot(pthread_t *t, int *s);

int main(int argc, char *argv[])
{
  int stock_entrepot = 0;
  int r = 1;
  int i;

  pthread_t usine;
  pthread_t entrepot;
  pthread_t concession[NB_CONCESSION];

  r = creation_usine(&usine, &stock_entrepot);
  if (r != 0)
    fprintf(stderr, "Usine echec !");

  r = creation_entrepot(&entrepot, &stock_entrepot);
  if (r != 0)
    fprintf(stderr, "Entrepot echec !");

  for (i = 0; i < NB_CONCESSION; i++)
  {
    int *pid = malloc(sizeof(int));
    *pid = i;
    r = creation_concession(&(concession[i]), pid, &stock_entrepot);
    if (r != 0)
      fprintf(stderr, "Concession echec !");
  }

  pthread_join(usine, NULL);
  pthread_join(entrepot, NULL);

  for (i = 0; i < NB_CONCESSION; i++)
  {
    pthread_join(concession[i], NULL);
  }

  return 0;
}
