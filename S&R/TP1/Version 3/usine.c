#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TEMPS_PRODUCTION 1
struct USINE {
  int * stock;
  pthread_mutex_t *mutex;
};

// On donne acces a la fonction capacite_max_entrepot en invoquant sa signature
int capacite_max_entrepot();

void *activite_usine(void *pdata)
{

  while (1)
  {
    struct USINE *U  = pdata;
    pthread_mutex_lock(U->mutex);
    printf("Usine :\t");
    // On limite la production a la capacité maximale de l'entrepot
    if (*(U->stock) < capacite_max_entrepot())
    {
      // on incrémente le stock
      (*(U->stock))++;
      printf("Production d'une voiture\n");
      sleep(TEMPS_PRODUCTION);
    }
    else
    {
      printf("Pas de production d'une voiture\n");
    }
    pthread_mutex_unlock(U->mutex);
    sleep(TEMPS_PRODUCTION);
  }
}

int creation_usine(pthread_t *t, int *S,pthread_mutex_t *mutex)
{
  struct USINE *U = malloc(sizeof(struct USINE));
  *U = (struct USINE){S,mutex};
  // on crée le thread en passant en parametres le pointeur du stock de l'entrepot
  return pthread_create(t, NULL, activite_usine, U);
}