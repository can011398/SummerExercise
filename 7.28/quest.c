#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct ids{
    char id[20];
    struct ids *next;
}IDS;


int READFILE(char *path,char **data){
    FILE *pfile;
    long length;
    pfile = fopen(path,"r");
    if (pfile == NULL){
        return 1;
    }
    fseek(pfile,0,SEEK_END);
    length = ftell(pfile);
    *data = (char *)malloc((length+1)*sizeof(char));
    rewind(pfile);
    length = fread(*data,1,length,pfile);
    (*data)[length] = '\0';
    fcolse(pfile);
    return 0;
}

char  *parse_couse(char **data,char **content){
    char order[4][100];
    Course *head=NULL;
    Course *cur=NULL;
    char *token;
    char *saveptr;
    int index = 0;
    token = strtok_r(*data,'\n',&saveptr);
    while(token!=NULL){
        char *maken;
        char *saveptr1;
        int x=0;
        Course *node = NULL;
        if(index>0){
            node = (Course*)malloc(sizeof(char));
            node->next=NULL;
        }
        maken=(token,',',&saveptr1);
        while(maken!=NULL){
            if(index==0){
                strcpy(order[x],maken);
            }else{
                if(node!=NULL){
                    if(strcmp(order[x],"课程编号")==0){
                        strcpy(node->id,maken);
                    }else if(strcmp(order[x],"任课教师")){
                        strcpy(node->teacher_name,maken);
                    }else if(strcmp(order[x],"课程名称")){
                        strcpy(node->course_name,maken);
                    }else if(strcmp(order[x],"最大容纳人数")){
                        node->max_student_num=atoi(maken);
                    }
                }
            }
            maken = strtok_r(NULL,",",&saveptr1);
            x++;
        }
        if(node!=NULL){
            if(head = NULL){
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
    content = head;
    return content;
}



char *parse_user(char **content,char **data){
    User *head = NULL;
    User *cur = NULL;
    char *token;
    char *saveptr;
    char order[3][100];
    int index = 0;
    token = strtok_r(data,"\n",&saveptr);
    while(token!=NULL){
        User*node = NULL;
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
                        strcpy(node->is_admin,'1');
                    }else if(strcmp(order[x],"密码")==0){
                        strcpy(node->password,maken);
                    }else if(strcmp(order[x],"编号")==0){
                        strcpy(node->id,maken);
                    }else if(strcmp(order[x],"账号")==0){
                        strcpy(node->account,maken);
                        strcpy(node->is_admin,'0');
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
        token=strtok_r(NULL,"\n",&saveptr1);
        index++;
    }content=head;
    return content;
}


int function_choose(){
    printf("welcome to class system\n");
    printf("1.init system\n");
    printf("2.print information\n");
    int index;
    scanf("%d",&index);
    return index;
}

int init(char **path,char **data){
    printf("begin read file\n");
    char *content;
    READFILE(path,*data);
    par_course(*data,*content);
    free(content);
    READFILE(path,*data);
    parse_user(*content,*data);
    return 0;
}


int main(){
    int a=function_choose;
    char *path;
    char *data;
    scanf("%s",&path);
    if(a==1){
        init(*path,*data);
    }
}