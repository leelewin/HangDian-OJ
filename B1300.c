/*
问题：有n级台阶，一个人每次上一级或者两级，问有多少种走完n级台阶的方法?
f(n)为走完n阶台阶的方法数
那要到达第n个台阶，要么从第n-1阶走一阶，要么从n-2阶走两步，
那到达第n阶的方法数f(n) = f(n-1)+f(n-2)
两种方法：
1.递归
2.动态规划

*/ 
//递归加记忆化搜索
#include<stdio.h>
#include<string.h>

#define MAX 30
int dp[MAX]  ;

int f(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(dp[n] != -1)
        return dp[n];
    else
    {
        dp[n] = f(n-1) + f(n-2);
        return dp[n];
    }
}

int main(void){
    int n;
    extern int dp[MAX];

    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    printf("%d", f(n));

    return 0;
}






/*
// 递推法
#include<stdio.h>

#define MAX 30

int dp[MAX] = {0};
int f( int n){
    for(int i = 1; i <= n; i++){
        if(i == 1) 
            dp[i] = 1;
        else if(i == 2) 
            dp[i] = 2;
        else
            dp[i] = dp[i-1] + dp[i-2];
    } 
    return dp[n];

}

int main(void){
    int n;

    scanf("%d", &n);
    printf("%d", f(n));

    return 0;
}
*/

/*

递归方法

#include<stdio.h>

int f(int n){
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else
        return f(n-1) + f(n-2);
    
} 

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
*/