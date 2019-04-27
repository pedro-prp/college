// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
#include "ilbp.h"
//
// void avanc_string(char *v);
//
// double get_area_pixel(int i, int j, int *matrix, int *area);
// void set_binary_matrix(int *area,int *binario, double sum);
// void transform_bin_caracol(char *bin_str,int *binario);
// int get_ilbp_numb(char *bin_str);
// void set_ilbp_number_vector(int *number_ilbp,int result_ilbp);

int main(){

    double *number_ilbp_media = (double*) calloc(512,sizeof(double));

    for(int p = 1; p <= 25; p++){

        FILE *f;
        char filename[50];
        char number_image[10];
        
        if(p <= 9)
            strcpy(filename,"DataSet/asphalt/asphalt_0");
        else
            strcpy(filename,"DataSet/asphalt/asphalt_");
        
        // number image
        sprintf(number_image, "%d", p);
        strcat(filename,number_image);
        
        // extensao
        strcat(filename,".txt");
        printf("%s\n",filename);


        f = fopen(filename, "r");

        int *matrix = (int*) malloc(1026*1026*sizeof(int));

        for(int i = 0 ;i < 1025; i++){
            for(int j = 0; j < 1025; j++){
                char c;
                fscanf(f,"%d%c", (matrix+(i*1026)+j),&c);
            }
        }

        int *number_ilbp = (int*) calloc(512,sizeof(int));

        // pega um pixel
        for(int i = 1; i < 1024; i++){
            for(int j = 1; j < 1024; j++){
                // Pega area envolta dos pixels
                int *area = (int*) malloc(3*3*sizeof(int));
                double sum = get_area_pixel(i, j, matrix, area);

                // Seta a matriz binaria
                int *binario = (int*) malloc(3*3*sizeof(int));
                set_binary_matrix(area, binario, sum);

                // caracol
                char *bin_str = (char*) malloc(9*sizeof(char));
                transform_bin_caracol(bin_str, binario);

                // Pega o resultado do ilbp
                int result_ilbp = get_ilbp_numb(bin_str);

                // Seta vetor ilbp resultados
                set_ilbp_number_vector(number_ilbp,result_ilbp);

                // limpa memoria
                free(area);
                free(bin_str);
                free(binario);
            }
        }

        // Print vetor ilbp
        for(int i = 0; i < 512; i++) {
            *(number_ilbp_media+i) += *(number_ilbp+i);
        }

        // Limpa memoria
        free(number_ilbp);
        free(matrix);

        // Fecha arquivo
        fclose(f);
    }

    printf("\n");
    for(int i = 0; i < 512; i++){
        if(*(number_ilbp_media+i) != 0){
            printf("[%d] = %lf\n",i,*(number_ilbp_media+i)/25);
        }
    }
    

    return 0;
}
//
// double get_area_pixel(int i, int j,int *matrix, int *area){
//     int lin = 0, col = 0;
//     double sum = 0;
//     for(int a = i-1; a < i+2; a++){
//         col = 0;
//         for(int b = j-1; b < j+2;b++){
//             *(area+(lin*3)+col) = *(matrix+(a*1026)+b);
//             sum+= *(area+(lin*3)+col);
//             col++;
//         }
//         lin++;
//     }
//
//     return sum;
// }
//
// void set_binary_matrix(int *area,int *binario, double sum){
//     for(int a = 0; a < 3;a++){
//         for(int b = 0; b < 3; b++){
//             if(*(area+(a*3)+b) > (sum/9))
//                 *(binario+(a*3)+b) = 1;
//             else
//                 *(binario+(a*3)+b) = 0;
//         }
//     }
// }
//
// void transform_bin_caracol(char *bin_str,int *binario){
//     *(bin_str + 0) = (char)(*(binario+(3*0)+0))+48;
//     *(bin_str + 1) = (char)(*(binario+(3*0)+1))+48;
//     *(bin_str + 2) = (char)(*(binario+(3*0)+2))+48;
//     *(bin_str + 3) = (char)(*(binario+(3*1)+2))+48;
//     *(bin_str + 4) = (char)(*(binario+(3*2)+2))+48;
//     *(bin_str + 5) = (char)(*(binario+(3*2)+1))+48;
//     *(bin_str + 6) = (char)(*(binario+(3*2)+0))+48;
//     *(bin_str + 7) = (char)(*(binario+(3*1)+0))+48;
//     *(bin_str + 8) = (char)(*(binario+(3*1)+1))+48;
// }
//
// int get_ilbp_numb(char *bin_str){
//     int result_ilbp = (int) strtol(bin_str, NULL, 2);
//     for(int a = 0; a < 8;a++){
//         avanc_string(bin_str);
//
//         if((int) strtol(bin_str, NULL, 2) < result_ilbp)
//             result_ilbp = (int) strtol(bin_str, NULL, 2);
//
//     }
//     return result_ilbp;
// }
//
// void set_ilbp_number_vector(int *number_ilbp,int result_ilbp){
//     *(number_ilbp+result_ilbp) = *(number_ilbp+result_ilbp) + 1;
// }
//
//
// void avanc_string(char *v){
//     char *ptr = v;
//     char *temp = malloc(9*sizeof(char));
//
//     temp[0] = ptr[8];
//
//     for(int i = 1; i < 9; i++){
//         temp[i] = ptr[i-1];
//     }
//     for(int i = 0; i < 9; i++){
//         *(v+i) = *(temp+i);
//     }
//     free(temp);
// }
