#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    pid_t x = fork();

    sleep(10);

    if(x == 0){
        printf("Processo filho morreu, zumbi instaurado\n");
        while(1) {
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