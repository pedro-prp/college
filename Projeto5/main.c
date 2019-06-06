// Projeto 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct ArvoreBinaria{
    int info;
    struct ArvoreBinaria *filhoDir;
    struct ArvoreBinaria *filhoEsq;
} arvore;

// biblioteca
arvore *loadTreeFromFile(char *);
// void showTree(arvore *);
void searchValue(arvore *, int);
int getHeight(arvore *);
void isFull(arvore *);


// funções auxiliares para funcionamento da biblioteca
arvore *arvoreVazia();
arvore *alocaNo(int);
arvore *insereElem(arvore *,int);
arvore *insereVector(arvore *, double *);
arvore *searchInTree(arvore *,int, arvore *);
int getSize(arvore *);
double *leituraDeArquivo(FILE *);
double checaDecimal(double);


int main(){

    char in[100];
    scanf("%s",in);

    arvore *arv;
    arvore *search = alocaNo(10);

    arv = loadTreeFromFile(in);
    int tam = getSize(arv);
    int altura = getHeight(arv);

    // printf("%d %d\n",tam,altura);

    searchValue(arv,35);

    // isFull(arv);

    return 0;
}


arvore *loadTreeFromFile(char *path){
    arvore *arv = arvoreVazia();
    double *vector;    
    
    FILE *f;  
    f = fopen(path,"r");
    if(f == NULL){
        printf("Erro de leitura\n");
        exit(-1);
    }
    vector = leituraDeArquivo(f);

    arv = insereVector(arv, vector);

    fclose(f);
    
    return arv;
}


void searchValue(arvore *arv, int info){
    if(arv->info == info){
        printf("Elemento encontrado na raiz: %d\n",arv->info);
        return;
    }
    
    arvore *father = alocaNo(1);
    father = searchInTree(arv, info, arvoreVazia());

    if(father == NULL){
        printf("Elemento não encontrado\n");
        return;
    }

    if(father->filhoEsq == NULL){
        printf("Elemento encontrado: %d\n",father->filhoDir->info);
        printf("Elemento Pai: %d\n",father->info);
        printf("Elemento Irmão: não possui\n");
    }else if(father->filhoDir == NULL){
        printf("Elemento encontrado: %d\n",father->filhoEsq->info);
        printf("Elemento Pai: %d\n",father->info);
        printf("Elemento Irmão: não possui\n");
    }else{
        if(father->filhoDir->info == info){
            printf("Elemento encontrado: %d\n",father->filhoDir->info);
            printf("Elemento Pai: %d\n",father->info);
            printf("Elemento Irmão: %d\n",father->filhoEsq->info);
        }else{
            printf("Elemento encontrado: %d\n",father->filhoEsq->info);
            printf("Elemento Pai: %d\n",father->info);
            printf("Elemento Irmão: %d\n",father->filhoDir->info);
        }
    }
}


arvore *searchInTree(arvore *arv,int info, arvore *father){
    if(arv == NULL){
        return arv;
    }

    if(arv->info == info){
        return father;
    }else{
        if(info < arv->info){
            return searchInTree(arv->filhoEsq, info, arv);
        }else{
            return searchInTree(arv->filhoDir, info, arv);
        }
    }
}


int getHeight(arvore *arv){
    // caso a arvore esteja vazia
    if(arv == NULL){
        return 0;
    }
    // caso não esteja vazia
    else{
        // sub arvores dos filhos
        int esquerda = getHeight(arv->filhoEsq);
        int direita = getHeight(arv->filhoDir);

        if(esquerda > direita){
            return (esquerda+1);
        }else{
            return (direita+1);
        }
    }
}


void isFull(arvore *arv){
    int height = getHeight(arv);
    int size = getSize(arv);

    if((pow(2,height) - 1) == size){
        printf("Árvore cheia\n");
    }else{
        printf("Árvore não cheia\n");
    }
}


int getSize(arvore *arv){
    // arvore vazia
    if(arv == NULL){
        return 0;
    }
    // pega tamanho pela esquerda e direita
    else{
        return getSize(arv->filhoEsq) + 1 + getSize(arv->filhoDir);
    }
}


arvore *arvoreVazia(){
    return NULL;
}

arvore *alocaNo(int info){
    arvore *arv = (arvore *) malloc(sizeof(arvore));

    if(arv == NULL){
        printf("Erro de alocacao\n");
        exit(-1);
    }
    
    arv->info = info;
    arv->filhoDir = NULL;
    arv->filhoEsq = NULL;

    return arv;
}

arvore *insereElem(arvore *raiz,int info){
    if(info < raiz->info){
        if(raiz->filhoEsq == NULL){
            arvore *elem = alocaNo(info);
            raiz->filhoEsq = elem;
        }else{
            raiz->filhoEsq = insereElem(raiz->filhoEsq, info);
        }
    }
    else{
        if(raiz->filhoDir == NULL){
            arvore *elem = alocaNo(info);
            raiz->filhoDir = elem;
        }else{
            raiz->filhoDir = insereElem(raiz->filhoDir, info);
        }
    }

    return raiz;
}


arvore *insereVector(arvore *arv, double *vector){
    arv = alocaNo(vector[0]);

    for(int i = 1; checaDecimal(vector[i]) == 0.0; i++){
        arv = insereElem(arv,vector[i]);
    }
    
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
