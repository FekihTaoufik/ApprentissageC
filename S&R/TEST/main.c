#include <stdio.h>

#include <pthread.h>

static void *task_a(void *p_data)
{
    if (p_data != NULL)
    {
        /* récupérer le contexte applicatif */
        char const *s = p_data;
        int i;

        for (i = 0; i < 5; i++)
        {
            printf("'%s' (%d)\n", s, i);
        }
    }
    return NULL;
}

static void *task_b(void *p_data)
{
    if (p_data != NULL)
    {
        /* récupérer le contexte applicatif */
        char const *s = p_data;
        int i;

        for (i = 0; i < 7; i++)
        {
            printf("'%s'     (%d)\n", s, i);
        }
    }
    return NULL;
}

int main(void)
{
    pthread_t ta;
    pthread_t tb;

    puts("main init");

    /* La chaîne étant définie const sur ma machine, je force en (char*).
 * Dans la tâche, 's' est bien de type 'char const *'
 */
    pthread_create(&ta, NULL, task_a, (char *)"Tache A");
    pthread_create(&tb, NULL, task_b, (char *)"Tache B");

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    puts("main end");

    return 0;
}