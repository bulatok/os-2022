#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 

int main(void){
    pid_t main_pid = getpid();
    clock_t tmain = clock();

    pid_t pros1 = fork();
    clock_t t1 = clock();

    pid_t pros2 = fork();
    clock_t t2 = clock();

    if (pros1 > 0 && pros2 > 0){
        printf("main processes, pid = %d, exec time=%f milliseconds\n", main_pid, ((float)tmain) / CLOCKS_PER_SEC * 1000);
        return 0;
    }
    if (pros1 > 0 && pros2 == 0){
        printf("prosses1, pid=%d, parent pid=%d, exec time=%f milliseconds\n", pros1, main_pid, ((float)t1) / CLOCKS_PER_SEC * 1000);
    }
    if (pros2 > 0 && pros1 == 0){
        printf("prosses2, pid=%d, parent pid=%d, exec time=%f milliseconds\n", pros2, main_pid, ((float)t2) / CLOCKS_PER_SEC * 1000);
    }

    return 0;
}