#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cu {
    char id[10];
    char course_name[100];
    char teacher_name[100];
    int max_student_num;
    int num;
    char name[20];
    struct cu *next;
} Course;

struct Class{
    char subject[10];
    int y;
    struct  Class *next1;
};
typedef struct User{
    char account[100];
    char password[20];
    char name[20];
    char identity[10];
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
        return 0;
    }
    fseek(pfile,0,SEEK_END);
    length = ftell(pfile);
    data=(char *)malloc((length+1)*sizeof(char));
    rewind(pfile);
    length=fread(data,1,length,pfile);
    data[length]='\0';
    fclose(pfile);


    int tim;
    scanf("%d",&tim);
    
    Course *head1=NULL;
    Course *cur1=NULL;
    char *token;
    char *saveptr;
    int index=0;
    char order[4][100];
    token=strtok_r(data,"\n",&saveptr);
    if(tim==0){
        while(token!=NULL){
        char *maken;
        int x=0;
        Course *node=NULL;
        if (index>0){
            node=(Course*)malloc(sizeof(Course));
        }
        char *saveptr1;
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
                        node->max_student_num=atoi(maken);
                    }
                }
            }
            maken=strtok_r(NULL,",",&saveptr1);
            x++;
        }
        if(index>0){
            if(head1==NULL){
                head1=node;
                cur1=node;
            }else{
                cur1->next=node;
                cur1=cur1->next;
            }        
        }
        token =strtok_r(NULL,"\n",&saveptr);
        index++;
    }
    for(int i=0;i<4;i++){
        printf("%s;",order[i]);
    }
    Course *p=head1;
    while(p!=NULL){
        printf("%s,%s,%s,%d\n",p->id,p->course_name,p->teacher_name,p->max_student_num);
        p=p->next;
    }
}
if(tim!=0){
    user *head=NULL;
    user *cur=NULL;
    while(token!=NULL){
        int y=0;
        user *many=NULL;
        char *saveptr1;
        if(index>0){
            many=(user*)malloc(sizeof(user));
        }
        char *maken=strtok_r(token,",",&saveptr1);
        while(maken!=NULL){
            if(index==0){
                strcpy(order[y],maken);
            }else{
                if(many!=NULL){
                    if(strcmp(order[y],"账号")==0){
                        strcpy(many->account,maken);
                        strcpy(many->identity,"管理员");
                    }else if(strcmp(order[y],"学号")==0){
                        strcpy(many->account,maken);
                        strcpy(many->identity,"学生");
                    }
                    else if(strcmp(order[y],"密码")==0){
                        strcpy(many->password,maken);
                    }else if(strcmp(order[y],"姓名")==0){
                        strcpy(many->name,maken);
                    }
                }
            }
            maken=strtok_r(NULL,",",&saveptr1);
            y++;
        }
        if(index>0){
            if(head==NULL){
                head=many;
                cur=many;
            }else{
                cur->next=many;
                cur=cur->next;
            }
            many->next=NULL;
        }
        token=strtok_r(NULL,"\n",&saveptr);
        index++;
    }
    for(int i=0;i<3;i++){
        printf("%s",order[i]);
    }
    printf("\n");
    user *p=head;
    if(tim==1){
    while(p!=NULL){
        printf("%s,%s,%s,%s\n",p->account,p->password,p->name,p->identity);
        p=p->next;
    }
    }else{
        while(p!=NULL){
        printf("%s,%s,%s,%s\n",p->account,p->password,p->name,p->identity);
        p=p->next;
    }
}
}
    return 0;
}
