#include<stdio.h>

int f(int n){
    if(n == 1)
        return 1;
    else if(n == 2)
        return 1;
    else
        return f(n-1)+f(n-2);
}

int main(void){
    printf("%d", f(3));
}













