/*
给定两个字符串s1和s2，计算出将s1转化成s2所使用的最少操作数
你可以对一个字符串进行如下三种操作：
1.插入一个字符串
2.删除一个字符串
3.替换一个字符
示例：
s1 = "horse" s2 = "ros"
3


*/
/*
//暴力解法
#include<iostream>
using namespace std;
int min_compare(char* a, char* b, int n, int m){
    if(n == 0){
        return m;

    }
    if(m == 0){
        return n;
    }
    if(a[n-1] == b[m-1])
    {
        return min_compare(a, b, n-1, m-1);

    }
    else
    {
        return min(min_compare(a, b, n-1, m-1)+1,  //替换 
            min_compare(a, b, n-1, m)+1,      //删除
                min_compare(a, b, n, m-1)+1);

        
    }
    


}
int main(void){
    char a[] = "horse";
    char b[] = "ros";
    cout << min_compare(a, b, 5, 3);




    return 0;
}
*/
//c风格
/*
#include<iostream>
using namespace std;
const int MAXSIZE = 20;
int dp[MAXSIZE][MAXSIZE];
int min_distance(char* a, char* b, int n, int m){
    //base case

    for(int j = 0; j <= m; j++)
        dp[0][j] = j;
    for(int i = 0; i <= n; i++)
        dp[i][0] = i;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
            {
                int min = dp[i-1][j-1];
                if(min > dp[i-1][j])
                    min = dp[i-1][j];
                if(min > dp[i][j-1])
                    min = dp[i][j-1];
                dp[i][j] = min+1;
                
            }
        }
    return dp[n][m]; 
        


}
int main(void){

    string a[] = "asjhdj";
    char a[] = "horse";
    char b[] = "ros";
    cout << min_distance(a, b, 5, 3);


    return 0;
}
*/
//c++风格
#include<iostream>
#include<string>
using namespace std;
int MinDistance(string str1, string str2){
    int m = str1.length();
    int n = str2.length();
    int** dp = new int[m+1][n+1];

    //base case
    for(int i = 0; i <= m; i++)
        dp[i][0] = i;
    for(int j = 0; j <= n; j++)
        dp[0][j] = j;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1] + 1,
                                    dp[i-1][j] + 1,
                                        dp[i][j-1] + 1);
            
        }
    return dp[m][n];


}
int main(void){
    string str1("horse"), str2("ros");
    MinDistance(str1, str2);





    return 0;
}


