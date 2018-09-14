void comptage(char T[], int taille, int *min, int *maj, int *chif)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        if ((int)T[i] >= 48 && (int)T[i] <= 57)
        {
            *chif += 1;
        }
        else if ((int)T[i] >= 65 && (int)T[i] <= 90)
        {
            *maj += 1;
        }
        else if ((int)T[i] >= 97 && (int)T[i] <= 122)
        {
            *min += 1;
        }
    }
}
void afficher_tableau(char T[], int taille)
{
    T[taille] = '\0';
    printf("\nAffichage du tableau : %s", T);
}

void remplir_tableau(char T[], int taille)
{
    int i;
    int gen;
    int min = 48, max = 122;
    srand((unsigned)time(NULL));
    for (i = 0; i < taille; i++)
    {
        do
        {
            gen = (rand() % (max + 1 - min)) + min;
        } while (!((gen >= 97 && gen <= 122) || (gen >= 65 && gen <= 90) || (gen >= 48 && gen <= 57)));
        T[i] = gen;
    }
    // 97 => 122 [a-z]
    // 65 => 90 [A-Z]
    // 48 => 57 [0-9]
}