/*
dp[i]是以第i个元素结尾的单调递增序列的长度   
注：单调递增序列要以第i个元素结尾，如果没有那就从当前位置开始计数

dp[i] = dp[j]+1 满足：a[j]<a[i] && 最大的dp[](j < i)

dp[i] = max(dp[j])+1 j<i && a[j]<a[i]

base case:
dp[1] = 1;   or 所有的都是1
*/
#include<iostream>
using namespace std;

int IncreaseeSeq(int seq[], int num){
    int* dp = new int[num+1];

    //base case
    for(int i = 1; i <= num; i++)
        dp[i] = 1;
    
    for(int i = 1; i <= num; i++){
        int max = 0;
        for(int j = i-1; j > 0 ; j--)
            if(seq[j-1] < seq[i-1] && dp[j] >= max)
                max = dp[j];
        dp[i] = max + 1;
    }
    int len = dp[num];
    delete[] dp;
    return len;

}




int main(void){
    int a[8] = {186, 186, 150, 200, 160, 130, 197, 200};
    cout << IncreaseeSeq(a, 8);



    return 0;
}
//c++风格 STL









