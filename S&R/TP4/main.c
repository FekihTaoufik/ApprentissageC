#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include "image.h"

void usage(){
 fprintf(stderr,"image finitial.pgm ftransforme.pgm\n");
}

int main(int argc, char *argv[]){
   void *lib_handle;
   void (*fn)(image *img,int seuil);
   int x;
   char *error;

  FILE *f;
  image *I;
  
  if (argc < 3){
    usage();
    return -1;
  }

  /* Lecture de l'image */

  f = fopen(argv[1],"r");
  if (f == NULL)
    fprintf(stderr,"Erreur d'ouverture du fichier initial \n");
  I = lecture_image(f);

  fclose(f);

  /* Traitement de l'image */
  // inverse_image(I);

   lib_handle = dlopen("./lib/libimageplus.so", RTLD_LAZY);
   if (!lib_handle)
   {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
   }

   fn = dlsym(lib_handle, "image_NB");
   if ((error = dlerror()) != NULL)  
   {
      fprintf(stderr, "%s\n", error);
      exit(1);
   }

  (*fn)(I,150);
    dlclose(lib_handle);

  /* Ecriture de l'image */
  f = fopen(argv[2],"w");
  ecriture_image(f,I);    
  fclose(f);
  
  return EXIT_SUCCESS;
}