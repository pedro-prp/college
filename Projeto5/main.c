// Projeto 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COUNT 5;

typedef struct ArvoreBinaria{
    int info;
    struct ArvoreBinaria *filhoDir;
    struct ArvoreBinaria *filhoEsq;
} arvore;

// biblioteca
arvore *loadTreeFromFile(char *);
void showTree(arvore *);
void printPostorder(arvore *);
void printInOrder(arvore *);
void printPreorder(arvore *);
arvore *removeValue(arvore *, int info);
void searchValue(arvore *, int);
int getHeight(arvore *);
void isFull(arvore *);


// funções auxiliares para funcionamento da biblioteca
arvore *arvoreVazia();
arvore *alocaNo(int);
arvore *insereElem(arvore *,int);
arvore *insereVector(arvore *, double *);
arvore *searchInTree(arvore *,int, arvore *);
arvore *removeRoot(arvore *);
int **getColunas(arvore *);
void setStrInOrder(arvore *, char *);
void printElemPreOrder(arvore *);
void printElemPostOrder(arvore *);
void printElemInOrder(arvore *);
void utilShowTree(arvore *, int);
int getSize(arvore *);
int getSucessor(arvore *, int);
double *leituraDeArquivo(FILE *);
double checaDecimal(double);

///////// teste print
int _print_t(arvore *tree, int is_left, int offset, int depth, char **s)
{
    char b[20];
    int width = 5;

    if (!tree) 
        return 0;

    sprintf(b, "(%03d)", tree->info);

    int left  = _print_t(tree->filhoEsq,  1, offset,depth + 1, s);
    int right = _print_t(tree->filhoDir, 0, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }

    return left + width + right;
}

void print_t(arvore *tree)
{
    char **str = (char **) calloc(getHeight(tree)*2+1,sizeof(char *));

    for (int i = 0; i < getHeight(tree)*2; i++){
        str[i] = calloc(255,sizeof(char));
        sprintf(str[i], "%80s", " ");
    }

    // printf("passou\n");

    _print_t(tree, 0, 0, 0, str);

    for (int i = 0; i < getHeight(tree)*2; i++)
        printf("%s\n", str[i]);
}


//////  adasdasdasdsa

int main(){

    char in[100];
    scanf("%s",in);

    arvore *arv;
    arv = loadTreeFromFile(in);

    // showTree(arv);
    print_t(arv);

    // arv = removeValue(arv,50);

    // showTree(arv);

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


void showTree(arvore *arv){
    utilShowTree(arv,0);
    // printf("\n");
}

void utilShowTree(arvore *arv, int space){
    if(arv == NULL){
        return;
    }

    space+=5;

    utilShowTree(arv->filhoDir,space);

    printf("\n");
    for(int i = 5; i < space; i++){
        printf(" ");
    }

    printf("%d\n",arv->info);

    utilShowTree(arv->filhoEsq,space);
}


void printElemPostOrder(arvore *arv){
    if(arv == NULL)
        return;

    printElemPostOrder(arv->filhoEsq);

    printElemPostOrder(arv->filhoDir);

    printf("%d ",arv->info);
}


void printPostorder(arvore *arv){
    printf("PostOrder: ");

    printElemPostOrder(arv);

    printf("\n");
}


void printElemInOrder(arvore *arv){
    if(arv == NULL)
        return;

    printElemInOrder(arv->filhoEsq);

    printf("%d ",arv->info);

    printElemInOrder(arv->filhoDir);
}


void printElemPreOrder(arvore *arv){
    if(arv == NULL)
        return;

    printf("%d ",arv->info);

    printElemPreOrder(arv->filhoEsq);

    printElemPreOrder(arv->filhoDir);
}


void printPreorder(arvore *arv){
    printf("PreOrder: ");

    printElemPreOrder(arv);

    printf("\n");
}


void printInOrder(arvore *arv){
    printf("InOrder: ");

    printElemInOrder(arv);

    printf("\n");
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


arvore *removeValue(arvore *arv, int info){
    if(arv->info == info){
        arvore *newArv = alocaNo(1);
        newArv = removeRoot(arv);

        return newArv;
    }
    
    arvore *father = alocaNo(1);
    arvore *aux = alocaNo(1);
    arvore *elem;
    father = searchInTree(arv,info,NULL);

    if(father == NULL){
        printf("Elemento não encontrado\n");

        return arv;
    }

    if(father->filhoDir->info == info){
        elem = father->filhoDir;

        if(elem->filhoDir == NULL && elem->filhoEsq == NULL){
            father->filhoDir = NULL;
            free(elem);
        }else if(elem->filhoEsq == NULL){
            father->filhoDir = elem->filhoDir;
            free(elem); 
        }else if(elem->filhoDir == NULL){
            father->filhoDir = elem->filhoEsq;
            free(elem);
        }else{

            int sucessor = getSucessor(arv,info);

            aux = searchInTree(arv,sucessor,NULL);
            
            if(aux->filhoDir->info == sucessor){
                father->filhoDir = aux->filhoDir;
            }else{
                father->filhoEsq = aux->filhoEsq;
            }

            free(elem);
        }
    }else{
        elem = father->filhoEsq;

        if(elem->filhoDir == NULL && elem->filhoEsq == NULL){
            father->filhoEsq = NULL;
            free(elem);
        }else if(elem->filhoEsq == NULL){
            father->filhoEsq = elem->filhoDir;
            free(elem); 
        }else if(elem->filhoDir == NULL){
            father->filhoEsq = elem->filhoEsq;
            free(elem);
        }else{

            int sucessor = getSucessor(arv,info);

            aux = searchInTree(arv,sucessor, NULL);
            
            if(aux->filhoDir->info == sucessor){
                father->filhoEsq = aux->filhoDir;
            }else{
                father->filhoEsq = aux->filhoEsq;
            }

            free(elem);
        }
    }

    return arv;
}

arvore *removeRoot(arvore *arv){
    if(arv->filhoDir == NULL && arv->filhoEsq)
        return NULL;
    else if(arv->filhoEsq == NULL)
        return arv->filhoDir;
    else if(arv->filhoDir == NULL)
        return arv->filhoEsq;

    arvore *fatherSucessor = alocaNo(1);
    arvore *sucessorArv = alocaNo(1);
    arvore *aux = alocaNo(1);

    int sucessor = getSucessor(arv, arv->info);

    fatherSucessor = searchInTree(arv,sucessor,NULL);
    
    sucessorArv = fatherSucessor->filhoEsq;
    aux = fatherSucessor->filhoEsq->filhoDir;

    sucessorArv->filhoDir = arv->filhoDir;
    sucessorArv->filhoEsq = arv->filhoEsq;

    fatherSucessor->filhoEsq = aux;
    free(arv);
    
    return sucessorArv;
}

int getSucessor(arvore *arv, int info){
    char *str = (char *) calloc(((getSize(arv)*10)+getSize(arv)+1),sizeof(char));
    char *aux = (char *) calloc(11,sizeof(char));
    char *charToString = (char *) calloc(2,sizeof(char));
    char *number = (char *) calloc(11,sizeof(char));

    if(str == NULL){
        printf("Erro de alocação\n");
        exit(-1);
    }

    setStrInOrder(arv,str);

    for(int i = 0; i < (int)strlen(str); i++){
        
        while(str[i] != '*'){

            charToString[0] = str[i];
            charToString[1] = '\0';

            strcat(aux,charToString);
            i++;

            memset(charToString,0,strlen(charToString));
        }

        sprintf(number, "%d", info);

        if(strcmp(number,aux) == 0){
            i++;
            memset(aux,0,strlen(aux));
            while(str[i] != '*'){
                charToString[0] = str[i];
                charToString[1] = '\0';

                strcat(aux,charToString);
                i++;

                memset(charToString,0,strlen(charToString));
            }

            return (int) strtol(aux, (char **)NULL, 10);
        }

        memset(aux,0,strlen(aux));
        memset(number,0,strlen(number));
    }

    free(str);
    free(aux);
    free(number);

    return 1;
}

arvore *searchInTree(arvore *arv,int info, arvore *father){
    if(arv == NULL){
        return arv;
    }

    if(arv->info!= info && arv->filhoDir == NULL && arv->filhoEsq == NULL){
        return NULL;
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


void setStrInOrder(arvore *arv, char *str){ 

    char *aux = (char *) calloc(10,sizeof(char));

    if (arv == NULL)
        return; 
  
    setStrInOrder(arv->filhoEsq, str); 

    // copia elementos para a string
    sprintf(aux,"%d",arv->info);
    strcat(str,aux);
    strcat(str,"*");

    setStrInOrder(arv->filhoDir, str);

    free(aux);
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
