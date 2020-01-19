#include<stdio.h>

#define MAXSIZE 100

typedef struct {
    int id;
    char gender;

}Stu, *q;

int main(){
    Stu std;
    Stu *p;
    Stu st[MAXSIZE];

    Stu git = {5, 'u'};
    p = &git;

    st[0].gender = 'r';
    std.id = 4;
    std.gender = 't';
    printf("%c",p->gender);
    printf("%d", std.id);
    printf("%c", st[0].gender);

    return 0;
}