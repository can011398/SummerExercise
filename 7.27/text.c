#include <stdio.h>
#include <stdlib.h>

int readfile (char *path, char **data){
    FILE *pfile;
    long length;
    pfile = fopen(path,"r");
    if(pfile==NULL){
        return 1;
    }
    fseek(pfile, 0, SEEK_END);
    length=ftell(pfile);
    *data =(char*)malloc((length+1)*sizeof(char));
    rewind(pfile);
    length = fread(*data,1,length,pfile);
    (*data)[length]='\0';
    fclose(pfile);
    // printf("%s", *data);    
    return 0;
    
}

void add(int *a) {
    *a = *a + 1;
}

int main(){
    char *path="./course.txt";
    char *data=NULL;
    int a=readfile(path, &data);
    printf("%s",data);

    int num = 1;
    add(&num);
    printf("%d\n", num);
    return 0;
}