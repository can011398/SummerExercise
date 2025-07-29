#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ids{
    char id[10];
    struct ids *next;
}IDS;




typedef struct user{
    char account[20];
    char password[20];
    struct user *next;
    char is_admin;
    int course_sum;
    char id[20];
    IDS *course;
}User;


typedef struct course{
    char course_name[20];
    struct course *next;
    char id[10]; 
    int choose_num;
    char course_teacher[20];
    int max_student_sum;
    int free_num;
    IDS *students;

}Course;


typedef struct ids{
    char id[10];
    struct ids *next;
}IDS;


void show_course(Course *head,User *info, int only_show_choose){
    Course *p=head;
    IDS *temp=NULL;
    if(info=NULL){
        while(p!=NULL){
            printf("%s,%s,%s,%d",p->course_name,p->id,p->course_teacher,p->max_student_sum);
            p=p->next;
        }
    }else if(info!=NULL&&only_show_choose==1){
        temp=info->course;
        printf("%s",temp->id);
        temp=temp->next;
    }else if(info!=NULL&&only_show_choose==0){

    }


}

int select_course(Course *head,User *info){
    
}
int unselect_course(Course *head,User *info){

}






int login(User *head,User **info){
    printf("账号");
    char account[20];
    scanf("%s",account);
    printf("密码");
    char password[20];
    scanf("%s",password);
    User *p=head;
    while(p->next!=NULL){
        if((strcmp(p->password,password)!=0)&&strcmp(p->account,account)!=0){
            *info=p;
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



void show_course_detail(Course *head, char *id, User *user_head) {
    Course *p=head;
    while(p!=NULL){
        if(strcmp(p->id,id)==0){
            printf("%s,%s,%s,%s",p->choose_num,p->course_name,p->course_teacher,p->max_student_sum);
            break;
        }

        p=p->next;
    }

}
void add_course(Course *head) {
    Course *p=head;
    Course *new=(Course*)malloc(sizeof(Course));
    while(p!=NULL){
        if(p->next==NULL){
            p->next=new;
            scanf("%s,%s,%s,%s",new->choose_num,new->course_name,new->course_teacher,new->next);
            new->next=NULL;
            break;
        }
        p=p->next;
    }

}


void delete_course(Course *head, char *id, User *user_head) {

}

void add_student(User *user_head) {
    User *p=user_head;
    User *new=(User*)malloc(sizeof(User));
    while(p!=NULL){
        if(p->next==NULL){
            p->next=new;
            scanf("%s,%s,%s,%s",new->account,new->course,new->course_sum,new->password);
            break;
        }
    }

}


void delete_student(User *user_head, Course *course_head, char *id) {

}
 