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
        char str[MAX_MESSAGE_SIZE];
        fgets(str, MAX_MESSAGE_SIZE, stdin);
        fd = open(myfifo, O_WRONLY);
        for (int i = 0; i < n; i++){
            write(fd, str, strlen(str) + 1);
        }
        close(fd);
    }
    return 0;
}