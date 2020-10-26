#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *c;
}palavra;

int main(){

    palavra *nova;
    char c[20] = "vinicius takeo";
    printf("%ld\n",sizeof(c));
    nova = (palavra*)malloc(sizeof(palavra));
    memcpy(&c,nova->c,sizeof(char)*20);
    puts(nova->c);


    return 0;
}
