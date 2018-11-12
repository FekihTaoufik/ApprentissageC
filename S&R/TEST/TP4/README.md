2.1
    Compléter les fonctions : 
        1. Lire une image 
        2. Inverser ses pixels
        3. Sortir le fichier .pgm inversé
            *Remarque : Le fichier d'entrée et celui de sortie sont indiqué dans la commande d'exécution du programme 
            - gcc main.c image.c -o image
            - ./image Logo_MIAGE_GreyLevel.pgm Logo_MIAGE_Inversed.pgm
            on la récupérer depuis argv
2.2
    Exécutable et bibliothèques : 
    => Il s'agit de créer l'exécutable ./image de 3 façons
    1. Classique (ce qu'on vient de faire en 2.1)
        vous compilez les deux fichiers sources simultanément
        Vous obtenez un exécutable [image].
    2. Bibliothèque statique
        Je me référe a ce tuto : https://gradot.wordpress.com/2013/11/15/creer-et-utiliser-une-bibliotheque-statique-en-c/
        Démarche en ligne de commande : 
            1. gcc -c image.c
            2. ar crs libimage.a image.a
            3. readelf -sW libimage.a (optionnel, pour voir combien nos fonctions coute en mémoire)
            4. gcc -Wall main.c -L. -limage -o image_static
            5. on exécute pour tester : ./image_libStatique Logo_MIAGE_GreyLevel.pgm Logo_MIAGE_Inversed_2.pgm
    2. Bibliothèque dynamique et partagé
2.3