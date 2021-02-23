#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int cont;

void sigint(int s){
    if(cont == 0)   cont++;
    else cont = 1;

    printf("Recebi 2\n", s);
}

void sigusr2(int s){
    if(cont == 1) cont++;
    else cont = 0;

    printf("Recebi 12\n", s);

}

void sigterm(int s){
    printf("Recebi 15\n", s);
    
    if(cont == 2){
        printf("Senha acionada\n");
        cont++;
    }
    else cont = 0;

}

void sigusr1(int s){
    if(cont == 3){
        cont++;
    }
    else cont = 0;

    printf("Recebi 10\n", s);
}

int main(){

    while(1){
        signal(SIGINT, sigint);
        signal(SIGUSR2, sigusr2);
        signal(SIGTERM, sigterm);
        signal(SIGUSR1, sigusr1);

        if(cont == 4){
            printf("Tchau\n");
            return 0;
        }
    }

    return 0;
}