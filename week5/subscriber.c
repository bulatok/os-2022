#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_MESSAGE_SIZE 1024

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    char *myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);
    int fd;
    while(1){
        fd = open(myfifo, O_RDONLY);
        char str[MAX_MESSAGE_SIZE];

        for (int i = 0; i < n; i++){
            read(fd, str, MAX_MESSAGE_SIZE);
            printf("recieved message - %s\n", str);
        }
        close(fd);
    }
    return 0;
}