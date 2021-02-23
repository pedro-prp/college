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

int main(){
    int n, size = 0, x;
    scanf(" %d", &n);

    // Item *v = malloc(sizeof(Item) * n);
    Item v[66000];

    for(int i = 0; i < n; i++){
        scanf(" %d", &v[i]);
    }

    size += n;

    quickSort(v, 0, (size-1));

    // int *vnd = malloc(sizeof(Item) * size);
    Item vnd[66000];
    int cont = 0;

    vnd[0] = v[0];
    cont++;

    for(int i = 1; i < n; i++){
        int j = binarySearch(vnd, v[i], 0, cont-1);

        if(j == -1){
            vnd[cont] = v[i];
            cont++;
        }
    }

    int sum;
    
    if(cont % 2 != 0){
        vnd[cont++] = 1000000000;
    }
    int n_v = cont;
    int cont_v3 = 0;
    int v_f[66000];

    for(int i = 0; i < (n_v-1); i ++){
        sum = vnd[i] + vnd[++i];

        int j = binarySearch(vnd, sum, 0, cont-1);

        int pos;

        if(j == -1){
            for(int k = 0; k < (n_v); k++){
                if(sum < v[k]){
                   v_f[cont_v3] = sum;
                   cont_v3++; 
                   break;
                }
            }
        } 
        
        v_f[cont_v3] = vnd[i];
        cont_v3++; 
    }

    printV(v_f, cont_v3-1);

    for(int i = 0; i < cont_v3; i+=4){
        printf("%d\n", v_f[i]);
    }

    printf("Elementos: %d\n", cont_v3);

    return 0;
}
