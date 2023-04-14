#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *tmp = malloc(sizeof(celula));

    tmp->dado = x;
    tmp->prox = le->prox;

    le->prox = tmp;
}

void insere_antes (celula *le, int x, int y){
    celula *new_element = malloc(sizeof(celula));
    new_element->dado = x;

    if(le->dado == y){
        insere_inicio(le, x);

        return;
    }

    celula *it = le;

    while(it != NULL){
        if(it->prox == NULL){
            it->prox = new_element;
            new_element->prox = NULL;
            return;
        }

        if(it->prox->dado == y){
            celula *tmp;
            tmp = it->prox;
            
            it->prox = new_element;
            new_element->prox = tmp;

            return;
        }

        it = it->prox;
    }
}

// void imprime (celula *le){
// 	for(celula *it=le; it != NULL; it = it->prox){
// 		printf("%d -> ", it->dado);
// 	}
// 	printf("NULL\n");
// }


// int main(){
// 	celula *jose = malloc(sizeof(celula));
// 	celula *joaquin = malloc(sizeof(celula));
// 	celula *juarez = malloc(sizeof(celula));

// 	jose->dado = 4;
// 	jose->prox = NULL;
// 	imprime(jose);

//     insere_inicio(jose, 2);
    
// 	imprime(jose);
    
//     insere_inicio(jose, 1);

// 	imprime(jose);
	
//     insere_antes(jose,3,1);

//     imprime(jose);

// 	return 0;
// }