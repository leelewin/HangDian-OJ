#include<iostream>
using namespace std;

int Part(int a[], int start, int end){   //升序划分
    int i = start;
    int j = end;
    int temp = a[start];

    while(i<j){
        while(i<j && a[j]>temp) j--;
        if(i<j){
            swap(a[i], a[j]);
            i++;
        }
        while(i<j && a[i]<temp) i++;
        if(i<j){
            swap(a[i], a[j]);
            j--;
        }
    }
    a[i] = temp;
    return i;
}

int QuikSelect(int a[], int start, int end, int k){

    if(start <= end){                 //可以等于  别忘了
        int index = Part(a, start, end);  //进行一趟划分返回，划分点的下标，即当前index小元素
        if(index == k)
            return a[index];
        else if(index < k)                //去右半部分查找
            QuikSelect(a, index+1, end, k);
        else                              //去左半部分查找
            QuikSelect(a, start, index-1, k);
    }
}

int selectKSmall(int a[], int size, int k){
    return QuikSelect(a, 0, size-1, k-1);
}



int main(void){
   int a[6] = {3,2,1,5,6,4};
   // int a[9] = {3,2,3,1,2,4,5,5,6}; 
   cout << selectKSmall(a, 6, 1) << endl;

   return 0;                 //错误返回
}







