#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define CAPACITE_CONCESSION 10
#define TEMPS_MOY_ENTRE_VENTE 8

struct CONCESSION
{
    int *stock_entrepot;
    int *stock_local;
    int *pid;
    pthread_mutex_t *mutex;
};

void *activite_concession(void *pdata)
{
    while (1)
    {
        struct CONCESSION *c = pdata;
        pthread_mutex_lock(c->mutex);
        // Alimentation du stock local de la concession =========DEBUT=========
        if (*(c->stock_local) <= 0 && *(c->stock_entrepot) > 0)
        {
            // au cas ou le stock local de la concession est vide et le stock de l'entrepot contient des voitues
            if (*(c->stock_entrepot) >= CAPACITE_CONCESSION)
            {
                // Si le stock de l'entrepot contient plus que la capacité de la concession
                // => On fait le plein
                *(c->stock_local) = *(c->stock_local) + CAPACITE_CONCESSION;
                *(c->stock_entrepot) = *(c->stock_entrepot) - CAPACITE_CONCESSION;
            }
            else
            {
                // Sinon
                // On recupere tout ce qu'il y a dans le stock de l'entrepot
                *(c->stock_local) = *(c->stock_local) + *(c->stock_entrepot);
                *(c->stock_entrepot) = 0;
            }
        }
        // Alimentation du stock local de la concession =========FIN=========
        printf("Concession %d :\t", (*(c->pid) + 1));
        // on check si le stock local de la concession n'est pas vide
        if (*(c->stock_local) > 0)
        {
            // On vend une voiture en decrementant le stock_local de 1
            *(c->stock_local) = *(c->stock_local) - 1;
            printf("Vente d'une voiture | (stock_local : %d, stock_entrepot : %d)\n", *(c->stock_local), *(c->stock_entrepot));
        }
        else
        {
            printf("Stock local insuffisant, aucune vente effectue\n");
        }
        pthread_mutex_unlock(c->mutex);
        sleep(TEMPS_MOY_ENTRE_VENTE);
    }
}

int creation_concession(pthread_t *t, int *pid, int *s,pthread_mutex_t *mutex)
{

    struct CONCESSION *c = malloc(sizeof(struct CONCESSION));
    int *stock_local = malloc(sizeof(int));

    // Le stock de la concession est initialise a 0
    *stock_local = 0;

    // On rassemble les données qu'on veut partager avec le thread dans une structure CONCESSION
    // - L'id de la concession
    // - Le stock de l'entrepot
    // - Le stock de de la concession

    *c = (struct CONCESSION){s, stock_local, pid,mutex};

    return pthread_create(t, NULL, activite_concession, c);
}