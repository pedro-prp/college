// Projeto 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArvoreBinaria{
    int info;
    struct ArvoreBinaria *filhoDir;
    struct ArvoreBinaria *filhoEsq;
} arvore;

// biblioteca
arvore *LoadTreeFromFile(char *);



// funções auxiliares para funcionamento da biblioteca
arvore *arvoreVazia();
int *leituraDeArquivo(FILE *);


int main(){

    char in[100];
    scanf("%s",in);

    LoadTreeFromFile(in);

    return 0;
}

arvore *arvoreVazia(){
    return NULL;
}

arvore *LoadTreeFromFile(char *path){
    arvore *arv = arvoreVazia();
    arv = (arvore *) malloc(sizeof(arvore));    
    
    FILE *f;  
    f = fopen(path,"r");
    if(f == NULL){
        printf("Erro de leitura\n");
        exit(-1);
    }

    int *a = leituraDeArquivo(f);



    fclose(f);
    return arv;
}

int *leituraDeArquivo(FILE *f){
    int cont=0,aux;
    char jaja;
    int *vector;
    
    // conta quant de numeros
    while(!feof(f)){
        fscanf(f,"%*d%*c");
        cont++;
    }
    vector = (int *) calloc(cont,sizeof(int));

    // retorna File f pro começo
    fseek( f, 0, SEEK_SET );

    // armazena em vector os elementos
    for(int i = 0; !feof(f); i++){
        fscanf(f,"%d%*c",&vector[i]);
    }

    return vector;
}
