/*
文件指针：FILE
EOF	(-1)
FILE* fopen (const char* filename, const char* mode);   否则返回NULL
mode模式有"r" "w" "a" "r+" "W+"
int fclose(FILE *stream)   成功返回0，否则返回EOF

getc()   putc()

文件指针:   stdin  stdout  stderr
fprintf()
fscanf()

fputs()
fgets()

int rename(const char *old_name, const char *new_name)
int remove(const char *filename)

fread()
fwrite()
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 60

int main(int argc, char *argv[]){
    FILE *in, *out;
    char name[MAXSIZE];
    int ch;
    int count = 0;


    if(argc < 2){
        fprintf(stderr, "Usage: %s", argv[0]);
        exit(1);
    }

    if((in = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "can't open %s", argv[1]);
        exit(2);
    }

    strcpy(name, argv[1]);
    strcat(name, "_new");

    if((out = fopen(name, "w")) == NULL){
        fprintf(stderr, "can't open %s", name);
        exit(3);
    }

    while((ch = getc(in)) != EOF){
        //每三个字符存入第二个文件
        if(count % 3 == 0)
            putc(ch, out);
        count++;
    }

    if(fclose(in) != 0 || fclose(out) != 0){
        fprintf(stderr, "can't close file");
        exit(4);
    }


    return 0;
}