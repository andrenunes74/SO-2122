//cliente

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char * myfifo1 = "/tmp/myfifoStoC";
    char * myfifo2 = "/tmp/myfifoCtoS"; 

    //buffers
    char arr1[80];
    char arr2[80];

    int fd = open(myfifo1, O_RDONLY);
    int n = read(fd, arr1, sizeof(arr1));
    close(fd);

    char *str = calloc(strlen(arr1)+1, sizeof(char));
    strcpy(str,arr1);
    str[n] = '\0';

    write(1,str,strlen(str));

    int fd2 = open(myfifo2, O_WRONLY);
    int x = read(0,arr2,sizeof(arr2));
    arr2[x]='\0';
    write(fd2,arr2,strlen(arr2));
    close(fd2);
    

    

    return 0;
}
