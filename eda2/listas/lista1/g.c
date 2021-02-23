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

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
} 


int main(){
    int size = 0;
    Item * v = malloc(sizeof(Item) * 50000);

    while(scanf("%d", &v[size]) == 1){
        size++;
    }

    insertionSort(v, (size));
    printV(v, (size-1));
    return 0;
}