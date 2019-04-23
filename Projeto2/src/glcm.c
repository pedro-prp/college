#include "glcm.h"
#include <string.h>
#include <math.h>

int *set_vector(FILE *f, int tam, int top, int *vec){
    char *c, var[1], comp[0];
    char num[top];
    int bot = 1, i = 0, j = 0;

    f = fopen("grass_01.txt", "r");

    while(!feof(f)){
        fscanf(f, "%c", &c);
        if(c != ";" && c != '\n'){
            comp[0] = c;
            num[i] = comp[0];
            i < (top - 1) ? i++ : i;

        }
        else if(j < tam){
            vec[j] = atoi(num);
            j++;
            for(int n = 0; n < top; n++)
                num[n] = comp[0];
            i = 0;
        }
        
    }
    fclose(f);
    return vec;
}

int *delete_vector(int *v){
    free(v);
}

float *glcm(int *matrix, int line, int num_of_lines, float *constraints){
    return 0;
}