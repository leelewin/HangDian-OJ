/*
输入格式：
在第一行给出不超过10^5的正整数N，即参赛人数。
随后N行，每行给出一位参赛者的信息和成绩
输出格式：
在一行中给出总得分最高的学校的编号及其总分，中间以空格进行分割。
题目保证答案唯一
*/
#include<stdio.h>

#define MAXNUM 10000
int school[MAXNUM];

int main(){
    int n;
    int info, grade;
    int i, j;
    int max_id = 0;
    int sum_info;
    int sum_grade = 0;
    

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d", &info, &grade);
        school[info] += grade;
        if(info > max_id)
             max_id = info;
    } 

    for(j = 1; j <= max_id; j++){
        if(school[j] > sum_grade){
            sum_grade = school[j];
            sum_info = j;
        }

    }

    printf("%d %d", sum_info, sum_grade);

    return 0;
}
