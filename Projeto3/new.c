#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Contato{
    char *nome;
    char *telefone;
    char *endereco;
    unsigned int *cep;
    char *dtNascimento;
    struct Contato *prox;
    struct Contato *ant;
}contato;

contato *listaVazia();
contato *pegarDadosContato();
contato *geraElem(char *,char *,char *,char *, int);
contato *firstRead(contato *);
contato *adicionarContatoSort(contato *, contato *);
contato *removerContatoString(contato *, char *);
contato *menu(contato *, int *);

char *stringToLower(char *);

int contaLinha();

void printaMenu();
void printaString(contato *,char *);
void printaLista(contato *);
void atualizarArquivo(contato *);
void freeContato(contato *);
void freeLista(contato *);

int main(){
    int flag = 0;
    contato *lista = (contato*) malloc(sizeof(contato));
    lista = listaVazia();
    lista = firstRead(lista);

    while(flag == 0){
        printaMenu();
        lista = menu(lista,&flag);
    }

    return 0;
}

contato *listaVazia(){
    return NULL;
}

contato *adicionarContatoSort(contato *lista, contato *elem){
    char *str1 = (char *) malloc(101*(sizeof(char)));
    char *str2 = (char *) malloc(101*(sizeof(char)));

    if(lista == NULL){
        elem->prox = NULL;
        elem->ant = NULL;
        
        return elem;
    }

    else if(lista->prox == NULL){
        str1 = stringToLower(elem->nome);
        str2 = stringToLower(lista->nome);
        if(strcmp(str1,str2) < 0){
            elem->prox = lista;
            lista->ant = elem;

            lista->prox = NULL;
            elem->ant = NULL;

            return elem;
        }else{
            lista->prox = elem;
            elem->ant = lista;

            elem->prox = NULL;
            lista->ant = NULL;

            return lista;
        }
    }
    else{
        contato *it = (contato*) malloc(sizeof(contato));
        int i = 0;
        for(it = lista; it != NULL; it = it->prox){

            str1 = stringToLower(elem->nome);
            str2 = stringToLower(it->nome);
            if(strcmp(str1,str2) < 0){
                if(i == 0){
                    elem->prox = it;
                    elem->ant = NULL;
                    it->ant = elem;

                    return elem;
                }
                contato *aux;
                aux = it->ant;

                elem->prox = it;
                it->ant = elem;
                elem->ant = aux;
                aux->prox = elem;

                return lista;

            }

            else if(it->prox == NULL){
                it->prox = elem;
                elem->prox = NULL;
                elem->ant = it;

                return lista;
            }
            i++;
        }

        free(it);
        free(str1);
        free(str2);

        return lista;
    }
}

contato *geraElem(char *nome,char *telefone,char * endereco, char *dtNascimento, int cep){
    contato *elem = (contato*) malloc(sizeof(contato));
    elem->nome = (char*) malloc(101*(sizeof(char)));
    elem->telefone = (char*) malloc(11*(sizeof(char)));
    elem->endereco = (char*) malloc(101*(sizeof(char)));
    elem->cep = (unsigned int*) malloc(sizeof(unsigned int));
    elem->dtNascimento = (char*) malloc(11*(sizeof(char)));

    strcpy(elem->nome, nome);
    strcpy(elem->telefone, telefone);
    strcpy(elem->endereco, endereco);
    *elem->cep = cep;
    strcpy(elem->dtNascimento, dtNascimento);

    return elem;
}

int contaLinha(){
    FILE *f;
    int lines = 0;

    f = fopen("contatos.txt", "r");
    if(f != NULL){
        while(!feof(f)){
            char c = getc(f);
            if(c == '\n'){
                lines++;
            }
        }
    }   lines++;

    return lines;
}

contato *firstRead(contato *lista){
    FILE *f;
    int numContatos = (contaLinha()/6);
    
    f = fopen("contatos.txt", "r");
    if(f != NULL){
        for(int i = 0; i < numContatos; i++){
            contato *new;
            char *nome = (char *) malloc(101*(sizeof(char)));
            char *telefone = (char *) malloc(11*(sizeof(char)));
            char *endereco = (char *) malloc(101*(sizeof(char)));
            unsigned int cep;
            char *dtNascimento = (char *) malloc(101*(sizeof(char)));
            char *trash = (char *) malloc(101*(sizeof(char)));

            fgets(nome,"%[^\n]s",f);
            strtok(nome, "\n");

            fgets(telefone,"%[^\n]s",f);
            strtok(telefone, "\n");

            fgets(endereco,"%[^\n]s",f);
            strtok(endereco, "\n");

            fgets(trash,"%[^\n]s",f);
            strtok(trash, "\n");
            cep = (unsigned int) strtol(trash, (char **)NULL, 10);

            fgets(dtNascimento,"%[^\n]s",f);
            strtok(dtNascimento, "\n");

            fgets(trash,"%[^\n]s",f);
            strtok(trash, "\n");

            new = geraElem(nome,telefone,endereco,dtNascimento,cep);
            lista = adicionarContatoSort(lista,new);

            free(nome);
            free(telefone);
            free(endereco);
            free(dtNascimento);
            free(trash);
        }

    }else{
        f = fopen("contatos.txt", "w");
    }

    fclose(f);
    return lista;
}

contato *removerContatoString(contato *lista, char *elem){
    contato *it;
    char *str1 = (char *) malloc(101*(sizeof(char)));
    char *str2 = (char *) malloc(101*(sizeof(char)));

    int i = 0;

    for(it = lista; it != NULL; it = it->prox){
        str1 = stringToLower(it->nome);
        str2 = stringToLower(elem);
        if(strstr(str1,str2) != NULL){
            if(i == 0){
                
                lista = it->prox;
                free(lista->ant);
                lista->ant = NULL;
            }
            else if(it->prox == NULL){
                
                it = it->ant;
                free(it->prox);
                it->prox = NULL;
            }
            else{

                it->ant->prox = it->prox;
                it->prox->ant = it->ant;
                free(it);
            }
        }
        i++;
    }
    free(str1);
    free(str2);

    return lista;
}

void printaLista(contato *lista){
    printf("\n");
    contato *it;
    for(it = lista; it != NULL; it = it->prox){
        printf("(*) %s\n",it->nome);
        printf("\t%s\n",it->telefone);
        printf("\t%s\n",it->endereco);
        printf("\t%u\n",*it->cep);
        printf("\t%s\n\n",it->dtNascimento);

    }
}

void printaString(contato *lista, char *elem){
    contato *it;
    char *str1 = (char *) malloc(101*(sizeof(char)));
    char *str2 = (char *) malloc(101*(sizeof(char)));
    printf("\n");

    for(it = lista; it != NULL; it = it->prox){
        str1 = stringToLower(it->nome);
        str2 = stringToLower(elem);
        if(strstr(str1, str2) != NULL){
            printf("(*) %s\n",it->nome);
            printf("\t%s\n",it->telefone);
            printf("\t%s\n",it->endereco);
            printf("\t%u\n",*it->cep);
            printf("\t%s\n\n",it->dtNascimento);
        }
    }

    free(str1);
    free(str2);
}

contato *menu(contato *lista, int *flag){
    char D;
    scanf(" %c",&D);
    char *str = (char *) malloc(101*(sizeof(char)));
    switch (D){
        case '1':
            printf("Digite os dados do novo contato:\n\n");
            contato *new;
            new = pegarDadosContato();
            lista = adicionarContatoSort(lista, new);
            break;
        case '2':
            printf("Digite o nome do contato que deseja excluir: ");
            scanf("%s",str);
            lista = removerContatoString(lista,str);
            break;
        case '3':
            printf("Digite o nome do contato que deseja visualizar: ");
            scanf("%s",str);
            printaString(lista,str);
            break;
        case '4':
            printaLista(lista);
            break;
        case '5':
            printf("Saindo...\n");
            
            atualizarArquivo(lista);
            
            freeLista(lista);
            *flag = 1;
            break;
    }
    return lista;
}

contato *pegarDadosContato(){
    contato *new;
    char *nome = (char *) malloc(101*(sizeof(char)));
    char *telefone = (char *) malloc(11*(sizeof(char)));
    char *endereco = (char *) malloc(101*(sizeof(char)));
    unsigned int cep = 0;
    char *dtNascimento = (char *) malloc(101*(sizeof(char)));
    char *trash = (char *) malloc(101*(sizeof(char)));

    printf("Nome: ");
    scanf(" %[^\n]s",nome);
    strtok(nome, "\n");

    printf("Telefone: ");
    scanf(" %[^\n]s",telefone);
    strtok(telefone, "\n");

    printf("Endereço: ");
    scanf(" %[^\n]s",endereco);
    strtok(endereco, "\n");

    printf("cep: ");
    scanf(" %[^\n]s",trash);
    strtok(trash, "\n");
    cep = (unsigned int) strtol(trash, (char **)NULL, 10);

    printf("Data de nascimento (xx/xx/xx): ");
    scanf(" %[^\n]s",dtNascimento);
    strtok(dtNascimento, "\n");

    new = geraElem(nome,telefone,endereco,dtNascimento,cep);

    free(nome);
    free(telefone);
    free(endereco);
    free(dtNascimento);
    free(trash);

    return new;
}

void printaMenu(){
    printf("+-----------------------------------------------+\n");
    printf("|               Agenda de Contatos              |\n");
    printf("+-----------------------------------------------+\n");
    printf("| 1. Criar novo contato                         |\n");
    printf("| 2. Remover contatos a partir de um nome       |\n");
    printf("| 3. Visualizar contatos a partir de um nome    |\n");
    printf("| 4. Visualizar todos os contatos               |\n");
    printf("| 5. Sair                                       |\n");
    printf("+-----------------------------------------------+\n");
    
}

char *stringToLower(char *str){
    char *c = (char *) malloc(101*(sizeof(char)));

    for(unsigned int i = 0; i < strlen(str); i++){
        c[i] = tolower(str[i]);
    }

    return c;
}

void freeContato(contato *elem){
    free(elem->nome);
    free(elem->telefone);
    free(elem->endereco);
    free(elem->cep);
    free(elem->dtNascimento);

    free(elem);
}

void freeLista(contato *lista){
    contato *it;
    contato *aux;
    for(it=lista; it != NULL; it = aux){
        aux = it->prox;
        
        freeContato(it);
    }
    lista = NULL;
}

void atualizarArquivo(contato *lista){
    FILE *f;
    f = fopen("contatos.txt", "w");
    char *trash = (char *) malloc(101*(sizeof(char)));
    contato *it;

    for(it = lista; it != NULL; it = it->prox){
        fputs(it->nome,f);
        fputs("\n",f);

        fputs(it->telefone,f);
        fputs("\n",f);

        fputs(it->endereco,f);
        fputs("\n",f);

        sprintf(trash, "%u", *it->cep);
        fputs(trash,f);
        fputs("\n",f);

        fputs(it->dtNascimento,f);
        fputs("\n",f);

        fputs("$",f);
        if(it->prox != NULL){
            fputs("\n",f);
        }
    }

    fclose(f);
}
