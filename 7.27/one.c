#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define COURSE_FILE "./course.txt"
#define STUDENT_FILE "./stduent.txt"
#define ADMIN_FILE "./admin.txt"


typedef struct ids {
    char id[20];
    struct ids *next;
} IDS;

typedef struct user{
    char account[20];
    char password[20];
    char id[20];
    struct user *next;
    int course_num;
    char course_name[20];
    IDS *courses;
} User;

typedef struct course{
    char course_name[20];
    char course_teacher[20];
    char id[20];
    int max_student_num;
    int course_person;
    char choose_id[400];
    struct course *next;
    IDS *students;
} Course;



int readfile (char *path, char *data){
    FILE *pfile;
    int length;
    pfile = (path,"r");
    if(pfile==NULL){
        return 1;
    }
    fseek(pfile, 0, SEEK_END);
    length=ftell(pfile);
    data =(char*)malloc((length+1)*sizeof(char));
    rewind(pfile);
    length = fread(data,1,length,pfile);
    data[length]='\0';
    fclose(pfile);
    return 0;
    
}


int init(char *path,char *data){
    Course *head=NULL;
    Course *cur=NULL;
    char *order[4][100];
    char *token;
    char *saveptr;
    int index=0;
    token=strtok_r(path,"\n",&saveptr);
    while(token!=NULL){
        char *maken;
        char *saveptr1;
        int x=0;
        Course *node=NULL;
        if(index>0){
            node=(Course*)malloc(sizeof(Course));
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
    Course *p = head;
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