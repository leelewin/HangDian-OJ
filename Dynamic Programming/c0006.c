#include<stdio.h>
#include<float.h>
#include<string.h>

#define MAXSIZE 30

double optimal_BST(int n, double p[], double C[][MAXSIZE], int R[][MAXSIZE]);

int main(void){
    int r[MAXSIZE];
    double p[MAXSIZE];                      //序列元素的查找概率
    double C[MAXSIZE][MAXSIZE];            //C[i][j]表示二叉树T[i][j]的最少比较次数
    int R[MAXSIZE][MAXSIZE];               //R[i][j]表示二叉树T[i][j]的根结点
    int n;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lf", &p[i]);
    memset(C, 0, sizeof(C));
    memset(R, 0, sizeof(R));

    printf("%f", optimal_BST(n, p, C, R));


    return 0;
}

double optimal_BST(int n, double p[], double C[][MAXSIZE], int R[][MAXSIZE]){
    int i, j, d, k;
    double sum;
    double min;
    int mark;

    //初始化
    for(i = 1; i <= n + 1; i++)
        C[i][i-1] = 0;        //空树的比较次数
    for(j = 1; j <= n; j++){
        C[j][j] = p[j];
        R[j][j] = j;
    }

    for(d = 1; d < n; d++)          //按照对角线的方向进行计算
        for(i = 1; i <= n - d; i++){
            j = d + i;
            sum = 0; min = DBL_MAX;
            for(k = i; k <= j; k++){    //计算T[i][j]中以k为根的最少比较次数
                sum += p[k];
                if(C[i][k-1] + C[k+1][j] < min){
                    min = C[i][k-1] + C[k+1][j];
                    mark = k;
                }

            }
            C[i][j] = min + sum;
            R[i][j] = mark;
        }

    return C[1][n];
}