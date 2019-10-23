#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();

void printa_menu();
contato *listaVazia();
contato *abrir_data_base(int *num_contatos);


//  Nome completo (string de até 100 caracteres);
//  Telefone celular (string no formato xxxxx-xxxx);
//  Endereço (string de até 100 caracteres);
//  CEP (inteiro sem sinal); e
//  Data de nascimento (string no formato dd/mm/aaaa).

struct Contato {
    char nome[101];
    char telefone[11];
    char endereco[101];
    unsigned int cep;
    char dtNascimento[11];
    struct Contato *prox;
    struct Contato *prev;

};typedef struct Contato contato;

void printa_menu(){

    printf("+--------------------------------------+\n");
    printf("| 1. Inserir novo contato              |\n");
    printf("| 2. Remover contato                   |\n");
    printf("| 3. Visualizar todos os contatos      |\n");
    printf("| 4. Sair                              |\n");
    printf("+--------------------------------------+\n");
}

contato *listaVazia(){
    return NULL;
}

// void criar_contato(contato *contatos, contato*novo){
    
// }

contato *abrir_data_base(int *num_contatos){
    FILE *f;
    char c;
    char trash[100];
    f = fopen("contatos.txt", "r");

    // conta linhas e contatos
    int line = 0;
    while(!feof(f)){
        c = fgetc(f);
        if(c == '\n'){
            line++;
        }
    } line++;
    *num_contatos = (line/6);

    contato *contatos = (contato*) malloc((line/6)*(sizeof(contato)));
    
    fseek (f, 0 , SEEK_SET );
    // Pega contatos
    for(int i = 0; i < (line/6); i++){
        contato *aux = (contato*) malloc(sizeof(contato));

        // Pega os dados de um contato
        fgets (aux->nome, sizeof trash, f);
        // printf("%s",aux->nome);
        
        fgets (aux->telefone, sizeof trash, f);
        // printf("%s",aux->telefone);

        fgets (aux->endereco, sizeof trash, f);
        // printf("%s",aux->endereco);

        fgets (trash, sizeof trash, f);
        aux->cep = (int) strtol(trash, (char **)NULL, 10);
        // printf("%s",trash);

        fgets (aux->dtNascimento, sizeof trash, f);
        // printf("%s",aux->dtNascimento);
        
        fgets (trash, sizeof trash, f);

        // Adiciona na lista de contatos
        contatos[i] = *aux;

        // resets
        free(aux);
    }
    fclose(f);
    return contatos;
}


int menu(){
    int d;

    printa_menu();
    scanf("%d",&d);

    switch (d){
        case 1:
            printf("Jose 1\n");
            contato *jose;
            jose = listaVazia();
            break;
        case 2:
            printf("Jose 2\n");
            break;
        case 3:
            printf("bugzao\n");
            contato * contatos;
            int num_contatos;
            contatos = abrir_data_base(&num_contatos);

            for(int i = 0; i < num_contatos; i++){
                printf("%s",contatos[i].nome);
            }
            
            free(contatos);
            break;
        default:
            break;
    }

    return d;
}


int main(){
    int a = 0;

    while(a != 4){
        a = menu();
    }

    return 0;
}
