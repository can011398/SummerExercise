#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct cu {
    char id[10];
    char course_name[100];
    char teacher_name[100];
    int max_student_num;
    struct cu *next;
} Course;
typedef struct student{
    char student_id[20];
    char student_name[100];
    char password[100];
    struct student *next1;
}Student;
typedef struct admin {
    char account[20];
    char admin_name[100];
    char admin_password[100];
    struct admin *next2;
}Admin;
int main(){
    FILE *pfile;
    char *data;
    char path[200];
    scanf("%s",path);
    int length;
    pfile=fopen(path,"r");
    if(pfile==NULL){
        return 1;
    }
    fseek(pfile,0,SEEK_END);
    length=ftell(pfile);
    data=(char*)malloc((length+1)*sizeof(char));
    rewind(pfile);
    length=fread(data,1,length,pfile);
    data[length]='\0';
    fclose(pfile);
    printf("请问你读入的是:\n1.学生信息\n2.管理员信息\n3.课程信息");
    int j;
    scanf("%d",&j);
    if(j==3){
        Course *head=NULL;
        Course *mnb=NULL;
        char *token;
        char *saveptr;
        char order [4][100];
        int nmum=0;
        token = strtok_r(data,"\n",&saveptr);
        while(token!=NULL){
            Course *new=NULL;
            if(nmum>0){
                new=(Course*)malloc(sizeof(Course));
                new->next=NULL;
            }     
            char *maken;
            const char s[2]=",";
            int le=0; 
            maken=strtok(token,s);
            while(maken!=NULL){
                if(nmum==0){
                    strcpy(order[le],maken);
                }else{
                    if(new!=NULL){
                        if(strcmp(order[le],"课程编号")==0){
                            strcpy(new->id,maken);
                        }else if(strcmp(order[le],"课程名称")==0){
                            strcpy(new->course_name,maken);
                        }else if(strcmp(order[le],"教师")==0){
                            strcpy(new->teacher_name,maken);
                        }else if(strcmp(order[le],"最大容纳人数")==0){
                            new->max_student_num=atoi(maken);
                        }
                    }
                }
                maken=strtok(NULL,s);
                le++;
            }
            if(new!=NULL){
                if(head==NULL){
                    head=new;
                    mnb=new;
                }else{
                    mnb->next=new;
                    mnb=new;
                }
            }
            token=strtok_r(NULL,"\n",&saveptr);
            nmum++;
        }
        for(int i=0; i<4; i++) {
		    printf("%s,", order[i]);
	    }
	    printf("\n");

        Course *p = head;
        while(p != NULL) {
            printf("%s, %s, %s, %d\n",p->id, p->course_name, p->teacher_name, p->max_student_num);
            p = p->next;
        }
    }else if(j==1){
        Student *head1=NULL;
        Student *mnb1=NULL;
        char *token1;
        char *saveptr1;
        char hang[3][100];
        int num1=0;
        token1=strtok_r(data,"\n",&saveptr1);
        while(token1!=NULL){
            Student *node=NULL;
            if(num1>0){
                node=(Student*)malloc(sizeof(Student));
                node->next1=NULL;
            }
            char *maken1;
            const char s1[2]=",";
            int ke=0;
            maken1=strtok(token1,s1);
            while(maken1!=NULL){
                if(num1==0){
                    strcpy(hang[ke],maken1);
                }else{
                    if(node!=NULL){
                        if(strcmp(hang[ke],"学号")==0){
                            strcpy(node->student_id,maken1);
                        }else if(strcmp(hang[ke],"姓名")==0){
                            strcpy(node->student_name,maken1);
                        }else if(strcmp(hang[ke],"密码")==0){
                            strcpy(node->password,maken1);
                        }
                    }
                }
                maken1=strtok(NULL,s1);
                ke++;
            }
            if(node!=NULL){
                if(head1==NULL){
                    head1=node;
                    mnb1=node;
                }else{
                    mnb1->next1=node;
                    mnb1=node;
                }
            }
            token1=strtok_r(NULL,"\n",&saveptr1);
            num1++;
        }
        for(int i=0; i<4; i++) {
		    printf("%s\t", hang[i]);
	    }
	    printf("\n");

        Student *p1 = head1;
        while(p1 != NULL) {
            printf("%s\t%s\t%s\n",p1->student_id, p1->student_name, p1->password);
            p1= p1->next1;
        }  
    }else if(j==2){
        Admin *head2=NULL;
        Admin *mnb2=NULL;
        char *token2;
        char *saveptr2;
        char lie[5][100];
        int num2=0;
        token2=strtok_r(data,"\n",&saveptr2);
        while(token2!=NULL){
            Admin *node1=NULL;
            if(num2>0){
                node1=(Admin*)malloc(sizeof(Admin));
                node1->next2=NULL;
            }
            char *maken2;
            const char s2[2]=",";
            int je=0;
            maken2=strtok(token2,s2);
            while(maken2!=NULL){
                if(num2==0){
                    strcpy(lie[je],maken2);
                }else{
                    if(node1!=NULL){
                        if(strcmp(lie[je],"账号")==0){
                            strcpy(node1->account,maken2);
                        }else if(strcmp(lie[je],"姓名")==0){
                            strcpy(node1->admin_name,maken2);
                        }else if(strcmp(lie[je],"密码")==0){
                            strcpy(node1->admin_password,maken2);
                        }
                    }
                }
                maken2=strtok(NULL,s2);
                je++;
            }
            if(node1!=NULL){
                if(head2==NULL){
                    head2=node1;
                    mnb2=node1;
                }else{
                    mnb2->next2=node1;
                    mnb2=node1;
                }
            }
            token2=strtok_r(NULL,"\n",&saveptr2);
            num2++;
        }
        for(int i=0;i<4;i++){
            printf("%s\t",lie[i]);
        }
        printf("\n");
        Admin *p2=head2;
        while(p2!=NULL){
            printf("%s\t%s\t%s\n",p2->account,p2->admin_name,p2->admin_password);
            p2=p2->next2;
        }
    }
return 0;
}