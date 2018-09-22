#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TEMPS_PRODUCTION 1

void *activite_usine(void *pdata)
{

  while (1)
  {
    printf("Production d'une voiture\n");

    sleep(TEMPS_PRODUCTION);
  }
}

int creation_usine(pthread_t *t)
{
  /* Creation de l'usine */
  return pthread_create(t,
                        NULL,
                        activite_usine,
                        NULL);
}