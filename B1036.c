/*
输入格式：
在一行中给出正方形边长N（3<=N<=20）和组成正方形的某种字符C
输出格式：
由给定字符C画出正方形。



*/
//技巧：整数除以二进行四舍五入的操作可以通过判断它是否是奇数来解决，
//以避免浮点数的介入
#include<stdio.h>
#include<math.h>

int main(){
    int n;
    char ch;
    int row;

    scanf("%d %c", &n, &ch);
    //进行四舍五入
    if(n % 2 == 0)
        row = n / 2;
    else 
        row = n / 2 + 1;

    for(int i=0; i<row; i++){
        if(i == 0 || i == row-1){
            for(int j=0; j<n; j++)
                printf("%c", ch);
            printf("\n");
        }
        else{
            printf("%c", ch);
            for(int j=0; j<n-2; j++)
                printf(" ");
            printf("%c", ch);
            printf("\n");
        }

    }

    



    







} 




















