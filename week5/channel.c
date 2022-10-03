#include <stdio.h>
#include <pthread.h>

int cnt = 0;

void *f(void *arg){
    for (int i = 0; i < 5000; i++){
        cnt += 1;
    }
    return NULL;
}

int main(){
    char *myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);
    
}