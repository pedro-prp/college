#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}

int partition (Item *v, int l, int r) {
    Item c = v[r];
    int j = l;
    for(int k = l; k < r; k++)
        if(less(v[k], c)){
            exch(v[k], v[j]);
            j++;
        }

    exch(v[j],v[r]);

    return j;
}

void quickSelect(int *v, int l, int r, int k){

    if(r <= l)  return;

    int m = partition(v, l, r);

    if(m > k)   quickSelect(v, l, m-1, k);
    if(m < k)   quickSelect(v, m+1, r, k);
}


void quickSort(Item *v, int l, int r) {
    if (l < r) {
        int m = partition(v, l, r);

        quickSort(v, l, m - 1);
        quickSort(v, m + 1, r);
    }
}


int main(){

    int s = 0;
    int n, p, x;

    scanf(" %d %d %d", &n, &p, &x);

    int * v = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf(" %d", &v[i]);
    }

    int position = p * x;
    int end = position + x - 1;

    quickSelect(v, 0, n-1, position);
    quickSelect(v, position+1, n-1, end);
    quickSort(v, position+1, end-1);

    for(int i = 0; i < x; i++){
        if(position < n){
            printf("%d\n", v[position]);
            position++;
        }
    }

    return 0;
}