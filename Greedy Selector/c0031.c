/*
设有 n 个活动的集合 E = {1 , 2 , ⋯, n} , 其中每个活动都要求使用同一资源(如演讲
会场) ,而在同一时间内只有一个活动能使用这一资源。每个活动 i 都有一个要求使用该 资源的起始时间 si
和一个结束时间 fi , 且 si < fi。如果选择了活动 i, 则它在半开时间区
间[ si , fi )内占用资源。若区间[ si , fi )与区间[ sj , fj )不相交, 则称活动 i 与活动 j 是相 容的。也就是说, 
当 si≥ fj 或 sj ≥ fi时, 活动 i 与活动 j 相容。活动安排问题要求在所给 的活动集合中选出最大的相容活动子集。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 30

typedef struct active{
    int begain;
    int end;

}active;

int compare(const void *a, const void *b){
    active *c = (active *)a;
    active *d = (active *)b;

    return c->end - d->end;
}

int main(void){
    active act[MAXSIZE];
    int n;
    int a[MAXSIZE];
    int i;
    int count = 1;

    qsort(act, n, sizeof(active), compare); //按照结束时间从小到大排序
    int j = 0;
    a[0] = 1;
    for(i = 1; i < n; i++){
        if(act[i].begain < act[j].end){ //不选
            a[i] = 0;

        }
        else{
            a[i] = 1;
            j = i;
            count++;
        }
    }
    printf("the number of active = %d", count);

    return 0;
}
