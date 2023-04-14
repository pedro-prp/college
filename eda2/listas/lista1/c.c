#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

int remove_depois (celula *p){
    if(p == NULL || p->prox == NULL){
        return 1;
    }

    celula *tmp;
    int data;

    tmp = p->prox;
    p->prox = tmp->prox;
    data = tmp->dado;
    free(tmp);

    return data;
}

void remove_elemento (celula *le, int x){
    celula *tmp, *it;

    tmp = le;
    it = le->prox;

    while(it != NULL && it->dado != x) {
        tmp = it;
        it = it->prox;
    }

    if(it != NULL){
        tmp->prox = it->prox;
        free(it);
    }

}

void remove_todos_elementos (celula *le, int x){
    celula *tmp, *it;
    tmp = le;
    it = le->prox;

    while(it != NULL){
        if(it -> dado == x){
            celula *remove = it;
            it = it->prox;
            tmp->prox = it;
            free(remove);
        } else {
            tmp = it;
            it = it->prox;
        }

    }
}

// int main() {

//     return 0;
// }