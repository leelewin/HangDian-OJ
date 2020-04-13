/*
最大连续子序列和
dp[i]以i结尾的最大连续子序列和
状态转移函数：
dp[i] = dp[i-1] + a[i]  dp[i-1]>=0
      = a[i]             dp[i-1]<0
最后遍历dp数组找到最大的即可

*/
#include<iostream>
using namespace std;
const int MaxSize = 50;
int dp[MaxSize];

int MaxSub(int a[], int n){
    if(n <= 0) return -1;
    if(n == 1){
        if(a[0] <= 0) return 0;
        else
            return a[0];
    }
    dp[0] = a[0];   //base case
    for(int i = 1; i < n; i++){   //迭代生成dp数组
        if(dp[i-1] >= 0)
            dp[i] = dp[i-1] + a[i];
        else
            dp[i] = a[i];
    }
    int max = 0;
    for(int j = 0; j < n; j++){  //遍历dp数组找到最大的值
        if(dp[j] > max)
            max = dp[j];
    }
    return max;

}

int main(void){
    int a[1] = { -3};
    cout << MaxSub(a, 1) << endl;



    return 0;
}
