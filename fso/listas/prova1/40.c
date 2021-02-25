#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int cont = 0;

void sigusr1(int s){
    printf("SIGUSR1 eh para aproveitar mais um pouco\n");
}

void sigalarm(int s){
    if(cont < 2){
        printf("Ai que sono, quero dormir mais um pouco\n");
    } else {
        printf("Os incomodados que se mudem, tchau\n");
    }

    cont++;
}




int main(){

    signal(SIGUSR1, sigusr1);
    signal(SIGALRM, sigalarm);
    
    while(cont < 3){
        pause();
    }

    return 0;
}