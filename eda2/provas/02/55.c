#include <stdio.h>
#include <stdlib.h>

int main(){
    int maior = -1, chosen = -1;
    int n, x;

    int *v = calloc(sizeof(int), 2001);

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);

        v[x]++;

        if(v[x] > maior){
            maior = v[x];
            chosen = x;
        }
        if(v[x] == maior){
            if(x > chosen){
                chosen = x;
            }
        }
    }

    printf("%d\n", chosen);


    return 0;
}