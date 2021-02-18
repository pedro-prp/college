#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>


void filhoNaoMorre(int s){
    printf("Não vou morrer\n");
}


int main(){

    pid_t x = fork();

    sleep(10);

    if(x == 0){
        signal(SIGTERM, filhoNaoMorre);
        printf("Processo filho morreu, zumbi instaurado\n");
        while(1) {
            sleep(2);
            printf("Zumbi talk\n");
        }
        
        return 3;
    } else{
        sleep(30);
        printf("Processo pai morreu\n");
        int s;
        sleep(30);
    }

    return 0;
}