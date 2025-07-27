#include <stdio.h>

typedef struct text{
    char account[100];
    char password[100];
    struct text *next;

}test;


int mian(){
    char a[100];
    char b[100];
    printf("请输入账号");
    scanf("%s",&a[100]);
    printf("请输入密码");
    scanf("%s",&b[100]);
    test *p;
    while(p!=NULL){
        p=p->next;
        if(strcmp(p->account,a[100])==0&&strcmp(p->password)==0){
            printf("登录成功");
        }else{
            printf("账号或密码错误");
        }
    }
}