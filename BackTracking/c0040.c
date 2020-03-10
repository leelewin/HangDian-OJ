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





















