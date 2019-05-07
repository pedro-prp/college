#include <stdio.h>

int menu();

void printa_menu();

void printa_menu(){

    printf("+--------------------------------------+\n");
    printf("| 1. Inserir novo contato              |\n");
    printf("| 2. Remover contato                   |\n");
    printf("| 3. Visualizar todos os contatos      |\n");
    printf("| 4. Sair                              |\n");
    printf("+--------------------------------------+\n");
}



int menu(){
    int d;

    printa_menu();
    scanf("%d",&d);

    switch (d){
        case 1:
            printf("Jose 1\n");
            break;
        case 2:
            printf("Jose 2\n");
            break;
        case 3:
            printf("Jose 3\n");
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