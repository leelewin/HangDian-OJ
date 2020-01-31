#include<stdio.h>
#include<stdbool.h>

typedef struct Node{
    char ch;
    int next;
    bool flag;
}node;

int main(){
    int list1, list2;
    int n;
    node slist[100010];

    int addr, next;
    char ch;

    scanf("%d %d %d", &list1, &list2, &n);
    for(int i = 0; i < n; i++){
        scanf("%d %c %d", &addr, &ch, &next);
        slist[addr].ch = ch;
        slist[addr].next = next;
        slist[addr].flag = false;
    }

    //枚举第一条链表
    while(list1 != -1){
        list1 = slist[list1].next;
        slist[list1].flag = true;
    }

    //枚举第二条链表
    while(list2 != -1){
        if(slist[list2].flag == true)
            break;
        list2 = slist[list2].next;
        
    }
    printf("%05d", list2);

    return 0;
}