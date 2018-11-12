2.1
    Compléter les fonctions : 
        1. Lire une image 
        2. Inverser ses pixels
        3. Sortir le fichier .pgm inversé
            *Remarque : Le fichier d'entrée et celui de sortie sont indiqué dans la commande d'exécution du programme 
            - gcc main.c image.c -o image
            - ./image Logo_MIAGE_GreyLevel.pgm Logo_MIAGE_Inversed.pgm
            on la récupérer depuis argv
2.2 Exécutable et bibliothèques : 
    => Il s'agit de créer l'exécutable ./image de 3 façons
    1. Classique (ce qu'on vient de faire en 2.1)
        vous compilez les deux fichiers sources simultanément
        Vous obtenez un exécutable [image].
    2. Bibliothèque statique
        Je me référe a ce tuto : http://www.gecif.net/articles/linux/pdf/edition_de_liens_et_librairies.pdf

        Démarche en ligne de commande : 
            1. gcc -c image.c
            2. ar crs libimage.a image.a
            3. readelf -sW libimage.a (optionnel, pour voir combien nos fonctions coute en mémoire)
            4. gcc main.c -L. -limage -o image_static
            5. on exécute pour tester : ./image_libStatique Logo_MIAGE_GreyLevel.pgm Logo_MIAGE_Inversed_2.pgm
    3. Bibliothèque dynamique et partagé
        Démarche en ligne de commande : 
            1. gcc -fPIC -c image.c -shared -o libimage.so
            2. gcc main.c -L. -limage -o image_dyn

2.3 Analyse
    Q1. Faire marcher :
        C'est fait, on a les exécutables image, image_static et image_dyn
    Q2.Comparer la taille des trois exécutables : 
        Les 3 fichiers exécutable ont la méme taille
    Q3. Montrer le placement en mémoire de la bibliothèque partagée
    Q4. Montrer les effets des allocations dans le tas dans la mémoire du processus.Gilles Menez - Ufr Sciences - UNS4
2.4 PLUGIN
    1. créer un nouveau fichier imageplus.c
    2. void image_NB(image *,int seuil);
    3. Suivre le tuto donné http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html
    et plus précisément la partie : "Dynamic loading and un-loading of shared libraries using libdl"faire découvrir cette nouvelle fonction à votre programme.Gilles Menez - Ufr Sciences - UNS6

    Ce que j'ai fait après la creation de imageplus.c: 
    1. création de la librairie dynamique partagé ./lib/libimageplus.so
        Commande : gcc -fPIC imageplus -shared -o ./lib/libimageplus.so
    2. compilation de l'exécutable et rajoutant la libraire dl pour pouvoir faire le dynamic loading
        Commande : gcc main.c -L. -limage -ldl -o image_dyn
    3. exécution & test : ./image_dyn Logo_MIAGE_GreyLevel.pgm Logo_MIAGE_Inversed_3.pgm
