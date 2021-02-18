#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    pid_t  x = fork();

    if(x == 0) {
        printf("Processo filho: %d, e pai %d\n", getpid(), getppid());
    } else {
        printf("Processo pai, e filho: %d\n",x);
    }

    return 0;
}