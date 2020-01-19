#include<stdio.h>

#define MAXSIZE 100
#define MAX(a, b) (a>b)?a:b

int dp[MAXSIZE][MAXSIZE]; 
int tower[MAXSIZE][MAXSIZE];

// int max(int a, int b){

//     return a>b ? a : b;
// }

int main(void){
    int n;
    int i, j;
    //输入数塔的层数
    printf("please, enter the n:");
    scanf("%d", &n);
    //输入数塔的内容
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++)
            scanf("%d", &tower[i][j]);
    }
    //采用递推方式求解数塔的全局最优
    for(i = n; i >= 1; i--){
        if(i == n)
            for(j = 1; j <= i; j++){
                dp[i][j] = tower[i][j];
                }
        else
            for(j = 1; j <= i; j++)
                //转移方程
                dp[i][j] = MAX(dp[i+1][j], dp[i+1][j+1]) + tower[i][j];
    }

    printf("The result is %d", dp[1][1]);

    return 0;

        
}






