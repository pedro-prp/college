#include "ilbp.c"
#include "glcm.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// sorteia aleatoriamente 50 números, 25 pra teste e 25 pra treinamento
int *sorteio_teste_treino(){
    srand(time(NULL));
    int *n = (int *)malloc(50*sizeof(int));

    int x = 1, y = 0;
    n[0] = rand() % 50 + 1;

    while(x < 50)
    {
        n[x] = rand() % 50 + 1;
        y = 0;

        while(y < x)
        {
            if(n[y] == n[x])
            {
                --x;
                break;
            }
            ++y;
        }
        ++x;
    }

    return n;
}

// Gera arquivos com os caminhos para as imagens sorteadas (grama teste, grama treino, asfalto teste e asfalto treinamento).
// Têm que estar em DataSet/grass e DataSet/asphalt
int salva_arquivos(int *vetor, int teste_treino, int grama_asfalto){
    char nome[20];
    char diretorio[256];
    int i = 0;
    int tipo;

    if(teste_treino == 0 && grama_asfalto == 0){
        strcpy(nome,"teste_grass.txt");
        strcpy(diretorio,"DataSet/grass/grass_");
        tipo = 0;
    }
    else if (teste_treino == 0 && grama_asfalto == 1){
        strcpy(nome,"teste_asphalt.txt");
        strcpy(diretorio,"DataSet/asphalt/asphalt_");
        tipo = 1;
    }
    else if (teste_treino == 1 && grama_asfalto == 0){
        strcpy(nome,"treino_grass.txt");
        strcpy(diretorio,"DataSet/grass/grass_");
        tipo = 2;
    }
    else if (teste_treino == 1 && grama_asfalto == 1){
        strcpy(nome,"treino_asphalt.txt");
        strcpy(diretorio,"DataSet/asphalt/asphalt_");
        tipo = 3;
    }
    else{
        printf("ERRO");
    }
    // printf("Criando: %s \n", nome);
    FILE *arquivo = NULL;
    arquivo = fopen(nome, "wt");

    int aux;
    char temp[50];

   for(i = 0; i < 25; i++){
        if(vetor[i] < 10){
            aux = sprintf(temp, "%s0%d.txt\n", diretorio, vetor[i]);
            fprintf(arquivo, "%s", temp);
        }else if(vetor[i] >= 10){
           aux = sprintf(temp, "%s%d.txt\n", diretorio, vetor[i]);
           fprintf(arquivo, "%s", temp);
       }
   }
   fclose(arquivo);
   return tipo;
}

int main()
{
    int * ordem_imagem_asfalto;
    int * ordem_imagem_grama;

    ordem_imagem_asfalto = sorteio_teste_treino();
    ordem_imagem_grama = sorteio_teste_treino();

    int asfalto_treino[25] = {0};
    int asfalto_teste[25] = {0};
    int grama_treino[25] = {0};
    int grama_teste[25] = {0};

    // printf("Sorteio de arquivos de Treinamento!\n");
    for(int i = 0; i < 25; ++i){
        asfalto_treino[i] = *(ordem_imagem_asfalto + i);
        grama_treino[i] = *(ordem_imagem_grama + i);
    }

    // printf("Sorteio de arquivos de Teste!\n");
    for(int i = 0; i < 50; ++i){
        asfalto_teste[i - 25] = *(ordem_imagem_asfalto + i);
        grama_teste[i - 25] = *(ordem_imagem_grama + i);
    }

    int arquivos_teste_grama = salva_arquivos(grama_teste, 0, 0);
    int arquivos_teste_asfalto = salva_arquivos(asfalto_teste, 0, 1);
    int arquivos_treino_grama = salva_arquivos(grama_treino, 1, 0);
    int arquivos_treino_asfalto = salva_arquivos(asfalto_treino, 1, 1);

    // Pega cada caminho salvo nos arquivos
    FILE *p_asphalt = fopen("treino_asphalt.txt", "r");
    FILE *p_grass = fopen("treino_grass.txt", "r");
    char path_asphalt[30];
    char path_grass[30];

    int *asphalt_image = (int*) malloc(1026*1026*sizeof(int));
    int *grass_image = (int*) malloc(1026*1026*sizeof(int));

    // Abre cada imagem
    for(int i = 0; i < 2; i++)
    {
        fgets(path_asphalt, 30, p_asphalt);
        fgets(path_grass, 30, p_grass);

        FILE *f_asphalt = fopen(path_asphalt, "r");
        FILE *f_grass = fopen(path_grass, "r");

    // Salva a imagem lida
        int j = 0;
        while(!feof(f_asphalt))
        {
            char c;
            fscanf(f_asphalt,"%d%c", (asphalt_image+j), &c);
            j++;
        }

        // Dados para normalizar vetor
        int menor_asphalt = 9999999;
        int menor_grass = 9999999;
        int maior_asphalt = -1;
        int maior_grass = -1;

        double *number_ilbp_asphalt = (double*) calloc(512,sizeof(double));
        double *number_ilbp_grass = (double*) calloc(512,sizeof(double));



        //COLOCAR RESTO DOS CÓDIGOS AQUI



        fclose(f_asphalt);
        fclose(f_grass);
    }

    fclose(p_asphalt);
    fclose(p_grass);

    return 0;
}
