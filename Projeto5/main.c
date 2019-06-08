// Projeto 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

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
arvore *balanceTree(arvore *);


// funções auxiliares para funcionamento da biblioteca
arvore *menu(int,arvore *);
void printMenu();
arvore *arvoreVazia();
arvore *alocaNo(int);
arvore *insereElem(arvore *,int);
arvore *insereVector(arvore *, double *);
arvore *searchInTree(arvore *,int, arvore *);
arvore *removeRoot(arvore *);
arvore *setArvBackBone(arvore *, arvore *, arvore*);
void rodarDir(arvore *,arvore *,arvore *);
void rodarEsq(arvore *,arvore *,arvore *);
arvore *desfazBackbone(arvore *, int);
arvore *transfBackbone(arvore *);
int **getColunas(arvore *);
void setStrInOrder(arvore *, char *);
void printElemPreOrder(arvore *);
void printElemPostOrder(arvore *);
void printElemInOrder(arvore *);
int buildStrTree(arvore *, int, int, int, char **);
int checaArvBalanceada(arvore *);
int getSize(arvore *);
int getSucessor(arvore *, int);
double *leituraDeArquivo(FILE *);
double checaDecimal(double);


int main(){
    int d=-1;
    arvore *arv = arvoreVazia();
    while(d!=11){
        printMenu();
        scanf(" %d",&d);
        arv = menu(d,arv);
    }


    return 0;
}


arvore *loadTreeFromFile(char *path){
    arvore *arv = arvoreVazia();
    double *vector;    
    
    FILE *f;  
    f = fopen(path,"r");
    if(f == NULL){
        printf("Erro de leitura\n");
        return NULL;
    }
    vector = leituraDeArquivo(f);

    arv = insereVector(arv, vector);

    fclose(f);
    
    return arv;
}


void rodarDir(arvore *avo,arvore *pai,arvore *filho){
    if(avo != NULL){
        if(avo->filhoEsq == pai){
            avo->filhoEsq = filho;
        }else{
            avo->filhoDir = filho;
        }
    }

    pai->filhoEsq = filho->filhoDir;
    filho->filhoDir = pai;
}


void rodarEsq(arvore *avo,arvore *pai,arvore *filho){
    if(avo != NULL){
        if(avo->filhoEsq == pai){
            avo->filhoEsq = filho;
        }else{
            avo->filhoDir = filho;
        }
    }

    pai->filhoDir = filho->filhoEsq;
    filho->filhoEsq = pai;
}


arvore *transfBackbone(arvore *raiz){

    arvore *avo = arvoreVazia();
    arvore *pai = arvoreVazia();
    arvore *filho = raiz;

    while(filho != NULL){
        if(filho->filhoEsq){
            if(filho == raiz){
                raiz = filho->filhoEsq;
            }

            pai = filho;
            filho = filho->filhoEsq;
            rodarDir(avo,pai,filho);
        }else{
            avo = filho;
            filho = filho->filhoDir;
        }
    }

    return raiz;
}

arvore *desfazBackbone(arvore *arv, int number){

    arvore *avo = arvoreVazia();
    arvore *pai = arvoreVazia();
    arvore *filho = arvoreVazia();

    while(number > 0){
        for(int i = 0; i <= 1; i++){
            avo = pai;
            pai = filho;

            if(filho){
                filho = filho->filhoDir;
            }else if(pai == NULL){
                filho = arv;
            }
        }

        if(pai == arv){
            arv = filho;
        }

        rodarEsq(avo,pai,filho);
        number--;
    }


    return arv;
}


arvore *balanceTree(arvore *arv){
    if(checaArvBalanceada(arv) == 1){
        printf("Árvore já balanceada\n");
        return arv;
    }else{
        arv = transfBackbone(arv);

        int size = getSize(arv);
        int auxFolhas = (1 << ((int) floor(log(size+1)/log(2)))) - 1;

        arv = desfazBackbone(arv, (size - auxFolhas));

        while (auxFolhas > 1){
            auxFolhas = auxFolhas/2;
            arv = desfazBackbone(arv,auxFolhas);
        }

        printf("Árvore balanceada com sucesso\n");
    }

    return arv;
}


void showTree(arvore *arv){
    if(arv == NULL){
        printf("Árvore vazia\n");
        return;
    }


    printf("+");
    for(int i = 0; i < 78; i++){
        printf("-");
    }printf("+\n");

    printf("|\t\t\t\tÁrvore binária\t\t\t\t       |\n");

    printf("+");
    for(int i = 0; i < 78; i++){
        printf("-");
    }printf("+\n");

    char **str = (char **) calloc(getHeight(arv)*2+1,sizeof(char *));

    for (int i = 0; i < getHeight(arv)*2; i++){
        str[i] = calloc(255,sizeof(char));
        sprintf(str[i], "%80s", " ");
    }
    
    buildStrTree(arv, 0, 0, 0, str);

    for (int i = 0; i < getHeight(arv)*2; i++){
        printf("%s\n", str[i]);
        free(str[i]);
    }
    free(str);
    for(int i = 0; i < 80; i++){
        printf("-");
    }printf("\n");
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
    if(arv ==  NULL){
        printf("Árvore ainda não lida\n");
        return;        
    }

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


void printMenu(){
    printf("+--------------------------------------------------------------------------------+\n");
    printf("|                      Biblioteca arvore binária                                 |\n");
    printf("+--------------------------------------------------------------------------------+\n");
    printf("|   1.  Ler Árvore de um arquivo                                                  |\n");
    printf("|   2.  Printar Árvore                                                            |\n");
    printf("|   3.  Verificar Árvore cheia                                                    |\n");
    printf("|   4.  Procurar elemento                                                         |\n");
    printf("|   5.  Pegar altura da Árvore                                                    |\n");
    printf("|   6.  Remover um elemento                                                       |\n");
    printf("|   7.  Printar travessia InOrder                                                 |\n");
    printf("|   8.  Printar travessia PreOrder                                                |\n");
    printf("|   9.  Printar travessia PostOrder                                               |\n");
    printf("|   10. Balancear Árvore                                                         |\n");
    printf("|   11. Sair                                                                     |\n");
    printf("+--------------------------------------------------------------------------------+\n");
}


arvore *menu(int d,arvore *arv){
    switch(d){
        case 1:{
            char *str = (char *) malloc(100*sizeof(char));
            
            printf("Arquivo: ");
            scanf("%s",str);
            
            arv = loadTreeFromFile(str);
            if(arv != NULL){
                printf("\nÁrvore lida com sucesso\n");
            }

            free(str);
            break;
        }
        case 2:
            if(arv != NULL)
                showTree(arv);
            else{
                printf("Árvore ainda não lida\n");
            }
            
            break;
        case 3:
            isFull(arv);
            break;
        case 4:{
            int info;
            
            printf("Elemento a ser buscado: ");
            scanf("%d",&info);

            searchValue(arv, info);
            break;
        }
        case 5:{
            int height = getHeight(arv);
            if(height == 0){
                printf("Árvore vazia\n");
            }else{
                printf("Altura: %d\n",height);
            }

            break;
        }
        case 6:{
            int info;
            printf("Elemento a ser removido: ");
            scanf("%d",&info);
            
            arv = removeValue(arv,info);
            break;
        }   
        case 7:
            printInOrder(arv);
            break;
        case 8:
            printPreorder(arv);
            break;
        case 9:
            printPostorder(arv);
            break;
        case 10:
            if(arv != NULL)
                arv = balanceTree(arv);
            else{
                printf("Árvore ainda não lida\n");
            }
            break;
        case 11:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    return arv;
}


arvore *removeValue(arvore *arv, int info){
    if(arv == NULL){
        printf("Árvore ainda não lida\n");
        return arv;
    }


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
    
    printf("Elemento removido com sucesso\n");
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
    if(arv == NULL){
        printf("Árvore vazia\n");
        return;
    }

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


int checaArvBalanceada(arvore *arv){
    if(arv == NULL){
        return 1;
    }

    // pegar diferenças de altura
    int dirHeight = getHeight(arv->filhoDir);
    int esqHeight = getHeight(arv->filhoEsq);

    int diferenca = abs(dirHeight - esqHeight);

    if(diferenca <= 1){
        if(checaArvBalanceada(arv->filhoDir) && checaArvBalanceada(arv->filhoEsq)){
                return 1;
           }
    }

    return 0;
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


int buildStrTree(arvore *arv, int temEsq, int desloc, int tam, char **s){
    // char b[20];
    char *aux = (char *) calloc(10,sizeof(char));
    int espaco = 5;

    if (!arv) 
        return 0;

    sprintf(aux, "|%03d|", arv->info);

    int subArvEsq  = buildStrTree(arv->filhoEsq,  1, desloc,tam + 1, s);
    int subArvDir = buildStrTree(arv->filhoDir, 0, desloc + subArvEsq + espaco, tam + 1, s);

    for(int i = 0; i < espaco; i++)
        s[2 * tam][desloc + subArvEsq + i] = aux[i];

    if(tam && temEsq){
        for (int i = 0; i < espaco + subArvDir; i++)
            s[2 * tam - 1][desloc + subArvEsq + espaco/2 + i] = '-';

        s[2 * tam - 1][desloc + subArvEsq + espaco/2] = '+';
        s[2 * tam - 1][desloc + subArvEsq + espaco + subArvDir + espaco/2] = '+';

    }else if (tam && !temEsq){
        for (int i = 0; i < subArvEsq + espaco; i++)
            s[2 * tam - 1][desloc - espaco/2 + i] = '-';

        s[2 * tam - 1][desloc + subArvEsq + espaco/2] = '+';
        s[2 * tam - 1][desloc - espaco/2 - 1] = '+';
    }

    free(aux);
    return (subArvEsq + espaco + subArvDir);
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
