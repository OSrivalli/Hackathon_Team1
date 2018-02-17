#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int i;
    char buff[30];
    if (argc < 2 || argc > 3)
    {
        printf("enter 2 arguments only eg.\" image_path ratio\"");
        return 0;
    }
    i = atoi(argv[2]);
    printf("\narg1 :%s \t arg2 %d\n",argv[1],i);
	printf("Executing python file");
    strcpy(buff,"python hello.py ");
    strcat(buff,argv[1]);
    strcat(buff," ");
    strcat(buff,argv[2]);
    printf("\n%s",buff);
	system(buff);
	return 0;
}

