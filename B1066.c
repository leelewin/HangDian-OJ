#include<stdio.h>

int lower_bound(const int a[], const int n, int x){
    int right = 0;
    int left = n - 1;
    int mid;

    while(right < left){
        mid = (right + left) / 2;

        if(a[mid] == x) 
            return mid;
        else if(a[mid] > x)
            left = mid - 1;
        else
            right = mid + 1;
    }    

}

int main(){
    int a[6] = {2, 4, 5, 7, 8, 9};
    printf("%d", lower_bound(a, 6, 9));

    return 0;
}
















