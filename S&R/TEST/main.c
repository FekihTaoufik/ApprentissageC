#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char * [1000] s ;
FILE *f = fopen('filename', "r");
s = read(f,1,1);
    printf("%s",s);
    return 0;
}