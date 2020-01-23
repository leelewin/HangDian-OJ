#include<stdio.h>
#include<stdlib.h>

/* 选取的数据结构形式不正确 */
/* ************************ */
// #define MAXSIZE 20

// int variety[MAXSIZE];
// int repetory[MAXSIZE];

// int main(){
//     int n;
//     int max_need;
//     int r_per_v[MAXSIZE];
//     double profit;

//     scanf("%d %d", &n, &max_need);

//     for(int i = 0; i < n; i++)
//         scanf("%d", &variety[i]);
//     for(int j = 0; j < n; j++)
//         scanf("%d", &repetory[j]);
//     //假设单价已经有序了

//     for(int x = 0; x < n; x++){
//         if(variety[x] > max_need){
//             //最大需求乘单价
//             profit = 

//             break;
//         }
//         else{
//             max_need -= variety[x];
//             profit += repetory[x];
//         }

//     printf("%.2f", profit);

//     }
// }
/* ********************************************** */
#define MAXSIZE 1010

typedef struct cake{
    double inventory;
    double total_price;
    double price;
}cake;

//排序用的比较函数
int compare(const void *a, const void *b){
    cake *c = (cake *)a;
    cake *d = (cake *)b;

    return (c->price) - (d->price);


}

int main(){
    cake cakes[MAXSIZE];
    int n;
    int max_need;
    double profit = 0;

    //输入相关信息
    scanf("%d %d", &n, &max_need);
    for(int i = 0; i < n; i++)
        scanf("%lf", &cakes[i].inventory);
    for(int i = 0; i < n; i++)
        scanf("%lf", &cakes[i].total_price);
    
    for(int i = 0; i < n; i++)
        cakes[i].price = cakes[i].total_price / cakes[i].inventory;
    //对月饼的单价进行排序 
    qsort(cakes, n, sizeof(cake), compare);

    //贪心求解，选择单价最高的
    for(int i = 0; i < n; i++){
        if(max_need < cakes[i].inventory){
            profit += cakes[i].price * max_need;
            break;
        }
        else{
            max_need -= cakes[i].inventory;
            profit += cakes[i].total_price;
        }
    }
    printf("%.2f", profit);
    
    return 0;
}    

 
 
 
 