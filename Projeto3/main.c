#include <stdio.h>

int menu();

void printa_menu();


//  Nome completo (string de até 100 caracteres);
//  Telefone celular (string no formato xxxxx-xxxx);
//  Endereço (string de até 100 caracteres);
//  CEP (inteiro sem sinal); e
//  Data de nascimento (string no formato dd/mm/aaaa).

struct Contato {
    char nome[100];
    char telefone[10];
    char endereco[100];
    unsigned int cep;
    char dtNascimento[10];
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

void abrir_data_base(){
    FILE *f;
    char c;
    f = fopen("contatos.txt", "r");

    while(!(feof(f))){
        // Pega 1 contato
        
    }
    printf("\n");
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
            abrir_data_base();
            break;
        default:
            break;
    }

    return d;
}


int main(){
    int a;

    while(a != 4){
        a = menu();
    }

    return 0;
}
