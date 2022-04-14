//servidor

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    // FIFO file path
    char * myfifo1 = "/tmp/myfifoStoC"; //server to client
    char * myfifo2 = "/tmp/myfifoCtoS"; //client to server

    // Creating the named file(FIFO)
    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);

    //buffers
    char arr1[80];
    char arr2[40];

    
    int fd1 = open(myfifo1, O_WRONLY);
    int n = read(0,arr1,sizeof(arr1));

    char *str = calloc(strlen(arr1)+1, sizeof(char));
    strcpy(str,arr1);
    str[n] = '\0';

    //escreve o que le do stdin no pipe s to c 
    write(fd1,str,strlen(str));
    close(fd1);

    int fd2 = open(myfifo2, O_RDONLY);
    int x = read(fd2, arr2, sizeof(arr2));
    close(fd2);
    arr2[x]='\0';
    write(1,arr2,strlen(arr2)+1);
    


    return 0;
}
