#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>


#define MAX_L 5000
#define MAX_VALOR 1000
#define TREINO "treino.txt"
#define PREVISAO "teste.txt"

// Alunos: Rafaella Junqueira       16/0142628
//         Pedro Rodrigues Pereira  17/00626876
//         Joao Gabriel Antunes     17/0013651

struct inputMatrix
{
    float *linha;
} IMATRIX;

typedef struct inputMatrix InputMatrix;

struct targetMatrix
{
    float *linha;
} TMATRIX;

typedef struct targetMatrix TargetMatrix;

struct neuronio
{
    float *entradas;
    float *pesos;
    float *pesosAntigos; 
    float *momentum;     
    float saida;
} RNA;

typedef struct neuronio Neuronio;

int MAX_EPCS = 1000;
float MOMENTO = 0.7;
int tipoAtivacao = 0;
int NUMERO_DE_CAMADAS = 3;
float taxaDeAprendizado = 0.7; 
int neuroniosQuantidade = 0;
int *neuroniosPorCamada = NULL;
char saida[32];

float ativacao(float z)
{
    float resultado = 0.0;
    resultado = 1.0 / (1.0 + exp(-z));
    return resultado;
}

float derivadaAtivacao(float z)
{
    float resultado = 0.0;
    resultado = z * (1 - z); 
    return resultado;
}

Neuronio *criaRedeNeuronal(int *neuroniosPorCamada)
{
    int camadasQuantidade = 0;
    int numeroDeEntradas = 0;
    int neuronioAtual = 0;

    camadasQuantidade = NUMERO_DE_CAMADAS;

    int camadasQuantidade_contador = camadasQuantidade;

    while (camadasQuantidade_contador)
    {
        neuroniosQuantidade = neuroniosQuantidade + neuroniosPorCamada[camadasQuantidade_contador - 1];
        camadasQuantidade_contador--;
    }

    Neuronio *neuronios = malloc(neuroniosQuantidade * sizeof(Neuronio));

    for (int contadorCamadas = 0; contadorCamadas < camadasQuantidade; contadorCamadas++)
    {

        for (int contadorNeuroniosPorCamada = 0; contadorNeuroniosPorCamada < neuroniosPorCamada[contadorCamadas]; contadorNeuroniosPorCamada++)
        {

            if (contadorCamadas == 0)
            {
                neuronios[neuronioAtual].entradas = (float *)malloc(sizeof(float));
                neuronios[neuronioAtual].pesos = (float *)malloc(sizeof(float));
                neuronios[neuronioAtual].pesosAntigos = (float *)malloc(sizeof(float));
                neuronios[neuronioAtual].momentum = (float *)malloc(sizeof(float));

                neuronios[neuronioAtual].entradas[0] = 0.0; //vetor de entrada
                neuronios[neuronioAtual].pesos[0] = 1.0;
                neuronios[neuronioAtual].pesosAntigos[0] = neuronios[neuronioAtual].pesos[0];
                neuronios[neuronioAtual].saida = 0.0;
                neuronios[neuronioAtual].momentum[0] = 0.0;
            }
            else
            {
                numeroDeEntradas = neuroniosPorCamada[contadorCamadas - 1];
                neuronios[neuronioAtual].entradas = (float *)malloc(numeroDeEntradas * sizeof(float));
                neuronios[neuronioAtual].pesos = (float *)malloc(numeroDeEntradas * sizeof(float));
                neuronios[neuronioAtual].pesosAntigos = (float *)malloc(numeroDeEntradas * sizeof(float));
                neuronios[neuronioAtual].momentum = (float *)malloc(numeroDeEntradas * sizeof(float));

                for (int entrada = 0; entrada < numeroDeEntradas; entrada++)
                {
                    neuronios[neuronioAtual].entradas[entrada] = 0.0;
                    neuronios[neuronioAtual].pesos[entrada] = (rand() % 10 + 1) / 100.0;
                    neuronios[neuronioAtual].pesosAntigos[entrada] = neuronios[neuronioAtual].pesos[entrada];
                    neuronios[neuronioAtual].momentum[entrada] = 0.0;
                }

                neuronios[neuronioAtual].saida = 0.0;
            }
            if (neuronioAtual < neuroniosQuantidade)
                neuronioAtual++;
        }
    }
    return neuronios;
}

void ajustaPesosAntigos(Neuronio *neuronios, int *neuroniosPorCamada)
{
    int numeroDeCamadas = NUMERO_DE_CAMADAS; 
    int numeroDeNeuronios = 0;
    int numeroDePesos = 0;

    for (int camada = 0; camada < numeroDeCamadas; camada++)
    {
        numeroDeNeuronios += neuroniosPorCamada[camada];
    }

    for (int neuronio = 0; neuronio < numeroDeNeuronios; neuronio++)
    {
        numeroDePesos = sizeof(neuronios[neuronio].pesos) / sizeof(neuronios[neuronio].pesos[0]);
        for (int pesoContador = 0; pesoContador < numeroDePesos; pesoContador++)
        {
            neuronios[neuronio].pesosAntigos[pesoContador] = neuronios[neuronio].pesos[pesoContador];
        }
    }
}

float erroQuadratico(float saida, float alvo)
{
    return 0.5 * pow((alvo - saida), 2);
}

float derivadaDoErroQuadratico(float saida, float alvo)
{
    float resultado = saida - alvo;
    return resultado;
}

int getUltimoNeuronioDaCamada(int camada, int *neuroniosPorCamada)
{
    int indexNeuronio = 0;

    for (int camadasContador = 0; camadasContador <= camada; camadasContador++)
    {
        indexNeuronio += neuroniosPorCamada[camadasContador];
    }

    return indexNeuronio - 1;
}

int getPrimeiroNeuronioDaCamada(int camada, int *neuroniosPorCamada)
{

    int indexNeuronio = 0;

    for (int camadasContador = 0; camadasContador < camada; camadasContador++)
    {
        indexNeuronio += neuroniosPorCamada[camadasContador];
    }

    return indexNeuronio;
}

int getTotalDeNeuroniosNaRede(int *neuroniosPorCamada)
{

    int totalCamadas = NUMERO_DE_CAMADAS;
    int resultado = 0;

    for (int contador = 0; contador < totalCamadas; contador++)
    {
        resultado += neuroniosPorCamada[contador];
    }
    return resultado;
}

float calculaDelta(Neuronio *neuronios, int neuronioAtual, int *neuroniosPorCamada, int camadaAtual, float erro, int neuronioAnterior)
{
    float resultado = 0.0;
    float delta = 0.0;
    int totalCamadas = NUMERO_DE_CAMADAS;
    int posicaoNeuronioCamada = 0;
    int indexNeuronio = 0;
    int numeroDeNeuroniosCamadaSeguinte = 0;
    int quantidadeDeParcelasNaSomaDoDeltaAtual = 0;
    int indexNeuroniosCamadaSeguinte = 0;
    int contadorDeslocadoPeloBias = 0;

    numeroDeNeuroniosCamadaSeguinte = neuroniosPorCamada[camadaAtual + 1];
    quantidadeDeParcelasNaSomaDoDeltaAtual = numeroDeNeuroniosCamadaSeguinte;

    if (camadaAtual < (totalCamadas - 1))
    {
        //camada escondida
        if (quantidadeDeParcelasNaSomaDoDeltaAtual == 1)
        {

            indexNeuroniosCamadaSeguinte = getTotalDeNeuroniosNaRede(neuroniosPorCamada) - neuroniosPorCamada[camadaAtual + 1];
            resultado += neuronios[indexNeuroniosCamadaSeguinte].pesosAntigos[neuronioAtual - 2] * calculaDelta(neuronios, indexNeuroniosCamadaSeguinte, neuroniosPorCamada, camadaAtual + 1, erro, neuronioAtual);
        }
        else
        {
            for (int contador = 0; contador < quantidadeDeParcelasNaSomaDoDeltaAtual; contador++)
            {
                indexNeuroniosCamadaSeguinte = getTotalDeNeuroniosNaRede(neuroniosPorCamada) - neuroniosPorCamada[camadaAtual + 1] + contador;
                contadorDeslocadoPeloBias = contador + 0;

                resultado += neuronios[indexNeuroniosCamadaSeguinte].pesosAntigos[contadorDeslocadoPeloBias] * calculaDelta(neuronios, indexNeuroniosCamadaSeguinte, neuroniosPorCamada, camadaAtual + 1, erro, neuronioAtual);
            }
        }
    }
    else
    {
        resultado = erro;
    }

    return resultado;
}

float soma(int camadaAnterior, int *neuroniosPorCamada, int neuronio, Neuronio *neuronios)
{

    float resultado = 0.0;

    int contadorNeuronioCamadaAnterior = 0;
    int camadaAnteriorContador = camadaAnterior;
    int totalNeuroniosCamadasAnteriores = 0;
    int primeiroNeuronioCamadaAnterior = 0;
    float saidaAnterior = 0.0;
    float pesoAtual = 0.0;
    float produtoParcial = 0.0;
    float entradaAtual = 0.0;
    float saidaDoNeuronioAtual = 0.0;


    primeiroNeuronioCamadaAnterior = getPrimeiroNeuronioDaCamada(camadaAnterior, neuroniosPorCamada);

    int linhaContador = 0;

    for (int contadorNeuroniosPorCamada = primeiroNeuronioCamadaAnterior; contadorNeuroniosPorCamada < (neuroniosPorCamada[camadaAnterior] + primeiroNeuronioCamadaAnterior); contadorNeuroniosPorCamada++)
    {
        saidaAnterior = neuronios[contadorNeuroniosPorCamada].saida;
        pesoAtual = neuronios[neuronio].pesos[linhaContador];
        produtoParcial = saidaAnterior * pesoAtual;
        resultado = resultado + produtoParcial;

        neuronios[neuronio].entradas[linhaContador] = (float)produtoParcial;
        entradaAtual = neuronios[neuronio].entradas[linhaContador];

        linhaContador++;
    }

    return resultado;
}

int backpropagation(float saida, float erro, int *neuroniosPorCamada, Neuronio *neuronios)
{

    int totalCamadas = NUMERO_DE_CAMADAS;
    int camadaAtual = 0;
    int indexNeuronio = 0;
    int ultimoNeuronio = 0;
    int inputsNeuronio = 0;
    float saidaDoNeuronioAnterior = 0.0;
    float saidaDoNeuronioAtual = 0.0;
    float novoPeso = 0.0;
    float pesoAntigo = 0.0;
    float delta = 0.0;
    float deltaPeso = 0.0;
    float derivada = 0.0;
    float derivadaSaida = 0.0;
    float momentum = 0.0;
    float taxaMomentum = 0.0;

    while (totalCamadas > 0)
    {
        camadaAtual = totalCamadas;

        indexNeuronio = getPrimeiroNeuronioDaCamada(camadaAtual, neuroniosPorCamada);
        ultimoNeuronio = getUltimoNeuronioDaCamada(camadaAtual, neuroniosPorCamada);

        for (int neuronioContador = indexNeuronio; neuronioContador <= ultimoNeuronio; neuronioContador++)
        {
        
            inputsNeuronio = neuroniosPorCamada[camadaAtual - 1];
            
            for (int pesosContador = 0; pesosContador < inputsNeuronio; pesosContador++)
            {
                saidaDoNeuronioAnterior = neuronios[neuronioContador].entradas[pesosContador] / neuronios[neuronioContador].pesos[pesosContador];
                saidaDoNeuronioAtual = neuronios[neuronioContador].saida;
                delta = calculaDelta(neuronios, neuronioContador, neuroniosPorCamada, camadaAtual, erro, neuronioContador);
                derivada = derivadaAtivacao(saidaDoNeuronioAtual);
                derivadaSaida = derivadaAtivacao(saida);

                pesoAntigo = neuronios[neuronioContador].pesos[pesosContador];

                if (derivada != derivadaSaida)
                {
                    taxaMomentum = MOMENTO;
                    deltaPeso = delta * derivada * derivadaSaida * saidaDoNeuronioAnterior;

                    if (neuronios[neuronioContador].momentum[pesosContador] == 0.0 || MOMENTO == 0)
                    {
                        novoPeso = pesoAntigo - taxaDeAprendizado * deltaPeso;
                    }
                    else
                    {
                        momentum = neuronios[neuronioContador].momentum[pesosContador];
                        novoPeso = pesoAntigo - taxaDeAprendizado * (deltaPeso - (taxaMomentum * momentum));
                    }

                    neuronios[neuronioContador].momentum[pesosContador] = deltaPeso;
                }
                else
                {

                    taxaMomentum = taxaDeAprendizado + ((rand() % 10 + 1) / 100.0);
                    deltaPeso = delta * derivada * saidaDoNeuronioAnterior;

                    if (neuronios[neuronioContador].momentum[pesosContador] == 0.0)
                    {
                        novoPeso = pesoAntigo - taxaDeAprendizado * deltaPeso;
                    }
                    else
                    {
                        momentum = neuronios[neuronioContador].momentum[pesosContador];
                        novoPeso = pesoAntigo - taxaDeAprendizado * (deltaPeso - (taxaMomentum * momentum));
                    }

                    neuronios[neuronioContador].momentum[pesosContador] = deltaPeso;
                }
                neuronios[neuronioContador].pesosAntigos[pesosContador] = neuronios[neuronioContador].pesos[pesosContador];
                neuronios[neuronioContador].pesos[pesosContador] = novoPeso;

                //}
            }
        }
        totalCamadas--;
    }

    return 1;
}

int treinaRedeNeuronal(Neuronio *neuronios, int *neuroniosPorCamada, InputMatrix *inputs, TargetMatrix *targets)
{
    float erro = 0.0;
    float somaTotal = 0.0;
    float saida = 0.0;
    int entradaContador = 0;

    int entradaCicloContador = 0;
    int targetContador = 0;
    int camadaContador = 0;
    int entrada = 0;
    int target = 0;
    int camadasQuantidade = NUMERO_DE_CAMADAS;
    int entradasQuantidade = -1;
    int saidasQuantidade = 0;
    int neuronioContador = 0;
    int neuronioPorCamadaContador = 0;
    int camadaAtual = 0;
    int epocaContador = 0;

    InputMatrix *entradas = inputs;
    TargetMatrix *alvos = targets;

    saidasQuantidade = neuroniosPorCamada[camadasQuantidade - 1];

    for (epocaContador = 0; epocaContador < MAX_EPCS; epocaContador++)
    {

        entradasQuantidade = 0;
        entradaContador = 0;
        neuronioContador = 0;

        while (entradas[entradaContador].linha)
        {
            entradaContador++;
            entradasQuantidade++;
        }

        while (entradasQuantidade > 0)
        {

            entradasQuantidade--;
            camadaAtual = 0;
            neuronioContador = 0;

            while (camadaAtual < camadasQuantidade)
            {
                if (camadaAtual == 0)
                {
                    neuronioPorCamadaContador = 0;

                    while (neuronioPorCamadaContador < neuroniosPorCamada[camadaAtual])
                    {

                        entradaContador = neuronioPorCamadaContador;

                        while (entradaContador < neuroniosPorCamada[camadaAtual])
                        {

                            neuronios[neuronioPorCamadaContador].saida = entradas[entradasQuantidade].linha[entradaContador];
                            neuronioContador++;
                            neuronioPorCamadaContador++;
                            entradaContador++;
                        }
                    }
                }
                else
                {
                    entradaContador = 0;

                    while (entradaContador < neuroniosPorCamada[camadaAtual])
                    {
                        somaTotal = soma(camadaAtual - 1, neuroniosPorCamada, neuronioContador, neuronios);
                        saida = ativacao(somaTotal);

                        neuronios[neuronioContador].saida = saida;
                        neuronioContador++;
                        entradaContador++;
                    }
                }
                camadaAtual++;
            }

            erro = derivadaDoErroQuadratico(neuronios[neuronioContador - 1].saida, targets[0].linha[entradasQuantidade]);

            if (!backpropagation(neuronios[neuronioContador - 1].saida, erro, neuroniosPorCamada, neuronios))
            {
                exit(1);
            };
            ajustaPesosAntigos(neuronios, neuroniosPorCamada);
        }
    }

    return 1;
}

char *substring(char *linha, int inicio, int fim)
{
    char *resultado = (char *)malloc(strlen(linha) * sizeof(char));

    for (int contador = inicio; contador < fim; contador++)
    {
        resultado[contador - inicio] = linha[contador];
    }

    return resultado;
}

float getAlvos(FILE *arquivo, int linhaArquivo)
{
    float resultado = 0.0;

    int linhaContador = 0;
    int entradaContador = 0;
    int valorContador = 0;
    char caractere;
    char linha[MAX_L];
    char valor[MAX_VALOR];

    memset(linha, '\0', MAX_L);
    memset(valor, '\0', MAX_VALOR);

    rewind(arquivo);
    while (!feof(arquivo))
    {
        fgets(linha, MAX_L, arquivo);
        if (linhaContador == linhaArquivo)
        {
            valorContador = 0;
            for (int contador = 0; contador < strlen(linha); contador++)
            {
                if (linha[contador] == ':')
                {
                    resultado = atof(substring(linha, (contador + 1), strlen(linha)));
                }
            }
        }
        memset(linha, '\0', MAX_L);
        linhaContador++;
    }
    return resultado;
}

float getEntrada(FILE *arquivo, int linhaArquivo, int entradaArquivo)
{
    float resultado = 0.0;

    int linhaContador = 0;
    int entradaContador = 0;
    int valorContador = 0;
    char caractere;
    char linha[MAX_L];
    char valor[MAX_VALOR];

    memset(linha, '\0', MAX_L);
    memset(valor, '\0', MAX_VALOR);

    rewind(arquivo);
    while (!feof(arquivo))
    {
        fgets(linha, MAX_L, arquivo);
        if (linhaContador == linhaArquivo)
        {
            valorContador = 0;
            for (int contador = 0; contador < strlen(linha); contador++)
            {
                if (linha[contador] != ';')
                {
                    valor[valorContador] = linha[contador];
                    valorContador++;
                }
                else
                {
                    if (entradaContador == entradaArquivo)
                    {
                        resultado = atof(valor);
                        //break;
                        return resultado;
                    }
                    valorContador = 0;
                    memset(valor, '\0', MAX_VALOR);
                    entradaContador++;
                }
            }
        }
        memset(linha, '\0', MAX_L);
        linhaContador++;
    }
    return resultado;
}

void prever(Neuronio *neuronios, int *neuroniosPorCamada, InputMatrix *previsao, float *previsaoResultados)
{
    int totalCamadas = NUMERO_DE_CAMADAS;
    int totalNeuroniosNaCamada = 0;
    int totalNeuronios = 0;
    int neuronioAtual = 0;
    int neuronioContador = 0;
    int contadorNeuronioAnterior = 0;
    int primeiroNeuronioDaCamada = 0;
    float soma = 0.0;
    int totalEntradas = neuroniosPorCamada[0];
    int totalLinhasDeEntrada = 0;
    int previsaoResultadoContador = 0;


    while (previsao[totalLinhasDeEntrada].linha)
    {
        totalLinhasDeEntrada++;
    }

    for (int contadorCamadas = 0; contadorCamadas < totalCamadas; contadorCamadas++)
    {
        totalNeuronios += neuroniosPorCamada[contadorCamadas];
    }

    for (int contadorLinhasEntrada = 0; contadorLinhasEntrada < totalLinhasDeEntrada; contadorLinhasEntrada++)
    {
        for (int contadorEntradas = 0; contadorEntradas < totalEntradas; contadorEntradas++)
        {
            neuronios[contadorEntradas].saida = previsao[contadorLinhasEntrada].linha[contadorEntradas];
            
        }

        for (int contadorCamadas = 1; contadorCamadas < totalCamadas; contadorCamadas++)
        {
            totalNeuroniosNaCamada = neuroniosPorCamada[contadorCamadas];
            primeiroNeuronioDaCamada = getPrimeiroNeuronioDaCamada(contadorCamadas, neuroniosPorCamada);
            for (neuronioContador = primeiroNeuronioDaCamada; neuronioContador < (totalNeuroniosNaCamada + primeiroNeuronioDaCamada); neuronioContador++)
            {
                
                soma = 0.0;
                totalEntradas = neuroniosPorCamada[contadorCamadas - 1];
                contadorNeuronioAnterior = getPrimeiroNeuronioDaCamada(contadorCamadas - 1, neuroniosPorCamada);

                for (int contadorEntradas = 0; contadorEntradas < totalEntradas; contadorEntradas++)
                {
                    neuronios[neuronioContador].entradas[contadorEntradas] = (float)neuronios[neuronioContador].pesos[contadorEntradas] * neuronios[contadorNeuronioAnterior].saida;

                    soma += neuronios[neuronioContador].entradas[contadorEntradas];
            
                    contadorNeuronioAnterior++;
                }
                neuronios[neuronioContador].saida = ativacao(soma);
            }
        }
        
        previsaoResultados[previsaoResultadoContador] = neuronios[neuronioContador - 1].saida;
        previsaoResultadoContador++;
    }
}

void imprimeResultadoPrevisao(Neuronio *neuronios, InputMatrix *previsao, FILE *testeFile, float *previsaoResultados)
{
    int quantidadeDeLinhasDeEntrada = 50;
    int qtdAcertos = 0, qtdFalsoAcerto = 0, qtdFalsaRejeicao = 0;
    double acertos, falsosAceitos, falsosRejeicao;

    for (int contadorLinha = 0; contadorLinha < quantidadeDeLinhasDeEntrada; contadorLinha++)
    {
        if (contadorLinha <= 25)
        {

            if (previsaoResultados[contadorLinha] <= 0.5)
            {
                qtdAcertos++;
            }
            else
            {
                qtdFalsaRejeicao++;
            }
        }
        else
        { 

            if (previsaoResultados[contadorLinha] > 0.5)
            {
                qtdAcertos++;
            }
            else
            {
                qtdFalsoAcerto++;
            }

        } 
    }

    acertos = (qtdAcertos * 100) / 50;
    falsosAceitos = (qtdFalsoAcerto * 100) / 25;
    falsosRejeicao = (qtdFalsaRejeicao * 100) / 25;
    printf("\t Métricas:\n");                          // GRASS 1, ASPHALT 0
    printf("\t TAXA DE ACERTOS:         %.0lf%%\n", acertos);       
    printf("\t TAXA DE FALSA ACEITAÇÃO: %.0lf%%\n", falsosAceitos);
    printf("\t TAXA DE FALSA REJEIÇÃO:  %.0lf%%\n\n", falsosRejeicao); 
}

int main(int argc, char *argv[])
{

    parser();
    double start_treino, end_treino, total_treino;
    start_treino = clock();

    memset(saida, '\0', 32);

    FILE *treinoFile = NULL;
    FILE *testeFile = NULL;

    testeFile = fopen(PREVISAO, "r");
    treinoFile = fopen(TREINO, "r");

    if (treinoFile == NULL)
    {
        printf("\nArquivos .txt com erro\n");
        exit(1);
    }

    int quantidadeDeLinhasDeEntrada = 50;
    int quantidadeEntradasPorLinha = 538;

    int quantidadeAlvosPorLinha = quantidadeEntradasPorLinha;

    InputMatrix *inputs = malloc(quantidadeDeLinhasDeEntrada * sizeof(InputMatrix));
    for (int contadorLinha = 0; contadorLinha < quantidadeDeLinhasDeEntrada; contadorLinha++)
    {
        inputs[contadorLinha].linha = (float *)malloc(quantidadeEntradasPorLinha * sizeof(float));
        for (int contadorEntrada = 0; contadorEntrada < quantidadeEntradasPorLinha; contadorEntrada++)
        {
            inputs[contadorLinha].linha[contadorEntrada] = getEntrada(treinoFile, contadorLinha, contadorEntrada);
        }
    }

    TargetMatrix *targets = malloc(sizeof(TargetMatrix));
    targets[0].linha = (float *)malloc(quantidadeDeLinhasDeEntrada * sizeof(float));

    for (int contadorLinha = 0; contadorLinha < quantidadeDeLinhasDeEntrada; contadorLinha++)
    {
        targets[0].linha[contadorLinha] = getAlvos(treinoFile, contadorLinha);
    }

    neuroniosPorCamada = malloc(NUMERO_DE_CAMADAS * sizeof(int));
    neuroniosPorCamada[0] = 536;
    neuroniosPorCamada[1] = atoi(argv[1]);
    //printf("\t Digite o numero de neuronios da camada oculta desejado: ");
    //scanf("%d", &neuroniosPorCamada[1]);
    neuroniosPorCamada[2] = 1;

    printf("\t Rede Neural Feed-Foward com 3 Camadas:\n\n");
    printf("\t Camada de entrada com 536 neuronios.\n");
    printf("\t Camada Oculta com %d neuronios.\n", neuroniosPorCamada[1]);
    printf("\t Camada de saida com 1 neuronio.\n\n");
    printf("\t Criando Rede Neural...\n");
    Neuronio *RNA = criaRedeNeuronal(neuroniosPorCamada);
    printf("\t Rede neural criada!\n\n");
    printf("\t Comecando treinamento usando o BackPropagation...\n");
    treinaRedeNeuronal(RNA, neuroniosPorCamada, inputs, targets);
    end_treino = clock();
    total_treino = (double)(end_treino - start_treino) / CLOCKS_PER_SEC;
    printf("\t Rede treinada em %.2f segundos.\n\n", total_treino);
    printf("\t Comecando os testes da rede neural...\n");

    if (testeFile != NULL)
    {
        quantidadeDeLinhasDeEntrada = 50;
        quantidadeEntradasPorLinha = 538;

        InputMatrix *previsao = malloc(quantidadeDeLinhasDeEntrada * sizeof(InputMatrix));
        float *previsaoResultados = malloc(quantidadeDeLinhasDeEntrada * sizeof(InputMatrix));

        for (int contadorLinha = 0; contadorLinha < quantidadeDeLinhasDeEntrada; contadorLinha++)
        {
            previsao[contadorLinha].linha = (float *)malloc(quantidadeEntradasPorLinha * sizeof(float));
            for (int contadorEntrada = 0; contadorEntrada < quantidadeEntradasPorLinha; contadorEntrada++)
            {
                previsao[contadorLinha].linha[contadorEntrada] = getEntrada(testeFile, contadorLinha, contadorEntrada);
            }
        }
        prever(RNA, neuroniosPorCamada, previsao, previsaoResultados);
        imprimeResultadoPrevisao(RNA,previsao,testeFile,previsaoResultados);
        fclose(testeFile);
    }

    fclose(treinoFile);
    //end_t = clock();
    
}
