
#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "projeto2.h"

//parser sorteia arquivos para treino e teste
void parser()
{
    printf("\t Os arquivos foram preparados!\n\t Iniciando o processamento...\n\n");
    FILE *testeAG;
    FILE *treinoAG;
    FILE *asphalt;
    FILE *grass;
    asphalt = fopen("asphalt.txt", "r");
    grass = fopen("grass.txt", "r");
    testeAG = fopen("teste.txt", "w+");
    treinoAG = fopen("treino.txt", "w+");
    int z = 0;
    char tranf;
    while (z < 25)
    {
        tranf = fgetc(asphalt);
        fprintf(testeAG, "%c", tranf);
        if (tranf == '\n')
            z++;
    }
    z = 0;
    while (z < 25)
    {
        tranf = fgetc(grass);
        fprintf(testeAG, "%c", tranf);
        if (tranf == '\n')
            z++;
    }
    z = 25;
    while (z < 50)
    {
        tranf = fgetc(asphalt);
        fprintf(treinoAG, "%c", tranf);
        if (tranf == '\n')
            z++;
    }
    z = 25;
    while (z < 50)
    {
        tranf = fgetc(grass);
        fprintf(treinoAG, "%c", tranf);
        if (tranf == '\n')
            z++;
    }

    fclose(testeAG);
    fclose(treinoAG);
    fclose(asphalt);
    fclose(grass);
}
#endif