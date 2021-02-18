#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    pid_t x = fork();

    sleep(10);
    if(x == 0){
        printf("Processo filho morreu, zumbi instaurado\n");
        exit(0);
    } else{
        sleep(30);
        printf("Processo pai morreu, zumbi morre também\n");
    }

    return 0;
}