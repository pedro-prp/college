#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void avanc_string(char *v);

int main(){

    // ler imagem
    FILE *f;

    f = fopen("DataSet/asphalt/asphalt_01.txt", "r");

    int matrix[1026][1026];

    for(int i = 0 ;i < 1025; i++){
        for(int j = 0; j < 1025; j++){
            char c;
            fscanf(f,"%d%c",&matrix[i][j],&c);
        }
    }

    // pega um pixel
    double sum = 0;
    for(int i = 1; i < 2; i++){
        for(int j = 1; j < 5; j++){
            sum = 0;
            // int *area;
            // area = (int*) malloc(3*3*sizeof(int));
            int area[3][3];
            int binario[3][3];

            int lin = 0, col = 0;
            for(int a = i-1; a < i+2; a++){
                col = 0;
                for(int b = j-1; b < j+2;b++){
                    area[lin][col] = matrix[a][b];
                    printf("%d ",area[lin][col]);
                    sum+= area[lin][col];
                    col++;
                }
                lin++;
                printf("\n");
            }
            printf("%lf\n",sum/9);
            // faz a matriz binaria
            for(int a = 0; a < 3;a++){
                for(int b = 0; b < 3; b++){
                    // if(*(area+(a*3)+b) > (sum/9))
                    if(area[a][b] > (sum/9))
                        binario[a][b] = 1;
                    else
                        binario[a][b] = 0;

                    printf("%d %lf %d\n",area[a][b],(sum/9),binario[a][b]);
                }
            }

            // caracol

            char bin_str[9];

            bin_str[0] = (char)binario[0][0]+48;
            bin_str[1] = (char)binario[0][1]+48;
            bin_str[2] = (char)binario[0][2]+48;
            bin_str[3] = (char)binario[1][2]+48;
            bin_str[4] = (char)binario[2][2]+48;
            bin_str[5] = (char)binario[2][1]+48;
            bin_str[6] = (char)binario[2][0]+48;
            bin_str[7] = (char)binario[1][0]+48;
            bin_str[8] = (char)binario[1][1]+48;

            int result_ilbp = (int) strtol(bin_str, NULL, 2);

            for(int a = 0; a < 8;a++){
                avanc_string(&bin_str);
                
                if((int) strtol(bin_str, NULL, 2) < result_ilbp)
                    result_ilbp = (int) strtol(bin_str, NULL, 2);
                
            }

            printf("%d\n",result_ilbp);

            for(int a = 0; a < 3; a++)
                for(int b = 0; b < 3; b++)
                    area[a][b] = 0;
        }
    }

    
    return 0;
}
void avanc_string(char *v){
    char *ptr = v;
    char *temp = malloc(9*sizeof(char));

    temp[0] = ptr[8];
    
    for(int i = 1; i < 9; i++){
        temp[i] = ptr[i-1];
    }
    for(int i = 0; i < 9; i++){
        *(v+i) = *(temp+i);
    }
    free(temp);
}
