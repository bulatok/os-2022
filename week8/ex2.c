#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    void *mem[10];
    for (int i = 0; i < 10; i++){
        mem[i] = malloc(10 * 1024 * 1024 * sizeof(char)); // allocating 10 MB memory
        memset(mem[i], 0, 10 * 1024 * 1024 * sizeof(char));
        sleep(1);
    }
    for (int i = 0; i < 10; i++){
        free(mem[i]);
    }
    return 0;
}