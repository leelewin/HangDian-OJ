#include<iostream>
using namespace std;

int multinomial(int *a, int n, int x);
int main(void){
    int a[3] = {1, 2, 3};
    int ret;
    ret = multinomial(a, 3, 2);
    cout<<ret<<endl;

    return 0;
}

int multinomial(int *a, int n, int x){
    int sum = 0; 
    int index = 1;
    for(int i=0; i<n; i++){
        sum += a[i] * index;
        index = index * x;
    }
    return sum;

}