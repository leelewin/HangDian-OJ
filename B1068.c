#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void qiuk_sort(int *a, int low_l, int high_h){
    int tmp;
    int low = low_l;
    int high = high_h;
    int p;

    srand((unsigned)time(NULL));

    if(low < high){
        p = rand() % (high - low + 1) + low;   //这两句要放在if条件句中，否则会出现算数错误
        swap(a[low], a[p]);

        tmp = a[low];
        while(low < high){
            while(a[high] > tmp && low < high) 
                high--;
            if(low < high){
                a[low] = a[high]; 
                low++;
            }
            while(a[low] < tmp && low < high)
                low++;
            if(low < high){
                a[high] = a[low];
                high--;
            }
        }
        a[low] = tmp;
        qiuk_sort(a, low_l, low-1);
        qiuk_sort(a, low+1, high_h);
    }
}

int main(){
    int a[5] = {7, 4, 3 ,6 ,9};
    qiuk_sort(a, 0, 4);

    for(int i = 0; i < 5; i++){
        printf("%d", a[i]);

    }

    return 0;
}

