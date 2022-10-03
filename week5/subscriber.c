#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 1024

int main(){
    char *myfifo = "/tmp/ex1";
    int fd;
    while(1){
        fd = open(myfifo, O_RDONLY);
        char str[MAX_MESSAGE_SIZE];
        read(fd, str, MAX_MESSAGE_SIZE);
        
        pritnf("message - %s\n", str);
        close(fd);
    }
    return 0;
}