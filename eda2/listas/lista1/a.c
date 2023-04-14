#include <stdio.h>
// #include <stdlib.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

void imprime (celula *le){
 	if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }

	celula *it = le->prox;

    while (it != NULL) {
        printf("%d -> ", it->dado);
        it = it->prox;
    }

    printf("NULL\n");
}

void imprime_rec (celula *le){
	if(le->prox == NULL){
		printf("NULL\n");
		return;
	}
	
	printf("%d -> ", le->prox->dado);
	imprime_rec(le->prox);
}

int main(){
	celula *jose = malloc(sizeof(celula));
	celula *joaquin = malloc(sizeof(celula));
	celula *juarez = malloc(sizeof(celula));

	jose->dado = 1;
	jose->prox = joaquin;

	// jose = NULL;

	joaquin->dado = 2;
	joaquin->prox = juarez;
	// 1 -> 2 -> 3 -> NULL

	juarez->dado = 3;
	juarez->prox = NULL;

	imprime(jose);
	imprime_rec(jose)
	return 0;
}