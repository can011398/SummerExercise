#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE *pfile;
    char *data;
    char path[50];
    scanf("%s",path);
    int *length;
    pfile=fopen(path,"r");
    if(pfile==NULL){
        printf("NULL");
    }
    fseek(pfile,0,SEEK_END);
    *length=ftell(pfile);
    data=(char*)malloc((*length+1)*sizeof(char));
    rewind(pfile);
    length=fread(data,1,*length,pfile);
    data[*length]='\0';
    int fcolse(pfile);
    printf("%s",data);
}