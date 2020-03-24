#include<iostream>
using namespace std;

int main(void){


    return 0;
}

void InsertHeap(int a[], int k){    //大顶堆 中有k个元素
    int i = k+1;   //新元素插入到k+1位置
    while(i != 1){
        int j = i / 2;  //i结点的父节点
        if(a[i] < a[j])
            break;
        else{
            swap(a[i], a[j]);
            i = j;

        }
    }
}


















