/*
区间不相交问题：给出N个开区间（x, y）,从中选择尽可能多的开区间，使得
这些开区间两两没有交集
     x --- y
            -------
       ------
 ---------   
*/
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50

typedef struct section
{
    int x;
    int y;
}section;

int compare(const void *a, const void *b){
    section *c = (section *)a;
    section *d = (section *)b;
    if(c->x != d->x)
        return c->x > d->x;
    else 
        return c->y < d->y;

}

int main(){
    int n;  //区间的个数
    section sections[MAXSIZE];
    int count = 1;
    int temp;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &sections[i].x, &sections[i].y);
    }

    qsort(sections, n, sizeof(section), compare);

    temp = sections[n-1].x;
    for(int i = n-1; i >= 0; i--){
        if(sections[i-1].y <= temp){
            temp = sections[i-1].x;
            count++;
        }
    }

    printf("%d", count);

    return 0;
}



















