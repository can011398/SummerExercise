#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define COURSE_FILE "./course.txt"
#define STUDENT_FILE "./stduent.txt"
#define ADMIN_FILE "./admin.txt"


typedef struct User{
    char account[20];
    char password[20];
    char identity;
    struct User *next;
} user;

typedef struct Course{
    char course_name[20];
    char course_teacher[20];
    char id[20];
    char max_student_num[20];
    struct Course *next
} course;

int main(){
    FILE *pfile;
    char *data;
    int length;
    char path[200];
    pfile = (path,"r");
    if(pfile==NULL){
        return NULL;
    }
    fseek(pfile, 0, SEEK_END);
    length=ftell(pfile);
    data =(char*)malloc((length+1)*sizeof(char));
    rewind(pfile);
    length = fread(data,1,length,pfile);
    data[length]='\0';
    fclose(pfile);
    printf("%s",data);
    return 0;
}


int main(){
    course *head=NULL;
    course *cur=NULL;
    char *order[4][100];
    char *token;
    char *saveptr;
    char *path;
    int index=0;
    token=strtok_r(path,"\n",&saveptr);
    while(token!=NULL){
        char *maken;
        char *saveptr1;
        int x=0;
        course *node=NULL;
        if(index>0){
            node=(course*)malloc(sizeof(course));
        }
        maken=(token,",",&saveptr1);
        while(maken!=NULL){
            if(index==0){
                strcpy(order[x],maken);
            }else{
                if(node!=NULL){
                    if(strcmp(order[x],"课程编号")==0){
                        strcpy(node->course_name,maken);
                    }else if(strcmp(order[x],"任课教师")==0){
                        strcpy(node->course_teacher,maken);
                    }else if(strcmp(order[x],"最大容纳人数")==0){
                        strcpy(node->max_student_num,maken);
                    }else if(strcmp(order[x],"课程编号")==0){
                        strcpy(node->id,maken);
                    }
                }
            }
            maken=(NULL,",",&saveptr1); 
            x++;           
        }
        if(index>0){
            if(head == NULL){
                head = node;
                cur = node;
            }else{
                cur->next = node;
                cur = cur->next;
            }
            node->next = NULL;
        }
        token=(NULL,"\n",&saveptr);
        index++;
    }
    for(int i=0;i<4;i++){
        printf("%s",order[i]);
    }
    course *p = head;
    while(p!=NULL){
        printf("%s,%s,%s,%s\n",p->course_name,p->course_teacher,p->id,p->max_student_num);
        p=p->next;
    }
    return 0;
}


int mian(){
    char a[100];
    char b[100];
    printf("请输入账号");
    scanf("%s",&a[100]);
    printf("请输入密码");
    scanf("%s",&b[100]);
    
}