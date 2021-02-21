#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}

void printV(Item *v, int s) {
    for(int i = 0; i <= s; i++)
        printf("%d%c", v[i], (i < s? ' ' : '\n'));
}

void InsertSort(Item *v, int l, int r){
    for(int i = r; i > l; i--){
        cmpexch(v[i], v[i-1]);
    }
    

    for(int i = l+2; i <= r; i++){
        int j = i; Item tmp = v[j];

        while(less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }

        v[j] = tmp;

    }
}


int main(){
    int r = 0;
    Item * v = malloc(sizeof(Item) * 1000);

    while(scanf("%d", &v[size]) == 1){
        size++;
    }

    InsertSort(v, 0, (size-1));
    printV(v, (size-1));
    return 0;
}