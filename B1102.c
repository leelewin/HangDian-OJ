#include<stdio.h>

//递归
int n_x1(int n, int x){
    if(x==0)
        return 1;
    else
        return n * n_x(n, x-1);
}

//分治
int n_x2(int n, int x){
    if(x==0)
        return 1;
    else
    {
        if(x % 2 == 0)
            return n_x2(n, x / 2) * n_x2(n, x / 2);
        else
            return n * n_x2(n, x-1);
    }

}

int main(void){
    int ret;

    ret = n_x2(3, 0);
    printf("%d", ret);

}
















