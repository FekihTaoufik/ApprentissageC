void minmax(int T[], int taille, int *pmin, int *pmax)
{
    int i;
    *pmin = T[0];
    *pmax = T[0];
    for (i = 0; i < taille; i++)
    {
        if (T[i] > *pmax)
            *pmax = T[i];

        if (T[i] < *pmin)
            *pmin = T[i];
    }
}