#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}

int binarySearch(Item *v, int x, int l, int r){

    if(r >= l){
        int mid = l + (r-l)/2;

        if(v[mid] == x){
            return mid;
        }

        if(v[mid] > x){
            return binarySearch(v, x,l, mid-1);
        }

        return binarySearch(v, x, mid+1, r);
    }

    return -1;
}


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

int main(){
    int n, x, cont = 0;
    scanf("%d", &n);

    Item *v = malloc(sizeof(Item) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);

        if(i != 0){
            int j = binarySearch(v, x, 0, (cont-1));
            
            if(j == -1){
                v[cont++] = x;
            }
        } else {
            v[cont++] = x;
        }

        mergeSort(v, 0, cont);
    }

    printf("%d\n", cont);    

    free(v);
    return 0;
}