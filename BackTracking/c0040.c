//迭代法实现图的着色问题
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAXSIZE 20
bool ok(int k);
void graphcolor(int n, int m);



int color[MAXSIZE];
int c[MAXSIZE][MAXSIZE];


//c[n][n]为邻接矩阵  n为结点个数  m为颜色数 color[n]为各个顶点的涂色
void graphcolor(int n, int m){  //下标均从0开始
    int k;
    int i;
    memset(color, 0, sizeof(color));  //初始化color数组为0
    k = 1;
    while(k <= n){
        i = color[k] + 1;
        while(i <= m){
            color[k] = i;
            if(ok(k) == true){        //顶点k涂当前颜色是否会发生冲突
                k++;
                break;
            }
            i++;
        }
        if(i > m){
            color[k] = 0;
            k = k - 1;           //回溯
        }
    }
    for(int i = 1; i<= n; i++)
        printf("%d", color[i]);
}
bool ok(int k){
    for(int i = 1; i <= k; i++)
        if(c[k][i] == 1 && color[k] == color[i])
            return false;
    return true;
}

int main(void){
    int n = 5;
    int m = 3;
    FILE *fd;

    fd = fopen("E:/OJ/test_new.txt","r");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            fscanf(fd, "%d", &c[i][j]);
            

    graphcolor(n, m); 
    return 0;
}










/*
//递归实现图的着色问题
#include<stdio.h>
#include<bool.h>

#define MAXSIZE 20

int n;
int ans;
color[MAXSIZE];
c[MAXSIZE][MAXSIZE];

int main(void){


    return 0;
}

void graphcolor(int i){
    if(i > n)
        ans++;
    else{
        for(int j = 1; j < m; j++){
            color[i] = j;
            if(ok(i) == TRUE)
                graphcolor(i+1);
        }
    }
}
//判断顶点i与相连的顶点的颜色是否相同
bool ok(int i){
    for(int j = 1; j < n; j++){
        if(c[i][j] == 1 && color[i] == color[j])
            return FALSE;
    }
    return TRUE;
}
*/





















