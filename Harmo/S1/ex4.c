// ANNUAIRE
#include <stdio.h>
typedef struct
{
    char nom[10];
    char prenom;
    int age;
    char *adresse;
} personne;

void remplir_annuaire(int *T, int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("Saisie des donnees de la personne Numero %d\n", i);
        T[i] = saisir_personne();
        printf(T[i]);
    }
}

// void afficher_annuaire(personne *T, int taille)
// {
//     int i;
//     for (i = 0; i < taille; i++)
//     {
//         printf("Personne N° : %d\n", i);
//         printf("Nom : %s", T[i].nom);
//         printf("\nPrénom : %s", T[i].nom);
//     }
// }
personne *saisir_personne()
{
    personne *p;
    p = malloc(sizeof(personne));

    printf("Nom : ");
    scanf("%s", p->nom);
    return p;
}

int main()
{
    personne *p;
    p = saisir_personne();
    printf("%d", p);
    return 0;
}