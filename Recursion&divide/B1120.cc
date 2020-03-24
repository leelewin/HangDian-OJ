#include<iostream>
using namespace std;

int maxPosition(int *a, int left, int right);
int main(void){
    int a[5] = {1, 2, 6, 4, 5};
    int ret;
    ret = maxPosition(a, 0, 4);
    cout << ret << endl;

    return 0;
}

int maxPosition(int *a, int left, int right){
    if(left == right)
        return left;
    int mid, max_left, max_right;
    mid = (right + left) / 2;
    max_left = maxPosition(a, left, mid);
    max_right = maxPosition(a, mid+1, right);
    if(a[max_left] > a[max_right])
        return max_left;
    else
        return max_right;
}


