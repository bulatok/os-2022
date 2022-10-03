#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 1024

int main(){
    char *myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);

    int fd;
    

    while(1){
        fd = open(myfifo, O_WRONLY);

        char str[MAX_MESSAGE_SIZE];
        
        printf("message - ");
        fgets(str, MAX_MESSAGE_SIZE, stdin);
        write(fd, str, strlen(str) + 1);
        printf("\n");
        
        close(fd);
    }
    return 0;
}