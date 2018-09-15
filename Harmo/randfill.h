#include <stdlib.h>
#include <time.h>
void randfill(int *T, int taille)
{
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < taille; i++)
        T[i] = rand() % 10;
}