#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h> 


int main(){
    while(1){
        char command[50];
        scanf("%s", command);
        system(command);
    }
    return 0;
}