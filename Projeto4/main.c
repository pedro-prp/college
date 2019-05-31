#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// constantes de tempo
#define TEMPO_UNIDADE 5

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
        codigos[i] = (char *) malloc(10*(sizeof(char)));
        
        if(codigos == NULL){
            printf("Erro de alocação\n");
            exit(-1);
        }

        fscanf(f," %s",codigos[i]);
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


lista *geraDadosAleatorios(int *num_Voos){
    srand(time(NULL));

    int numVoos = geraNumAleatorio(20,64);
    int numAprox = geraNumAleatorio(10,(numVoos-10));
    int numDecola = (numVoos - numAprox);

    *(num_Voos) = numVoos;
    
    printf("%d voos => %d Aproximacoes - %d Decolagens\n", numVoos,numAprox,numDecola);

    lista *voos = (lista *) malloc(numVoos*(sizeof(lista)));
    
    int *codigosUsados = (int *) calloc(64, sizeof(int));

    char **codigos = lerCodigosVoos();

    // for(int i = 0; i < 64; i ++){
    //     printf("%d - %s\n",i,codigos[i]);
    // }

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

        // printf("%d - %d - ",i,numCodigo);

        voos[i].codigo = (char *) malloc(10*(sizeof(char)));
        strcpy(voos[i].codigo, codigos[numCodigo]);

        // tipo 0 - Aproximacoes
        // tipo 1 - Decolagens
        if(i < numAprox){
            voos[i].tipo = 0;
            voos[i].combustivel = geraNumAleatorio(0,12);
        }else{
            voos[i].tipo = 1;
            voos[i].combustivel = 0;
        }

        // printf("%d %s",i,voos[i].codigo);
        // printf("\t%d - %d\n",voos[i].tipo,voos[i].combustivel);
    }

    liberaMatrix(codigos,64);
    free(codigosUsados);

    return voos;
}


int main(){
    lista *v;
    int num_Voos;
    v = geraDadosAleatorios(&num_Voos);

    // printf("%d\n",num_Voos);

    // // 10:00 am -> em minutos(600)
    int tempo = 600;

    for(int i = 0; i < num_Voos; i++){
        printf("%s",v[i].codigo);
        printf("\t%d - %d\n",v[i].tipo,v[i].combustivel);
    }

    return 0;
}
