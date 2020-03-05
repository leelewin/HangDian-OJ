#include<stdio.h>

#define MAXSIZE 50

int main(void){
    char ch;
    ch = getchar();
    putchar(ch);

}

int common_order(int m, int n, char x[], char z[], int dp[][MAXSIZE]){  //dp[i][j]表示x的前i个元素和z的前j个元素的最长公共子序列和
    int i, j;

    for(i = 0; i <= m; i++)
        dp[i][0] = 0;
    for(j = 0; j <= n; j++)
        dp[0][j] = 0;

    for(i = 1; i <=m; i++)
        for(j = 1; j <=n; j++){
            if(x[i] == z[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else if(dp[i-1][j] > dp[i][j-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1];
        }

    return dp[m][n];

}