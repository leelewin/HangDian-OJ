#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
#define MAXSIZE 20
int n;
int a[MAXSIZE];
int b[MAXSIZE];
int sum1[MAXSIZE];
int sum2[MAXSIZE];
int bestsum;
int x[MAXSIZE];
bool IsOk(int k);

/*
a[n]存储作业在机器1上的处理时间
b[n]存储作业在机器2上的处理时间
x[k]第k次选择的任务号为x[k]
sum1[k]任务k在机器1的运行时长
sum2[k]任务k在机器2的运行时长
bestsum 最短的运行时长
*/
void BatchJob(int k){
    if(k > n){
        if(sum2[k-1] < bestsum)
            bestsum = sum2[k-1];
        return;
    }
    else{
        for(int i=1; i<=n; i++){
            x[k] = i;
            sum1[k] = sum1[k-1] + a[x[k]];
            sum2[k] = max(sum1[k], sum2[k-1]) + b[x[k]];
            if(IsOk(k) == true && sum2[k] < bestsum){
                BatchJob(k+1);
                x[k+1] = 0;
                sum1[k+1] = 0;
                sum2[k+1] = 0;
            }
        }

    }
}

bool IsOk(int k){
    for(int l=1; l<k; l++){
        if(x[l] == x[k])
            return false;
    }
    return true;
}
int main(void){

    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
    bestsum = 1000;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    for(int j=1; j<=n; j++)
        scanf("%d", &b[j]);
    BatchJob(1); 
    cout<<bestsum<<endl;
    
    return 0;


}