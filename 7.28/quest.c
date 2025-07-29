 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COURSE_FILE "./course.txt"
#define STUDENT_FILE "./student.txt"
#define ADMIN_FILE "./admin.txt"

typedef struct ids{
    char id[20];
    struct ids *next;
}IDS;

typedef struct user{
    char account[20];
    char password[20];
    char id[20];
    int is_admin;
    int course_sum;
    struct user *next;
    IDS *course;
} User;

typedef struct course{
    char id[20];
    char course_name[100];
    char teacher_name[100];
    int max_student_num;
    int choose_sum;
    struct course *next;
    IDS *students;
} Course;

char *READFILE(char *path){
    FILE *pfile;
    char *data;
    long length;
    pfile = fopen(path,"r");
    if (pfile == NULL){
        return NULL;
    }
    fseek(pfile,0,SEEK_END);
    length = ftell(pfile);
    data = (char *)malloc((length+1)*sizeof(char));
    rewind(pfile);
    length = fread(data,1,length,pfile);
    data[length] = '\0';
    fclose(pfile);
    return data;
}


Course *parse_course(char *data){
    char order[4][100];
    Course *head=NULL;
    Course *cur=NULL;
    char *token;
    char *saveptr;
    int index = 0;
    token = strtok_r(data,"\n",&saveptr);
    while(token!=NULL){
        char *maken;
        char *saveptr1;
        int x=0;
        Course *node = NULL;
        if(index>0){
            node = (Course*)malloc(sizeof(Course));
            node->next=NULL;
        }
        maken=strtok_r(token,",",&saveptr1);
        while(maken!=NULL){
            if(index==0){
                strcpy(order[x],maken);
            }else{
                if(node!=NULL){
                    if(strcmp(order[x],"课程编号")==0){
                        strcpy(node->id,maken);
                    }else if(strcmp(order[x],"任课教师")==0){
                        strcpy(node->teacher_name,maken);
                    }else if(strcmp(order[x],"课程名称")==0){
                        strcpy(node->course_name,maken);
                    }else if(strcmp(order[x],"最大容纳人数")==0){
                        node->max_student_num=atoi(maken);
                    }
                }
            }
            maken = strtok_r(NULL,",",&saveptr1);
            x++;
        }
        if(node!=NULL){
            if(head == NULL){
                head = node;
                cur = node;
            }else{
                cur->next = node;
                cur = cur->next;
            }

        } 
        token = strtok_r(NULL,"\n",&saveptr);
        index++;       
    }
    return head;
}



User *parse_user(char *data){
    User *head = NULL; 
    User *cur = NULL;
    char *token;
    char *saveptr;
    char order[4][100];
    int index = 0;
    token = strtok_r(data,"\n",&saveptr);
    while(token!=NULL){
        User *node = NULL;
        if(index>0){
            node=(User*)malloc(sizeof(User));
            node->next=NULL;
        }
        char *maken;
        char *saveptr1;
        int x=0;
        maken=strtok_r(token,",",&saveptr1);
        while(maken!=NULL){
            if(index==0){
                strcpy(order[x],maken);
            }else{
                if(node!=NULL){
                    if(strcmp(order[x],"学号")==0){
                        strcpy(node->account,maken);
                        node->is_admin = 1;
                    }else if(strcmp(order[x],"密码")==0){
                        strcpy(node->password,maken);
                    }else if(strcmp(order[x],"编号")==0){
                        strcpy(node->id,maken);
                    }else if(strcmp(order[x],"账号")==0){
                        strcpy(node->account,maken);
                        node->is_admin = 0;
                    }else if(strcmp(order[x],"ID")==0){
                        strcpy(node->id,maken);
                    }
                }
            }
            maken=strtok_r(NULL,",",&saveptr1);
            x++;
        }
        if(node!=NULL){
            if(head==NULL){
                head=node;
                cur=node;
            }else{
                cur->next=node;
                cur=node;
            }
        }
        token=strtok_r(NULL,"\n",&saveptr);
        index++;
    }
    return head;
}


int function_choose(){
    printf("welcome to class system\n");
    printf("1.init system\n");
    printf("2.print information\n");
    int index;
    scanf("%d",&index);
    return index;
}

int init(Course **course_head,User **user_head){
    printf("begin read file\n");
    char *content;
    content=READFILE(COURSE_FILE);
    *course_head=parse_course(content);
    free(content);
    content=READFILE(STUDENT_FILE);
    User *student_head=parse_user(content);
    free(content);
    content=READFILE(ADMIN_FILE);
    User *admin_head=parse_user(content);
    User *tail=student_head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next = admin_head;
    *user_head=student_head;
    return 0;

}


int main() {
    Course *course_head = NULL;
    User *user_head = NULL;
    // int num = 3;
    while(1) {
        int choice = function_choose();
        if(choice == 1) {
            init(&course_head, &user_head);
        } else if(choice == 2) {
            Course *cur = course_head;
            printf("------\nCourse Info:\n");
            while(cur != NULL) {
                printf("ID: %s, Name: %s, Teacher: %s, Max Students: %d\n", 
                       cur->id, cur->course_name, cur->teacher_name, cur->max_student_num);
                cur = cur->next;
            }
            printf("------\nUser Info:\n");
            User *user_cur = user_head;
            while(user_cur != NULL) {
                printf("ID: %s, Name: %s, Password: %s, Is Admin: %d\n", 
                       user_cur->id, user_cur->account, user_cur->password, user_cur->is_admin);
                user_cur = user_cur->next;  
            }
        }
    }
    return 0;
}