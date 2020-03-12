#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 10

int path[MAXSIZE];
int c[MAXSIZE][MAXSIZE];
int visited[MAXSIZE];


//c[][]图的邻接矩阵   path[]保存经过的顶点  visited[]标记数组  n总的顶点数
//k=1开始  path[1] = 1从顶点1开始
bool travel(int k, int n){
    if(k >= n){
        if(c[path[k]][1] == 1) 
            return true;
        return false;
    }
    else{
        for(int i = 1; i <= n; i++){
            if(c[path[k]][i] == 1 && visited[i] == 0){
                path[k+1] = i;
                visited[i] = 1;
                if(travel(k+1, n))
                    return true;
                path[k+1] = 0;
                visited[i] = 0;
            }

        }
        return false;
    }
}
int main(void){
    FILE *fd;
    fd = fopen("E:/OJ/test_new.txt", "r");
    int n = 5;
    int k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        fscanf(fd, "%d", &c[i][j]);

    k = 1; path[1] = 1;visited[1] = 1;
    if(travel(k, n)){
        printf("Have hamcircle\n");
        for(int i = 1; i <= n; i++)
            printf("%d ", path[i]);
    }
    else
        printf("not have hamcircle\n");
    
    return 0;
}















/*  深度搜素
#include<stdio.h>
void travel(int k);
int visited[10];
int path[10];
int c[10][10];
int n = 5;
int x = 0;

// path[n]记录走过的路径    visited[n]记录已经走过的顶点
void travel(int k){    //从顶点k开始
    printf("%d\n", k);
    visited[k] = 1;
    path[++x] = k;
    int i = 1;
    while(i <= n){
        if(visited[i] == 0 && c[k][i] == 1)
            travel(i);
        i++;

    }

}
int main(void){
    FILE *fd;
    fd = fopen("E:/OJ/test_new.txt", "r");

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        fscanf(fd, "%d", &c[i][j]);
    
    travel(1);
    for(int i = 1; i <= n; i++)
        printf("%d ", path[i]);

    return 0;
}
*/














