#include <stdio.h>
#include <stdlib.h>

int InsertSort(int *v, int reg, int size){
    for(int i = 0; i < size; i++){
        if(v[i] == reg){
            return size;
        }else if(v[i] > reg){
            int tmp = v[i];
            v[i] = reg;
            v[i++] = tmp;
            return ++size;
        }
    }
    v[size++] = reg;

    return size;
}


int main(){
    int n, reg, size = 0, cont = 0;
    scanf("%d", &n);

    int * v = malloc(sizeof(int) * n);

    scanf("%d", &v[0]);
    size++;

    for(int i = 1; i < n; i++){
        scanf("%d", &reg);
        size = InsertSort(v, reg, size);
    }

    printf("%d\n", size);

    return 0;
}