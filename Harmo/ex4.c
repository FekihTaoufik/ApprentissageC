// ANNUAIRE
#include <stdio.h>
typedef struct
{
    char nom[50];
    char prenom[50];
    int age;
    // char *adresse;
} personne;

personne saisir_personne()
{
    static int count = 0;
    personne *p;
    p = malloc(sizeof(personne));



    printf("Saisie des donnees de la personne Numero %d\n", count + 1);
    printf("Nom : ");
    scanf("%s", &p->nom);
    printf("Prenom : ");
    scanf("%s", &p->prenom);
    printf("\nAge : ");
    scanf("%d", &p->age);

    
    count++;
    return *p;
}
void remplir_annuaire(personne *T, int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        T[i] = saisir_personne();
    }
}

void afficher_annuaire(personne T[], int taille)
{
    int i;
    printf("---------- Affichage de l'annuaire");
    for (i = 0; i < taille; i++)
    {
        printf("%s %s a %d ans", T[i].nom, T[i].prenom, T[i].age);
    }
}
int main()
{
    personne T[3];
    // T[0] = saisir_personne();
    remplir_annuaire(&T, 3);
    afficher_annuaire(T, 3);

    return 0;
}
