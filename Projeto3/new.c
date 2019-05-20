#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Contato{
    char *nome;
    char *telefone;
    char *endereco;
    unsigned int cep;
    char *dtNascimento;
    struct Contato *prox;
    struct Contato *ant;
}contato;

contato *listaVazia();
contato *geraElem(char *,char *,char *,char *, int);
contato *firstRead(contato *);
contato *adicionarContatoSort(contato *, contato *);
int contaLinha();
void printaLista(contato *);

int main(){

    printf("\nHello World\n\n");
    contato *lista = (contato*) malloc(sizeof(contato));
    
    lista = listaVazia();

    lista = firstRead(lista);
    
    printaLista(lista);


    printf("\nBye World\n\n");
    return 0;
}

contato *listaVazia(){
    return NULL;
}

contato *adicionarContatoSort(contato *lista, contato *elem){
    if(lista == NULL){
        elem->prox = NULL;
        elem->ant = NULL;
        
        return elem;
    }

    else if(lista->prox == NULL){
        if((int)toupper(elem->nome[0]) <= (int)toupper(lista->nome[0])){
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
            if((int)toupper(elem->nome[0]) <= (int)toupper(it->nome[0])){
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
        return lista;
    }
}

contato *geraElem(char *nome,char *telefone,char * endereco, char *dtNascimento, int cep){
    contato *elem = (contato*) malloc(sizeof(contato));
    elem->nome = (char*) malloc(101*(sizeof(char)));
    elem->telefone = (char*) malloc(11*(sizeof(char)));
    elem->endereco = (char*) malloc(101*(sizeof(char)));
    elem->dtNascimento = (char*) malloc(11*(sizeof(char)));

    strcpy(elem->nome, nome);
    strcpy(elem->telefone, telefone);
    strcpy(elem->endereco, endereco);
    elem->cep = cep;
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

    }

    fclose(f);
    return lista;
}

void printaLista(contato *lista){
    contato *it;
    for(it = lista; it != NULL; it = it->prox){
        printf("%s\n",it->nome);
        printf("%s\n",it->telefone);
        printf("%s\n",it->endereco);
        printf("%u\n",it->cep);
        printf("%s\n----\n",it->dtNascimento);

    }
}
