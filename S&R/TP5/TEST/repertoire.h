#ifndef ID3REPERTOIRE
#define ID3REPERTOIRE


char** ls_mp3files_inarray(char* directory);
char * get_album(char* directory, char* filename);
void creer_repertoire(char* directory, char* filename);
void move_files(char* directory,char* path);
#endif





