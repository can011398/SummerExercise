#define COURSE_FILE "./course.txt"

#define STUDENT_FILE  "./student.txt"

#define ADMIN_FILE  "./admin.txt"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>


typedef struct course{
    char course_name[20];
    char teacher_name[20];
    int  id[20];
    char max_student_num[20];
    struct course *massage;
} Course;


typedef struct user{
    char account[20];
    char password[20];
    char name[20];
    char is_admin;
    int lesson_num;
    struct user *next;
} User;

typedef struct jjnn{
    char lesson_name[20];
    struct jjnn *next;
} jjnn;

int function_choose(){
    printf("welcome to class system\n");
    printf("1.init system\n");
    printf("2.print information\n");
    int index = 0;
    scanf("%d",index);
    return index;
}


char *read_file(char path[200]){

    FILE *pfile;
    char *data;
    int length;
    pfile = fopen(path,"r");
    if(pfile ==NULL){
        printf("not");
    }
    fseek(pfile, 0, SEEK_END);
    length = ftell(pfile);
    data = (char *)malloc((length +1)*sizeof(char));
    rewind (pfile);
    length = fread(data, 1, length, pfile);
    data[length]='\0';
    fclose(pfile);
    return data;
}


int parse_course(char *content,Course *course_head){

    char *token;
    char *saveptr;
    int index=0;
    char order[4][100];
    Course *course_head=NULL;
    Course *cur=NULL;

    token = strtok_r(content,"\n",&saveptr);
    while(token != NULL){
        char *maken;
        char *saveptr1;
        int x=0;
        Course *node=NULL;
        if(index>0){
            node=(Course*)malloc(sizeof(Course));
        }
        maken=strtok_r(token,",",&saveptr1);
        while(maken!=NULL){
            if(index==0){
                strcpy(order[x],maken);
            }else{
                if(node!=NULL){
                    if(strcmp(order[x],"课程编号")==0){
                        strcpy(node->id,maken);
                    }else if(strcmp(order[x],"课程名称")==0){
                        strcpy(node->course_name,maken);
                    }else if(strcmp(order[x],"教师")==0){
                        strcpy(node->teacher_name,maken);
                    }else if(strcmp(order[x],"最大容纳人数")==0){
                        strcpy(node->max_student_num,maken);                       
                        }
                    }
                }maken=strtok_r(NULL,",",&saveptr1);
                x++;
        }
        if(index>0){
            if(course_head==NULL){
                course_head=node;
                cur=node;
            }else{
                cur->massage=node;
                cur=cur->massage;
            }
        }
        if(index>0){
            if(course_head=NULL){
                course_head=node;
                cur=node;
            }else{
                cur->massage=node;
                cur=cur->massage;
            }
    }        
        token=strtok_r(NULL,"\n",&saveptr);
        index++;
    }

}


int parse_user(char *content, int is_admin, User *user_head){
    char *token;
    char *saveptr;
    char *path;
    token=strtok_r(path,"\n",&saveptr);
    while(token!=NULL){
        char *maken;
        char *saveptr1;
        User *node=NULL;
        maken=strtok_r(token,",",&saveptr1);
        while(maken!=NULL){

            maken=strtok_r(NULL,",",&saveptr1);
        }
        token=strtok_r(NULL,"\n",&saveptr);
    }
}


int main(){

}
