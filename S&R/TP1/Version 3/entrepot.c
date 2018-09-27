#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define CAPACITE_ENTREPOT 1000
#define INTERVALLE_INVENTAIRE 1
struct ENTREPOT
{
    int *stock;
    pthread_mutex_t *mutex;
};
int capacite_max_entrepot()
{
    return CAPACITE_ENTREPOT;
}
void *activite_entrepot(void *pdata)
{
    while (1)
    {
        // On récupére les données passé en parametres et on affiche l'état du stock
        struct ENTREPOT  *E = pdata;
        
        pthread_mutex_lock(E->mutex);

        printf("Entrepot :\t");
        printf("Stock actuel %d\n", *(E->stock));

        pthread_mutex_unlock(E->mutex);

        sleep(INTERVALLE_INVENTAIRE);
    }
}

int creation_entrepot(pthread_t *t, int *s,pthread_mutex_t *mutex)
{
    // on crée le thread en passant en parametres le pointeur du stock de l'entrepot
     struct ENTREPOT *E = malloc(sizeof(struct ENTREPOT));
  *E = (struct ENTREPOT){s,mutex};
    return pthread_create(t, NULL, activite_entrepot, E);
}