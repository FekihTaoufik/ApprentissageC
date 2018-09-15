#include <stdio.h>
#include "minmax.h"
#include "randfill.h"
int main()
{

    int T[10], min, max, i;

    randfill(&T, 10);
    minmax(T, 10, &min, &max);

    for (i = 0; i < 10; i++)
        printf(" | %d", T[i]);

    printf("\nmin : %d, max : %d", min, max);

    return 0;
}