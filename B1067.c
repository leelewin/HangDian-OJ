#include<stdio.h>
#include<math.h>

const double eps = 1e-5;

double f(double x){
    return x * x;
}

double lower_bound(double left, double right, double x){
    double mid;

    while(right - left >= eps){
        mid = left + (right - left) / 2;
        if(f(mid) > x)
            right = mid;
        else 
            left = mid;
    }
    return right;

}

int main(){

    //通过二分法求得 根下2
    printf("%f\n", lower_bound(1, 2, 2));
    //通过C自带的数学库计算
    printf("%f", sqrt(2));


    return 0;
}