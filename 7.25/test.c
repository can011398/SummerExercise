#define COURSE_FILE = "./course.txt"


typedef struct course{
    char course_name[20];
    char teacher_name[20];
    int  id[20];
    int max_student_num[20];
    struct course *massage;
} Course;


typedef struct user{
    char account[20];
    char password[20];
    char name[20];
    struct user *next;
} User;


#include <stdio.h>

#include <stdlib.h>

#include <string.h>


char read_file(char *path,char *data){

    FILE *pfile;
    int length;
    pfile = fopen(path,"r");
    if(pfile ==NULL){
        return NULL;
    }
    fseek(pfile, 0, SEEK_END);
    length = ftell(pfile);
    data = (char *)malloc((length +1)*sizeof(char));
    rewind (pfile);
    length = fread(data, 1, length, pfile);
    data[length]='\0';
    fcolse(pfile);
    return data;
}


int init(Course *course_head,User *user_head){
    printf("begin read file\n");
    char *content;
    read_file(COURSE_FILE, content);
}



int main(){
    char next[100];
    next=init()
}
