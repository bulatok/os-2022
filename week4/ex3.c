#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h> 


int main(int argc, char* argv[]){
    int n;
    for (int i = 0;i<argc;i++){
        n = atoi(argv[i]);
    }

    for (int i = 0; i < n; i++){
        fork();
        sleep(5);
    }
    return 0;
}