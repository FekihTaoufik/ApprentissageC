
#ifndef UTILH
#define UTILH

#include "id3_frame.h"

int read_error(int fd, char *buff, int nb_alire, const char *msg);
void printf_buff(char *buf, int nb, char *format, char *label);
int decode_taille(char t[4]);
int sizeOfTag(int fd);
char *get_directory(char* argv);
int file_exist(char *filename);
  
#define DEBUG 1

#endif