#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAXSIZE 100
int dp[MAXSIZE][MAXSIZE]; 
int tower[MAXSIZE][MAXSIZE];

// void number_tower(int *tower, int n){
//     int i;
//     int j;

//     for(i = n; i <= 1; i--){
//         if(i == n)
//             for(j = 1; j <= i; j++)
//                 dp[i][j] = tower[i][j];
//         else
//             for(j = 1; j <= i; j++)
//                 dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + tower[i][j];
//     }

// }
int max(int a, int b){

    return a>b ? a : b;
}

int main(void){
    int n;
    int i, j;

    printf("please, enter the n:");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++)
            scanf("%d", &tower[i][j]);
    }
    // for(i=1; i<=n; i++){
    //     for(j=1; j<=i; j++)
    //         printf("it %d\n", tower[i][j]);
    // }

    // printf("it is a %d\n", tower[1][1]);

    for(i = n; i >= 1; i--){
        if(i == n)
            for(j = 1; j <= i; j++){
                dp[i][j] = tower[i][j];
                // printf(" motho %d", dp[i][j]);
                }
        else
            for(j = 1; j <= i; j++)
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + tower[i][j];
    }

    printf("The result is %d", dp[1][1]);

    return 0;

        
}






