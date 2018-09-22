#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define CAPACITE_ENTREPOT 1000
#define INTERVALLE_INVENTAIRE 1
int capacite_max_entrepot()
{
    return CAPACITE_ENTREPOT;
}
void *activite_entrepot(void *pdata)
{
    while (1)
    {
        // On récupére les données passé en parametres et on affiche l'état du stock
        int *s = pdata;
        printf("Entrepot :\t");
        printf("Stock actuel %d\n", *s);
        sleep(INTERVALLE_INVENTAIRE);
    }
}

int creation_entrepot(pthread_t *t, int *s)
{
    // on crée le thread en passant en parametres le pointeur du stock de l'entrepot
    return pthread_create(t, NULL, activite_entrepot, s);
}