/*
有n件物品，每件物品的重量为w[i], 价值为c[i].现在需要选出若干件
物品放入一个容量为V的背包中，使得在选入背包的物品重量和不超过容量
V的前提下，让背包中物品的价值之和最大，求最大价值（1<=n<=20）
*/

/*加入剪枝函数，进行算法的优化*/

#include<stdio.h>
#include<time.h>

#define MAXSIZE 25

float w[MAXSIZE];
float c[MAXSIZE];
int n;
float max_value = 0;
float max_weigh;

void DFS(int index, float sum_weigh, float sum_value){
    if(index == n){    //递归边界
        if(sum_weigh <= max_weigh && sum_value > max_value){
            max_value = sum_value;
        }
        return ;
    }
    DFS(index + 1, sum_weigh, sum_value);  //不加入背包

    if((sum_weigh + w[index+1]) <= max_weigh) //剪枝
        DFS(index + 1, sum_weigh + w[index+1], sum_value + c[index+1]);

}

int main(){
    clock_t begain, end;  //测试剪枝后花费的时间

    scanf("%d", &n);
    scanf("%f", &max_weigh);
    for(int i = 0; i < n; i++){
        scanf("%f", &w[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%f", &c[i]);
    }

    begain = clock();
    DFS(0, 0, 0);
    end = clock();

    printf("%f\n", max_value);
    printf("%lf", (double)(end - begain) / CLOCKS_PER_SEC);

    return 0;
}