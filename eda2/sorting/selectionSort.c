#include <stdio.h>

#define Item int
#define key(a) a
#define less(a, b) ( key(a) < key(b) )
#define exch(a, b) { Item t = a; a = b; b = t; }
#define cmpexch(a, b) { if less(a, b) exch(a, b); }

void selectionSortRec(Item *v, int l, int r){
    if(l == r)
        return;

    int min = l;

    for(int i = (l+1); i <= r; i++){
        if(less(v[i], v[min])) {
            min = i;
        }
    }

    exch(v[l], v[min]);

    selectionSortRec(v, (l+1), r);
}

void selectionSortIt(Item *v, int l, int r){
    
    for(int i = l; i <= r; i++){
        int min = i;

        for(int j = (i+1); j <= r; j++){
            if(less(v[j], v[min])){
                min = j;
            }
        }

        exch(v[i], v[min]);
    }
}


void printV(Item *v, int s) {
    for(int i = 0; i < s; i++)
        printf("%d ", v[i]);
    printf("\n");
}


int main(){

    Item v[1000];
    
    for(int i = 0; i < 1000; i++){
        v[i] = rand();
    }

    // printV(v, 1000);
    selectionSortIt(v, 0, 999);
    selectionSortRec(v, 0, 999);
    // printV(v, 1000);

    return 0;
}