#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Contato{
    char *nome;
    struct Contato *prox;
    struct Contato *ant;
}contato;

contato *listaVazia();
contato *geraElem(char *);
contato *adicionarContatoSort(contato *, contato *);
void printaLista(contato *);

int main(){

    printf("\nHello World\n\n");
    contato *lista = (contato*) malloc(sizeof(contato));
    lista = listaVazia();

    contato *new;
    char *nome = (char*) malloc(101*(sizeof(char)));
    strcpy(nome,"jose");
    new = geraElem(nome);

    contato *new1;
    char *nome1 = (char*) malloc(101*(sizeof(char)));
    strcpy(nome1,"pedro");
    new1 = geraElem(nome1);

    contato *new2;
    char *nome2 = (char*) malloc(101*(sizeof(char)));
    strcpy(nome2,"bia");
    new2 = geraElem(nome2);

    contato *new3;
    char *nome3 = (char*) malloc(101*(sizeof(char)));
    strcpy(nome3,"manuela");
    new3 = geraElem(nome3);

    contato *new4;
    char *nome4 = (char*) malloc(101*(sizeof(char)));
    strcpy(nome4,"kamile");
    new4 = geraElem(nome4);

    contato *new5;
    char *nome5 = (char*) malloc(101*(sizeof(char)));
    strcpy(nome5,"zannier");
    new5 = geraElem(nome5);

    contato *new6;
    char *nome6 = (char*) malloc(101*(sizeof(char)));
    strcpy(nome6,"Ana");
    new6 = geraElem(nome6);

    lista = adicionarContatoSort(lista,new);
    lista = adicionarContatoSort(lista,new1);
    lista = adicionarContatoSort(lista,new2);
    lista = adicionarContatoSort(lista,new3);
    lista = adicionarContatoSort(lista,new4);
    lista = adicionarContatoSort(lista,new5);
    lista = adicionarContatoSort(lista,new6);

    printaLista(lista);

    printf("\nBye World\n\n");
    return 0;
}

contato *listaVazia(){
    return NULL;
}

contato *adicionarContatoSort(contato *lista, contato *elem){
    if(lista == NULL){
        elem->prox = NULL;
        elem->ant = NULL;
        
        return elem;
    }

    else if(lista->prox == NULL){
        if((int)toupper(elem->nome[0]) <= (int)toupper(lista->nome[0])){
            elem->prox = lista;
            lista->ant = elem;

            lista->prox = NULL;
            elem->ant = NULL;

            return elem;
        }else{
            lista->prox = elem;
            elem->ant = lista;

            elem->prox = NULL;
            lista->ant = NULL;

            return lista;
        }
    }
    else{
        contato *it = (contato*) malloc(sizeof(contato));
        int i = 0;
        for(it = lista; it != NULL; it = it->prox){
            if((int)toupper(elem->nome[0]) <= (int)toupper(it->nome[0])){
                if(i == 0){
                    elem->prox = it;
                    elem->ant = NULL;
                    it->ant = elem;

                    return elem;
                }
                contato *aux;
                aux = it->ant;

                elem->prox = it;
                it->ant = elem;
                elem->ant = aux;
                aux->prox = elem;

                return lista;

            }

            else if(it->prox == NULL){
                it->prox = elem;
                elem->prox = NULL;
                elem->ant = it;

                return lista;
            }
            i++;
        }

        free(it);
        return lista;
    }
}

contato *geraElem(char *nome){
    contato *elem = (contato*) malloc(sizeof(contato));
    elem->nome = (char*) malloc(101*(sizeof(char)));
    strcpy(elem->nome, nome);

    return elem;
}

void printaLista(contato *lista){
    contato *it;
    for(it = lista; it != NULL; it = it->prox){
        printf("%s\n",it->nome);
    }
}
