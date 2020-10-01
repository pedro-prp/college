#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}

int partition (Item *v, int l, int r) {
    int p = v[r];
    int i = (l - 1);

    for (int j = l; j <= r- 1; j++) {
        if (v[j] <= p) {
            i++;
            exch(v[i], v[j]);
        }
    }

    exch(v[i + 1], v[r]);

    return (i + 1);
}

void quickSort(Item *v, int l, int r) {
    if (l < r) {
        int m = partition(v, l, r);

        quickSort(v, l, m - 1);
        quickSort(v, m + 1, r);
    }
}

void printV(Item *v, int s) {
    for(int i = 0; i <= s; i++)
        printf("%d%c", v[i], (i < s? ' ' : '\n'));
}

int main(){

    Item * v = malloc(sizeof(Item) * 100001);
    int s = 0, x;

    while(scanf("%d", &x) == 1) {
        v[s] = x;
        s++;
    }

    s--;


    quickSort(v, 0, s);
    printV(v, s);

    return 0;
}