#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Contato{
    char *nome = (char *) malloc(101*(sizeof(char)));
    struct Contato *prox;
    struct Contato *ant;
}contato;

contato *listaVazia();
contato *adicionarContatoSort(contato *, contato *);

contato *listaVazia(
    return NULL;
)

contato *adicionarContatoSort(contato *lista, contato *elem){
    if(lista == NULL){
        elem->prox = NULL;
        elem->ant = NULL;
        
        return elem;
    }

    contato *it;

    for(it = lista; it != NULL; it = it->prox){
        if(elem->nome[0] <= it->nome[0]){
            contato *aux;
            aux = it->ant;

            it->ant = elem;
            elem->prox = it;

            aux->prox = elem;
            elem->ant = aux;
        }
    }
    
    return lista; 
}

