
//给定两个序列 X和 Y, 当另一个序列 Z既是 X 的子序列又是 Y 的子序列时, 称 Z是序列 X和 Y 的公共子序列。
//例如, 序列 X= ( a, b, c, b, d, b) , Y= ( a, c, b, b, a, b, d, b, b) ,
//序列( a, c, b)是序列 X和 Y的一个长度为 3 的公共子序列,序列( a, b, b, d, b)是 
//序列 X和 Y 的一个长度为 5 的公共子序列。最长公共子序列问题就是在序列 X和 Y 的 公共子序列
//中查找长度最长的公共子序列。
#include<stdio.h>

#define MAXSIZE 50
int dp[MAXSIZE][MAXSIZE];


int common_order(int m, int n, char x[], char z[]){  //dp[i][j]表示x的前i个元素和z的前j个元素的最长公共子序列和
    int i, j;

    for(i = 0; i <= m; i++)
        dp[i][0] = 0;
    for(j = 0; j <= n; j++)
        dp[0][j] = 0;

    for(i = 1; i <=m; i++)
        for(j = 1; j <=n; j++){
            if(x[i-1] == z[j-1])        //改成i-1
                dp[i][j] = dp[i-1][j-1] + 1;
            else if(dp[i-1][j] > dp[i][j-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1];
        }

    return dp[m][n];

}
int main(void){ 
    char *a = "b";
    char *b = "a";
    printf("%d", common_order(1, 2, a, b));

}