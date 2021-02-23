#include <stdio.h>

int main(){

    int better[2];
    int r, score, code;
    int days = 0;

    while(scanf("%d", &r) == 1){
        days++;

        scanf("%d %d", &code, &score);

        better[0] = code;
        better[1] = score;

        for(int i = 1; i < r; i++){
            scanf("%d %d", &code, &score);

            if(score > better[1]){
                better[0] = code;
                better[1] = score;
            } else if(score == better[1]){
                if(code < better[0])
                    better[0] = code;
            }
        }

        printf("Dia %d\n", days);
        printf("%d\n\n", better[0]);
    }


    return 0;
}