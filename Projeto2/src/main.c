#include <stdio.h>
#include <string.h>

int main(){

    FILE *f;

    f = fopen("DataSet/asphalt/asphalt_01.txt", "r");

    int matrix[1026][1026];

    for(int i = 0 ;i < 1025; i++){
        for(int j = 0; j < 1025; j++){
            char c;
            fscanf(f,"%d%c",&matrix[i][j],&c);
        }
    }

    int i = 1;
    int j = 1;

    int area[3][3];

    for(int a = i-1; a < i+2; a++){
        for(int b = j-1; b < j+2;b++){
            area[a][b] = matrix[a][b];
        }
    }

    for(int a = 0; a < 3;a++){
        for(int b = 0; b < 3; b++)
            printf("%d ",area[1][1]);
        printf("\n");
    }

    return 0;
}