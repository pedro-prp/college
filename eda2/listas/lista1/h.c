#include <string.h>
#include <stdio.h>

void reprova(int students){
    char nome[21], nome_r[21];
    int nota, nota_r;
    
    scanf(" %s %d", nome_r, &nota_r);
    
    for(int i = 1; i < students; i++){
        scanf(" %s %d", nome, &nota);
        
        if(nota < nota_r){
                strcpy(nome_r, nome);
                nota_r = nota;
        }else if(nota == nota_r){
            if(strcmp(nome, nome_r) > 0){
                strcpy(nome_r, nome);
                nota_r = nota;
            }
        }
    }

    printf("%s\n", nome_r);
}


int main(){
    int students, inst = 1;

    while(scanf("%d", &students) == 1){
        printf("Instancia %d\n", inst++);
        reprova(students);
        printf("\n");
    }
}