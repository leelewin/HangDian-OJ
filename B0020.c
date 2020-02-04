#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20

typedef struct Stu{
    char name[MAXSIZE];
    int age;
    float grade;
}stu;

int compare(const void *a, const void *b){
    stu *c = (stu *)a;
    stu *d = (stu *)b;

    //return c->grade > d->grade; 由小到大
    return c->grade < d->grade;    //由大到小
}

int main(){
    stu studentA[3];
    stu studentB[3];
    FILE *fp;


    //以二进制方式打开文件
    if((fp = fopen("cs.txt", "wb+")) == NULL){
        fprintf(stderr, "can't open");
        exit(1);
    }

    //通过键盘输入结构体数据
    for(int i = 0; i < 3; i++){
        scanf("%s %d %f", studentA[i].name, &studentA[i].age, &studentA[i].grade);
    }

    //写入文件
    fwrite(studentA, sizeof(stu), 3, fp);
    //重定位到文件开头
    rewind(fp);
    //读出文件到结构体数组
    fread(studentB, sizeof(stu), 3, fp);

    //关闭文件
    if(fclose(fp) != 0){
        fprintf(stderr, "can't close");
        exit(2);
    }

    //对结构体按照grade 由大到小 进行排序
    qsort(studentB, 3, sizeof(stu), compare);

    printf("name:%s\n age:%d\n grade:%.2f", studentB[0].name, studentB[0].age, studentB[0].grade);

    return 0;
}