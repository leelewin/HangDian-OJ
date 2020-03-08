#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 200

typedef struct item{
    int number;  //物品编号
    double weight; //物品的重量
    double value;   //物品的价值
    double wpv;     //物品的单位价值
}item;

int compare(const void *a, const void *b){
    item *c = (item *)a;
    item *d = (item *)b;
    return d->wpv - c->wpv;
}

int main(void){
    item items[MAXSIZE];
    int i;
    int n;                           //物品个数
    double C;                        //背包容量
    double maxvalue = 0;

    scanf("%d", &n);                 //输入物品的个数
    scanf("%lf", &C);                 //输入背包容量
    for(i = 0; i < n; i++)
        scanf("%lf", &items[i].weight);  //输入物品重量
    for(i = 0; i < n; i++){            //输入物品的价值
        items[i].number = i;
        scanf("%lf", &items[i].value);
        items[i].wpv = items[i].value / items[i].weight;
    }

    qsort(items, n, sizeof(item), compare); //按照单位价值从大到小进行排序

    for(int i = 0; i < n; i++){
        if(items[i].weight <= C){
            C = C - items[i].weight;
            maxvalue += items[i].value; 
        }
        else{
            maxvalue += C * items[i].wpv;
            break;
        }

    }
    printf("%lf", maxvalue);

    return 0;
}






















