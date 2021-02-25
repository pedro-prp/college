#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int cont = 0;

void handle(int s){
    pid_t x;
    cont++;

    if(cont == 1){
        x = fork();
        if(x == 0){
            exit(0);
        }
    } else if(cont == 2){
        wait(NULL);
    }

}


int main(){

    signal(SIGUSR1, handle);
    signal(SIGUSR2, handle);
    
    while(cont < 3){
        pause();
    }

    return 0;
}