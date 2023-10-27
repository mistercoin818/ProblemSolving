#include <stdio.h>
int N, maxi, s, h;
int main() {
    scanf("%d", &N);
    maxi = 2*N - 1;
    for(int i = 1; i <= N; ++i){
        s = 2*i - 1;
        h = (maxi - s) / 2;
        for(int j = 1; j <= h; ++j){
            printf(" ");
        }
        for(int j = 1; j <= s; ++j){
            printf("*");
        }
        printf("\n");
    }
    for(int i = N -1; i >= 1; --i){
        s = 2*i - 1;
        h = (maxi - s) / 2;
        for(int j = 1; j <= h; ++j){
            printf(" ");
        }
        for(int j = 1; j <= s; ++j){
            printf("*");
        }
        if(i > 1) printf("\n");
    }
}