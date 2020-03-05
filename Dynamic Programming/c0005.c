#include<stdio.h>
#include<string.h>

#define MAXSIZE 50
#define MAX(a, b) (((a) > (b))?(a):(b))

int dp[MAXSIZE][MAXSIZE];

int packet(int n, int C, int w[], int v[]){
    int i;
    int j;

    for(i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(i = 0; i <= C; i++)
        dp[0][i] = 0;
    
    for(i = 1; i <= n; i++)
        for(j = 1; j <= C; j++){
            if(j < w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = MAX(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
            
        }
    return dp[n][C];

}

int main(void){
    int w[MAXSIZE];
    int v[MAXSIZE];
    int i;
    int n;
    int max_value = 0;
    int c;

    scanf("%d", &n);
    scanf("%d", &c);
    for(i = 1; i <=n; i++)
        scanf("%d", &w[i]);
    for(i = 1; i <=n; i++)
        scanf("%d", &v[i]);
    memset(dp, 0, sizeof(dp));
    max_value = packet(n, c, w, v);
    printf("max_value = %d", max_value);

    return 0;
}