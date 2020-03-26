#include<iostream>
using namespace std;

//一趟划分
int Part(int a[], int start, int end){  //倒序
    int i = start;
    int j = end;

    int temp = a[i];
    while(i < j){
        while(i<j && a[j]<temp) j--;
        if(i<j){
            swap(a[i], a[j]);
            i++;
        }
        while(i<j && a[i]>temp) i++;
        if(i<j){
            swap(a[i], a[j]);
            j--;
        }

    }
    a[i] = temp;
    return i;

}

//快排
void QuikSort(int a[], int start, int end){
    if(start < end){
        int povit = Part(a, start, end);
        QuikSort(a, start, povit-1);
        QuikSort(a, povit+1, end);
    }
}

int main(void){
    int a[5] = {2, 3, 1, 8, 4};
    QuikSort(a, 0, 4);

    for(int i=0; i<5; i++){
        cout<<a[i]<<endl;
    }

    return 0;
}