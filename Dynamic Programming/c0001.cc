#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int MaxSize = 30;
int dp[MaxSize][MaxSize];

int NumTower(int a[][MaxSize], int n){
    if(n <= 0) return -1;
    memset(dp, 0, sizeof(dp));
    int i, j;
    for(i=1; i<=n; i++)  //base case
        dp[n][i] = a[n][i];
    for(i = n-1; i >= 1; i--)  //迭代求dp[1][1]
        for(j = 1; j <= i; j++)
            dp[i][j] = max(dp[i+1][j]+a[i][j], dp[i+1][j+1]+a[i][j]);//状态转移方程

    return dp[1][1];
}
int main(void){
    int n;
    int a[MaxSize][MaxSize];

    scanf("%d", &n);
    FILE *fd;
    fd = fopen("E:/OJ/Dynamic Programming/test.txt","r");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            fscanf(fd, "%d", &a[i][j]);
    cout << NumTower(a, n);

    return 0;





}
