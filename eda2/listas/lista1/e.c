#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *it1 = l1->prox;
    celula *it2 = l2->prox;

    while(it1 != NULL && it2 != NULL){
        if(it1->dado > it2->dado){
            l3->prox = it2;
            it2 = it2->prox;
        } else {
            l3->prox = it1;
            it1 = it1->prox;
        }

        l3 = l3->prox;
    }

    if(it1 != NULL){
        l3->prox = it1;
    }
    if(it2 != NULL){
        l3->prox = it2;
    }
}

// int main(){

//     return 0;
// }