#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}

void merge(Item *v, int l, int r1, int r2){
    Item *c = malloc(sizeof(Item) * (r2-l+1));

    int k = 0, i = l, j = (r1+1);

    while(i <= r1 && j <= r2){

        if(less(v[i], v[j]))
            c[k++] = v[i++];
        else
            c[k++] = v[j++];
    }

    while(i <= r1)
        c[k++] = v[i++];
    
    while(j <= r2)
        c[k++] = v[j++];

    k = 0, i = l;

    while(i <= r2)
        v[i++] = c[k++];

    free(c);
}

void mergeSort(Item *v, int l, int r){
    if(l >= r) return;
    
    int mid = (r + l)/2;

    mergeSort(v, l, mid);
    mergeSort(v, (mid+1), r);
    merge(v, l, mid, r);
}

void printV(Item *v, int s) {
    for(int i = 0; i <= s; i++)
        printf("%d%c", v[i], (i < s? ' ' : '\n'));
}

int main(){
    int n, x;
    scanf("%d", &n);

    Item *v = malloc(sizeof(Item) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        v[i] = x;
    }

    mergeSort(v, 0, (n-1));
    printV(v, (n-1));

    free(v);
    return 0;
}