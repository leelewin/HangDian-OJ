#include<stdio.h>

#define MAXSIZE 200

typedef struct item{
    int number;  //物品编号
    double weight; //物品的重量
    double value;   //物品的价值
    double wpv;     //物品的单位价值
}item;

int main(void){
    item items[MAXSIZE];
    int n; //物品个数
    int C;  //背包容量
    double maxvalue = 0;

    qsort(); //按照单位价值从大到小进行排序

    for(int i = 1; i <= n; i++){
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






















