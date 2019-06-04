// Projeto 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArvoreBinaria{
    int info;
    struct ArvoreBinaria *filhoDir;
    struct ArvoreBinaria *filhoEsq;
} arvore;

arvore *arvoreVazia();

int main(){

    arvore *a = arvoreVazia();

    printf("a\n");

    return 0;
}

arvore *arvoreVazia(){
    return NULL;
}
