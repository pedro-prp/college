#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Lista {
    char *codigo;
    int combustivel;
    int tipo;
    struct Lista *prox;
}lista;

typedef struct Fila {
    lista *ini;
    lista *fim;
} fila;


char **lerCodigosVoos(){
    
    char **codigos = (char **) malloc(64*sizeof(char*));
    FILE *f = fopen("codigos.txt", "r");

    if(codigos == NULL || f == NULL){
        printf("Erro de alocação\n");
        exit(-1);
    }

    for(int i = 0; i < 64; i++){
        codigos[i] = (char *) malloc(8*(sizeof(char)));
        
        if(codigos == NULL){
            printf("Erro de alocação\n");
            exit(-1);
        }

        fscanf(f,"%s",codigos[i]);
    }
    fclose(f);
    return codigos;
}


void liberaMatrix(char **codigos,int size){
    for(int i = 0; i < size; i++){
        free(codigos[i]);
    }
    free(codigos);
}


int geraNumAleatorio(int inicio, int final){
    int numero = (rand() % (final - inicio + 1)) + inicio;

    return numero;
}


void geraDadosAleatorios(){
    srand(time(NULL));

    int numVoos = geraNumAleatorio(20,64);
    int numAprox = geraNumAleatorio(10,(numVoos-10));
    int numDecola = (numVoos - numAprox);
    
    printf("%d voos => %d Aproximacoes - %d Decolagens\n", numVoos,numAprox,numDecola);

    lista *voos = (lista *) malloc(numVoos*(sizeof(lista)));
    
    int *codigosUsados = (int *) calloc(64, sizeof(int));

    char **codigos = lerCodigosVoos();

    // sorteia codigo voos e combustivel
    for(int i = 0; i < numVoos; i++){
        // sortei codigo
        int flag = 0;
        int numCodigo;
        
        while(flag == 0){
            numCodigo = geraNumAleatorio(0,63);
            if(codigosUsados[numCodigo] == 0){
                codigosUsados[numCodigo] = 1;
                flag = 1;
            }
        }

        voos[i].codigo = (char *) malloc(8*(sizeof(char)));
        voos[i].codigo = codigos[numCodigo];

        // tipo 0 - Aproximacoes
        // tipo 1 - Decolagens
        if(i < numAprox){
            voos[i].tipo = 0;
            voos[i].combustivel = geraNumAleatorio(0,12);
        }else{
            voos[i].tipo = 1;
            voos[i].combustivel = 0;
        }

        printf("%s",voos[i].codigo);
        printf("\t%d - %d\n",voos[i].tipo,voos[i].combustivel);
    }



    liberaMatrix(codigos,64);
    free(codigosUsados);
}
// Constantes 

int main(){

    char **codigos = lerCodigosVoos();

    liberaMatrix(codigos,64);
    geraDadosAleatorios();

    return 0;
}
