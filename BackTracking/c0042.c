
//x[k] 表示第k个皇后放在第k行的第x[k]列，x[k]属于{1，2， 3， 4}对于四皇后来说
// 解决对角线冲突问题（i， xi）(j, xj)两个皇后， i - xi != j- xj
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXSIZE 20


bool ok(int k);
int x[MAXSIZE];
int n;
int sum = 0;

void n_queen(int k){
    if(k > n){
        sum++;
        return ;  //注意返回值
    }
    else{
        for(int i = 1; i <= n; i++){
            x[k] = i;
            if(ok(k) == true){
                n_queen(k+1);
                x[k+1] = 0;
            }
            
        }
        
    }
}

bool ok(int k){
    for(int i = 1; i < k; i++){   //不取等于
        // if(x[k] == x[i] || abs(k - x[k]) == abs(i - x[i]))  出错
        if(x[k] == x[i] || abs(k - i) == abs(x[k] - x[i]))
            return false;
    }
    return true;  //注意
}

int main(void){
    n = 8;
    n_queen(1);
    for(int i = 1; i <= n; i++)
        printf("%d ", x[i]);

    printf("\n%d", sum);  //输出全部的解法

    return 0;
}

    







