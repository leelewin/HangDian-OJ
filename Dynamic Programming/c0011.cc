#include<iostream>
#include<climits>
using namespace std;
//多段图以邻接矩阵存储
const int MAXSIZE = 20;
int dp[MAXSIZE];  //dp[i]表示顶点i到终点的最短路径长度
                  //全部被初始化为最大值


int MultiG(int g[][MAXSIZE], int n){
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--){
        int min = INT_MAX;
        for(int j = i; j <= n; j++){
            if(g[i][j] != 0 && dp[j]+g[i][j] < min)
                min = (dp[j] + g[i][j]);
        }
        dp[i] = min;
    }
    return dp[0];

}

int main(void){

    return 0;
}