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
arvore *alocaNo(int info);
double *leituraDeArquivo(FILE *);
double checaDecimal(double);


int main(){

    char in[100];
    scanf("%s",in);

    LoadTreeFromFile(in);

    return 0;
}

arvore *arvoreVazia(){
    return NULL;
}

arvore *alocaNo(int info){
    arvore *arv = (arvore *) malloc(sizeof(arvore));
    
    arv->info = info;
    arv->filhoDir = NULL;
    arv->filhoEsq = NULL;

    return arv;
}

arvore *LoadTreeFromFile(char *path){
    arvore *arv = arvoreVazia();
    double *vector;    
    
    FILE *f;  
    f = fopen(path,"r");
    if(f == NULL){
        printf("Erro de leitura\n");
        exit(-1);
    }
    vector = leituraDeArquivo(f);

    // Raiz
    arv = alocaNo(vector[0]);

    printf("Raiz: %d\n",arv->info);

    for(int i = 1; checaDecimal(vector[i]) == 0.0; i++){
        printf("%.0lf\n",vector[i]);
    }

    fclose(f);
    return arv;
}

double *leituraDeArquivo(FILE *f){
    int cont=0;
    double *vector;
    
    // conta quant de numeros
    while(!feof(f)){
        fscanf(f,"%*d%*c");
        cont++;
    }
    vector = (double *) calloc((cont+1),sizeof(double));

    // retorna File f pro começo
    fseek( f, 0, SEEK_SET );

    // armazena em vector os elementos
    for(int i = 0; !feof(f); i++){
        fscanf(f,"%lf%*c",&vector[i]);
    }
    
    // criterio de parada
    vector[cont] = 1.5;

    return vector;
}

double checaDecimal(double d){
    double result = d - (int)d;
    
    return result;
}
