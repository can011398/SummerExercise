#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cu {
    char id[10];
    char course_name[100];
    char teacher_name[100];
    int max_student_num;
    struct cu *next;
} Course;

struct Class{
    char subject[10];
    int y;
    struct  Class *next1;
};
typedef struct User{
    char admin_account[100];
    char admin_password[20];
    char student_account[100];
    char student_password[20];
    char name[20];
    int lesson;
    struct Class class;
    struct User *next;
} user;

int main(){
    FILE * pfile;
    char *data;
    char path[200];
    int length;
    scanf("%s",path);
    pfile=fopen(path,"r");
    if(pfile==NULL){
        printf("open fail\n");
        return 0;
    }
    fseek(pfile,0,SEEK_END);
    length = ftell(pfile);
    data=(char *)malloc((length+1)*sizeof(char));
    rewind(pfile);
    length=fread(data,1,length,pfile);
    data[length]='\0';
    fclose(pfile);

    char *token;
    char *saveptr;
    token=strtok_r(data,"\n",&saveptr);
    while(token!=NULL){
        char *maken;
        char *saveptr1;
        maken=strtok_r(token,",",&saveptr1);
        while(maken!=NULL){
            printf("%s\n",maken);
            maken=strtok_r(NULL,",",&saveptr1);
        }
        token =strtok_r(NULL,"\n",&saveptr);
    }
    return 0;
}
