#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int cnt = 0;

#define MAX_MESSAGE_SIZE 1024

void *f(void *arg){
    for (int i = 0; i < 5000; i++){
        cnt += 1;
    }
    return NULL;
}

int main(int argc, char *argv[]){
    char *myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);
    
    pid_t publisher = fork();
    pid_t subscriber = fork();

    if (publisher > 0 && subscriber == 0){
        while (1){
            char str[MAX_MESSAGE_SIZE];
            int fd = open(myfifo, O_WRONLY);
            fgets(str, MAX_MESSAGE_SIZE, stdin);
            write(fd, str, strlen(str) + 1);
        }
       
    }
    
    if (subscriber > 0 && publisher == 0){
        while (1){
            int fd = open(myfifo, O_RDONLY);
            char str[MAX_MESSAGE_SIZE];
            read(fd, str, MAX_MESSAGE_SIZE);
            printf("recieved message - %s\n", str);
            close(fd);
        }
    }
    while (1) {};
    return 0;
}