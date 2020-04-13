/*
dp[i][j]为前i个物品放入背包容量为j的背包的最大价值
状态转移方程：
dp[i][j] =   dp[i-1][j]            Wi > j
        =    max(dp[i-1][j], dp[i-1][j-Wi]+Vi) ,Wi < j
base case:
dp[0][j] = 0
dp[i][0] = 0

*/
#include<iostream>
using namespace std;
int dp[20][30];

int package(int value[], int weight[], int num, int max_w){
    // int dp[num][max_w];
    int i, j;
    for(i = 0; i <= num; i++)
        dp[i][0] = 0;
    for(j = 0; j <= max_w; j++)
        dp[0][j] = 0;

    for(i = 0; i <= num; i++)
        for(j = 0; j <= max_w; j++){
            if(weight[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
        }
    
    return dp[num][max_w];
}

int main(void){
    int w[5] = {2, 3, 6, 5, 4};
    int v[5] = {6, 3, 5, 4, 6};
    cout << package(v, w, 5, 10) << endl;


    return 0;
}





















