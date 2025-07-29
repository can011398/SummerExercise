#include <stdio.h>
typedef struct user{
    char account[20];
    char password[20];
    struct user *next;
}User;


typedef struct course{
    char course_name[20];
    struct course *next;
    char id[10]; 
}Course;


typedef struct ids{
    char ID[10];
    struct ids *next;
}IDS;


int login(User *head){
    printf("账号");
    char account1[20];
    scanf("%s",account1);
    printf("密码");
    char password1[20];
    scanf("%s",password1);
    User *p=head;
    while(p->next!=NULL){
        if((strcmp(p->password,password1)!=0)&&strcmp(p->account,account1)!=0){
            return 0;
        }
        p=p->next;
    }
}




int find_course_node(Course *head,Course **node, Course **last_node,char *id){
    Course *p=head;
    while(p->next!=NULL){
        if(strcmp(p->next->id,id)==0){
            *last_node=p;
            *node=p->next;
            return 0;
        }
        p=p->next;
    }
}


int find_user_node(User *head,User **node,User **last_node,char *id){
    Course *p=head;
    while(p->next!=NULL){
        if(strcmp(p->next->id,id)==0){
            *last_node=p;
            *node=p->next;
            return 0;
        }
        p=p->next;
    }
}


int find_id_node(IDS *head,IDS **node,IDS**last_node,char *id){
    Course *p=head;
    while(p->next!=NULL){
        if(strcmp(p->next->id,id)==0){
            *last_node=p;
            *node=p->next;
            return 0;
        }
        p=p->next;
    }
}
