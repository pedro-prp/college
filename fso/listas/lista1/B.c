#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int valid = 1;
char name[11];

void printJudge(char *name, char *expc){
    if(strcmp(name , expc) == 0){
        printf("Certo\n");
    } else{
        printf("Erro\n");
    }
}

void sigusr1(int s){
    valid = scanf("%s", &name);

    if(valid == -1){
        return;
    }

   printJudge(name, "Igor3k");
}

void sigusr2(int s){
    valid = scanf("%s", &name);

    if(valid == -1){
        return;
    }

   printJudge(name, "Monark");

}

void sigint(int s){
    valid = scanf("%s", &name);

    if(valid == -1){
        return;
    }

   printJudge(name, "Con1");
}

void sigterm(int s){
    valid = scanf("%s", &name);

    if(valid == -1){
        return;
    }

   printJudge(name, "Con2");

}

void sigalarm(int s){
    valid = scanf("%s", &name);

    if(valid == -1){
        return;
    }

   printJudge(name, "Silencio");
}




int main(){

    while(1){
        signal(SIGINT, sigint);
        signal(SIGUSR2, sigusr2);
        signal(SIGTERM, sigterm);
        signal(SIGUSR1, sigusr1);
        signal(SIGALRM, sigalarm);

        if(valid == -1){
            return 0;
        }
    }

    return 0;
}