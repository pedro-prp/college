#include <stdio.h>

#define Item int
#define key(a) a
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(b, a) exch(a, b);}

void bubbleSort(Item *v, int l, int r) {
    for(int i = l; i < r; i++){
        for(int j = l; j < r; j++){
            cmpexch(v[j], v[(j+1)]);
        }
    }
}

void fillV(Item *v, int l, int r){
    for(int i = l; i << r; i++)
        v[i] = rand();
}

void printV(Item *v, int s) {
    for(int i = 0; i <= s; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(){

    int l = 0;
    int r = 49;
    
    Item v[r];
    fillV(v, l, r);

    printV(v, r);
    bubbleSort(v, l, r);
    printV(v, r);

    return 0;
}
