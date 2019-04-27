#include "ilbp.h"
#include <math.h>

double distancia_euclidiana(double *number_ilbp, double *number_ilbp_media);
void ilbp(double *number_ilbp, int *image);

int main(){

    double *number_ilbp_media_asphalt = (double*) calloc(512,sizeof(double));
    double *number_ilbp_media_grass = (double*) calloc(512,sizeof(double));

    for(int p = 1; p <= 25; p++){

        FILE *f_asphalt;
        FILE *f_grass;

        char filename_asphalt[50];
        char filename_grass[50];

        char number_image[10];
        
        if(p <= 9){
            strcpy(filename_asphalt,"DataSet/asphalt/asphalt_0");
            strcpy(filename_grass,"DataSet/grass/grass_0");
        }else{
            strcpy(filename_asphalt,"DataSet/asphalt/asphalt_");
            strcpy(filename_grass,"DataSet/grass/grass_");
        }
        
        // number image
        sprintf(number_image, "%d", p);
        strcat(filename_grass,number_image);
        strcat(filename_asphalt,number_image);
        
        // extensao
        strcat(filename_asphalt,".txt");
        strcat(filename_grass,".txt");

        printf("%s - Lendo...\n",filename_asphalt);
        printf("%s - Lendo...\n",filename_grass);

        f_asphalt = fopen(filename_asphalt, "r");
        f_grass = fopen(filename_grass, "r");

        int *asphalt_image = (int*) malloc(1026*1026*sizeof(int));
        int *grass_image = (int*) malloc(1026*1026*sizeof(int));

        for(int i = 0 ;i < 1025; i++){
            for(int j = 0; j < 1025; j++){
                char c;
                fscanf(f_asphalt,"%d%c", (asphalt_image+(i*1026)+j),&c);
                fscanf(f_grass,"%d%c", (grass_image+(i*1026)+j),&c);
            }
        }
        
        // Dados para normalizar vetor
        int menor_asphalt = 9999999;
        int menor_grass = 9999999;
        int maior_asphalt = -1;
        int maior_grass = -1;

        double *number_ilbp_asphalt = (double*) calloc(512,sizeof(double));
        double *number_ilbp_grass = (double*) calloc(512,sizeof(double));

        // pega um pixel

        ilbp(number_ilbp_asphalt,asphalt_image);
        ilbp(number_ilbp_grass,grass_image);    

        for(int i = 0; i < 512; i++){
            if(*(number_ilbp_asphalt+i) < menor_asphalt)    menor_asphalt = *(number_ilbp_asphalt+i);
            if(*(number_ilbp_asphalt+i) > maior_asphalt)    maior_asphalt = *(number_ilbp_asphalt+i);
            if(*(number_ilbp_grass+i) < menor_grass)        menor_grass = *(number_ilbp_grass+i);
            if(*(number_ilbp_grass+i) > maior_grass)        maior_grass = *(number_ilbp_grass+i);
        }

        
        // Normalizando vetor e construindo vetor media
        for(int i = 0; i < 512; i++){
            *(number_ilbp_media_asphalt+i) += (((*(number_ilbp_asphalt+i)) - menor_asphalt)
                /(maior_asphalt - menor_asphalt));

            *(number_ilbp_media_grass+i) += (((*(number_ilbp_grass+i)) - menor_grass)
                /(maior_grass - menor_grass));
        }

        // Limpa memoria
        free(number_ilbp_asphalt);
        free(number_ilbp_grass);

        free(asphalt_image);
        free(grass_image);

        // Fecha arquivo
        fclose(f_asphalt);
        fclose(f_grass);
    }
    
    // Tirando media 
    for(int i = 0; i < 512; i++){
        *(number_ilbp_media_asphalt+i) = *(number_ilbp_media_asphalt+i)/25;
        *(number_ilbp_media_grass+i) = *(number_ilbp_media_grass+i)/25;
    }

    // TESTES
    for(int i = 26; i <= 36; i ++){
        FILE *f_test;

        char filename[50];
        char number_image[10];
    
        strcpy(filename,"DataSet/asphalt/asphalt_");
        
        // number imag
        sprintf(number_image, "%d", i);
        strcat(filename,number_image);
        
        // extensao
        strcat(filename,".txt");

        printf("%s - Testando...\n",filename);

        f_test = fopen(filename, "r");

        int *test_image = (int*) malloc(1026*1026*sizeof(int));

        for(int i = 0 ;i < 1025; i++){
            for(int j = 0; j < 1025; j++){
                char c;
                fscanf(f_test,"%d%c", (test_image+(i*1026)+j),&c);
            }
        }
        
        // Dados para normalizar vetor
        int menor = 9999999;
        int maior = -1;

        double *number_ilbp = (double*) calloc(512,sizeof(double));

        // pega um pixel

        ilbp(number_ilbp,test_image);    

        for(int i = 0; i < 512; i++){
            if(*(number_ilbp+i) < menor)    menor = *(number_ilbp+i);
            if(*(number_ilbp+i) > maior)    maior = *(number_ilbp+i);
        }
        
        // Normalizando vetor e construindo vetor media
        for(int i = 0; i < 512; i++){
            *(number_ilbp+i) += (((*(number_ilbp+i)) - menor)
                /(maior - menor));
        }

        int dist_asphalt_asphalt = distancia_euclidiana(number_ilbp,number_ilbp_media_asphalt);
        int dist_asphalt_grass = distancia_euclidiana(number_ilbp,number_ilbp_media_grass);

        if(dist_asphalt_asphalt < dist_asphalt_grass)
            printf("Sucess\n");
        else
            printf("Failure\n");

        free(number_ilbp);
        free(test_image);
    }

    free(number_ilbp_media_asphalt);
    free(number_ilbp_media_grass);

    return 0;
}

double distancia_euclidiana(double *number_ilbp, double *number_ilbp_media){
    double sum = 0.0;

    for(int i = 0; i < 512;i++){
        double dif = number_ilbp_media[i] - number_ilbp[i];
        sum += pow(dif,2);
    }

    double dist = sqrt(sum);
    
    return dist;
}

void ilbp(double *number_ilbp, int *image){
    for(int i = 1; i < 1024; i++){
        for(int j = 1; j < 1024; j++){
            // Pega area envolta dos pixels 
            int *area = (int*) malloc(3*3*sizeof(int));
            double sum = get_area_pixel(i, j, image, area);

            // Seta a matriz binaria
            int *binario = (int*) malloc(3*3*sizeof(int));
            set_binary_matrix(area, binario, sum);
            
            // Caracol
            char *bin_str = (char*) malloc(9*sizeof(char));
            transform_bin_caracol(bin_str, binario);
            
            // Pega o resultado do ilbp
            int result_ilbp = get_ilbp_numb(bin_str);

            // Seta vetor ilbp resultados
            set_ilbp_number_vector(number_ilbp, result_ilbp);

            // limpa memoria
            free(area);
            free(bin_str);
            free(binario);
        }
    }
}