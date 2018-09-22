#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define CAPACITE_CONCESSION 10
#define TEMPS_MOY_ENTRE_VENTE 5

struct CONCESSION
{
    int *stock_entrepot;
    int *stock_local;
    int *pid;
};

void *activite_concession(void *pdata)
{
    while (1)
    {
        struct CONCESSION *c = pdata;
        // Alimentation du stock local de la concession =========DEBUT=========
        if (*(c->stock_local) <= 0 && *(c->stock_entrepot) > 0)
        {
            if (*(c->stock_entrepot) >= CAPACITE_CONCESSION)
            {
                *(c->stock_local) = *(c->stock_local) + CAPACITE_CONCESSION;
                *(c->stock_entrepot) = *(c->stock_entrepot) - CAPACITE_CONCESSION;
            }
            else
            {
                *(c->stock_local) = *(c->stock_local) + *(c->stock_entrepot);
                *(c->stock_entrepot) = 0;
            }
        }
        // Alimentation du stock local de la concession =========FIN=========
        printf("Concession %d :\t", (*(c->pid) + 1));
        if (*(c->stock_local) > 0)
        {
            *(c->stock_local) = *(c->stock_local) - 1;
            printf("Vente d'une voiture | (stock_local : %d, stock_entrepot : %d)\n", *(c->stock_local), *(c->stock_entrepot));
        }
        else
        {
            printf("Stock local insuffisant, aucune vente realise\n");
        }

        sleep(TEMPS_MOY_ENTRE_VENTE);
    }
}

int creation_concession(pthread_t *t, int *pid, int *s)
{
    struct CONCESSION *c = malloc(sizeof(struct CONCESSION));
    int *stock_local = malloc(sizeof(int));
    *stock_local = 0;
    *c = (struct CONCESSION){s, stock_local, pid};
    return pthread_create(t, NULL, activite_concession, c);
}