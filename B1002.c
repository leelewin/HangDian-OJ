#include<stdio.h>

#define MAXSIZE 20


int P[MAXSIZE];
int hashTable[MAXSIZE] = {0};

void generate(int index, const int n){
    //递归的边界条件
    if(index == n + 1){
        for(int i = 1; i <= n; i++){
            printf("%d", P[i]);
        }
        printf("\n");
        return ;
    }
    //
    for(int j = 1; j <= n; j++){
        if(hashTable[j] == 0){
            P[index] = j;
            hashTable[j] = 1;
            generate(index + 1, n);
            hashTable[j] = 0;
        }
    }
}


int main(){
    int n=3;
    generate(1, n);

    return 0;
}


















