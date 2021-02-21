#include <stdio.h>
#include <stdlib.h>

typedef struct numbers{
    int value;
    int pos;
} numbers;

#define Item int
#define key(a) (a.value)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}


void printV(Item *v, int s) {
    for(int i = 0; i <= s; i++)
        printf("%d%c", v[i], (i < s? ' ' : '\n'));
}

int binarySearch(Item *v, int x, int l, int r){

    if(r >= l){
        int mid = l + (r-l)/2;

        if(v[mid-1] < x && x <= v[mid]){
            return mid;
        }

        if(v[mid] > x){
            return binarySearch(v, x,l, mid-1);
        }

        return binarySearch(v, x, mid+1, r);
    }

    return (r+l)/2;
}

int main(){
    int m, n, x, j, nf = -1;
    scanf("%d %d", &m, &n);

    Item *v = malloc(sizeof(Item) * m);

    for(int i = 0; i < m; i++){
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        j = binarySearch(v, x, 0, m);
        printf("%d\n", j == -1 ? nf : j);
    }

    free(v);
    return 0;
}
