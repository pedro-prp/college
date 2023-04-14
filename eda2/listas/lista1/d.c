#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

celula *busca (celula *le, int x) {
    for(celula *it = le; it != NULL; it = it -> prox){
        if(it->dado == x){
            return it;
        }
    }

    return NULL;
}

celula *busca_rec (celula *le, int x){    
    if(le == NULL || le->dado == x){
        return le;
    }

    busca_rec(le->prox, x);
}

// int main() {

//     return 0;
// }