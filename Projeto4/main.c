#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// constantes de tempo
#define TEMPO_UNIDADE 5

// Estruturas para tratar os voos
typedef struct Lista {
    char *codigo;
    char *status;
    int combustivel;
    int tipo;
    int processo;
    int horainicio;
    int horafinal;
    struct Lista *prox;
} lista;

typedef struct Fila {
    lista *ini;
    lista *fim;
} fila;

// Estrutura para tratar as pistas
typedef struct Pista{
    int horarioUsado;
    int emUso;
} pista;


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

void *listaVazia(){
    return NULL;
}


void printaCabecalho(int numVoos, int numAprox){
    printf("---------------------------------------------------------------------------------\n");
    printf("“Aeroporto Internacional de Brasília”\n");    
    printf("Fila de Pedidos: [código do voo – P/D – prioridade]\n");
    printf("NVoos: %d\n", numVoos);
    printf("Naproximações: %d\n", numAprox);
    printf("---------------------------------------------------------------------------------\n");
}


int geraNumAleatorio(int inicio, int final){
    int numero = (rand() % (final - inicio + 1)) + inicio;

    return numero;
}

lista *geraVoo(char **codigos,int numCodigo, int i, int numAprox, int numVoos){
    lista *new = (lista *) malloc(sizeof(lista));
    
    new->codigo = (char *) malloc(10*(sizeof(char)));
    strcpy(new->codigo, codigos[numCodigo]);


    if(i < (numVoos - numAprox)){
        new->tipo = 1;
        new->combustivel = 0;
    }else{
        new->tipo = 0;
        // new->combustivel = geraNumAleatorio(0,12);
        new->combustivel = 0;
    }

    new->processo = 0;
    new->horainicio = -1;
    new->horafinal = -1;
    new->status = (char *) malloc(100*(sizeof(char)));

    new->prox = NULL;

    return new;
}

lista *insereLista(lista *l, lista *new){
    if(l == NULL){
        return new;
    }

    new->prox = l;

    return new;
}


lista *ordenaAproxPorComb(lista *voos, int numAprox){
    for(int i = 0; i < numAprox; i++){
        lista *it = voos;
        for(int j = 0; j < (numAprox-1); j++){
            if(it->combustivel > it->prox->combustivel){
                char *aux = (char *) malloc(10*(sizeof(char)));
                int combAux;

                strcpy(aux, it->codigo);
                strcpy(it->codigo, it->prox->codigo);
                strcpy(it->prox->codigo, aux);

                combAux = it->combustivel;
                it->combustivel = it->prox->combustivel;
                it->prox->combustivel = combAux;
            }
            it=it->prox;
        }
    }

    return voos;
}


lista *geraDadosAleatorios(int *num_Voos, int *num_Aprox){
    srand(time(NULL));

    int numVoos = geraNumAleatorio(20,64);
    int numAprox = geraNumAleatorio(10,(numVoos-10));
    int numDecola = (numVoos - numAprox);

    *(num_Voos) = numVoos;
    *(num_Aprox) = numAprox;
    
    printf("%d voos => %d Aproximacoes - %d Decolagens\n", numVoos,numAprox,numDecola);

    lista *voos = listaVazia();
    
    int *codigosUsados = (int *) calloc(64, sizeof(int));

    char **codigos = lerCodigosVoos();

    // sorteia codigo voos e combustivel
    for(int i = 0; i < numVoos; i++){
        // sortei codigo
        int flag = 0;
        int numCodigo;
        lista *newVoo;

        while(flag == 0){
            numCodigo = geraNumAleatorio(0,63);
            if(codigosUsados[numCodigo] == 0){
                codigosUsados[numCodigo] = 1;
                flag = 1;
            }
        }
        
        newVoo = geraVoo(codigos, numCodigo, i, numAprox, numVoos);
        voos = insereLista(voos, newVoo);

    }
    voos = ordenaAproxPorComb(voos, numAprox);

    liberaMatrix(codigos,64);
    free(codigosUsados);

    return voos;
}


lista *reduzCombustivel(lista *voos){
    lista *it;
    for(it = voos; it != NULL; it = it->prox){
        if(it->processo == 0){
            it->combustivel--;
            if(it->combustivel < 0){
                strcpy(it->status, "CAIU");
                it->processo = 1;
            }
        }
    }

    return voos;
}


lista *checaCombustivel(lista *voos){
    lista *it;
    printf("debug 1\n");
    for(it = voos; it != NULL; it = it->prox){
        printf("debug 2\n");
        if((it->combustivel < 0) && (it->processo == 0)){
            printf("debug 3\n");
            strcpy(it->status, "ALERTA CRÍTICO, AERONAVE IRÁ CAIR");
            it->processo = 1;
        }
    }

    return voos;
}

int checaEmergencia(lista *voos){
    int cont = 0;
    lista *it;
    for(it = voos; it != NULL; it = it->prox){
        if(it->combustivel == 0 && it->processo == 1){
            cont++;
        }
    }

    return cont;
}


pista *pistaStart(int tempo){
    pista *p = (pista *) malloc(sizeof(pista));
    if(p == NULL){
        printf("Erro de alocacao\n");
        exit(-1);
    }

    p->horarioUsado = (tempo-1);
    
    return p;
}


lista *avancLista(lista *voos, int num){
    lista *it = voos;
    for(int i = 0; i < num; i++){
        it = it->prox;
    }

    return it;
}


lista *checaVoos(lista *voos, int tempo){
    lista *it;
    for(it = voos; it != NULL; it = it->prox){
        if(it->tipo == 0){
            if(it->horafinal <= tempo){
                if(it->processo == 0){
                    it->processo = 1;
                    strcpy(it->status,"aeronave pousou");
                }
            }
        }else{
            if(it->horafinal <= tempo){
                if(it->processo == 0){
                    it->processo = 1;
                    strcpy(it->status,"“aeronave decolou”");
                }
            }
        }
    }

    return voos;
}


lista *definirPistas(lista *voos, int tempo, int numVoos, int numAprox){
    lista *newVoos = NULL;
    int tempoAux;
    
    pista *pistaA = pistaStart(tempo);
    pista *pistaB = pistaStart(tempo);
    pista *pistaC = pistaStart(tempo);
    
    lista *itAprox = voos;
    lista *itDecolagens = avancLista(voos, (numAprox));

    tempoAux = tempo + (10*TEMPO_UNIDADE);
    
    while(numVoos > 0){

        int Emergencia = checaEmergencia(voos);

        if(itAprox->tipo == 1){
            break;
        }

        if(pistaA->horarioUsado < tempo){
            lista *aux = itAprox;
            itAprox = itAprox->prox;
            if(aux->processo == 0){
                if(aux->tipo == 0){
                    aux->horainicio = tempo;
                    aux->horafinal = tempo+20;
                    pistaA->horarioUsado = tempo+20;
                }
            }
        }
        
        if(pistaB->horarioUsado < tempo){
            lista *aux = itAprox;
            itAprox = itAprox->prox;
            if(aux->processo == 0){
                if(aux->tipo == 0){
                    pistaB->horarioUsado = tempo+20;
                }
            }
        }
        
        // if(pistaC->horarioUsado < tempo){
        //     if(Emergencia >= 3){
        //         printf("pousar\n");
        //     }else{
        //         itDecolagens = itDecolagens->prox;
        //     }
        // }

        if(tempo == tempoAux){
            voos = reduzCombustivel(voos);
            tempoAux = tempo + (10*TEMPO_UNIDADE);
            
        }

        voos = checaCombustivel(voos);
        voos = checaVoos(voos, tempo);

        tempo+=TEMPO_UNIDADE;
    }

    return voos;
}


fila *geraFila(lista *voos){
    fila *new = (fila *) malloc(sizeof(fila));
    
    // inicio
    new->ini = voos;
    
    // final
    lista *it;
    for(it = voos; it != NULL; it = it->prox){
        new->fim = it;
    }

    return new;
}


int main(){
    lista *v;
    int num_Voos,num_Aprox;
    v = geraDadosAleatorios(&num_Voos, &num_Aprox);

    int tempo = 600;

    printaCabecalho(num_Voos,num_Aprox);

    v = definirPistas(v, tempo, num_Voos, num_Aprox);
    lista *it;
        for(it = v; it != NULL; it = it->prox){
        printf("%s",it->codigo);
        printf("\t%d - %d %s\n",it->tipo,it->combustivel,it->status);
    }

    return 0;
}
