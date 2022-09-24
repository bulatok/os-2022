#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 
#include <sys/wait.h>

#define N 120

void fill_array(int *a, int n){
    time_t t;
    sleep(1);
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        a[i] = rand() % 100;
    }
}

// dot_product [from, to)
int dot_product(int *a, int *b, int from, int to){
    int res = 0;
    for (int i = from; i < to; i++){
        res += a[i] * b[i]; 
    }
    return res;
}
int main(void){
    int u[N];
    int v[N];
    fill_array(u, N);
    fill_array(v, N);
    
    int n; 
    printf("n = ");
    scanf("%d", &n);

    int step = N / n;

    FILE *fw = fopen("temp.txt", "w");

    pid_t wpid;
    int status;
    
    for (int i = 0; i < n; i++){
        pid_t pid = fork();
        int from = i * step;
        int to = (i+1) * step;
        if (pid == 0){
            int res = dot_product(u, v, from, to);
            char str[20];
            sprintf(str, "%d", res);
            fprintf(fw, "%s", str);
            fprintf(fw, "\n");
            exit(0);
        }else if(pid < 0){
            printf("error with prcoses %d\n", pid);
            exit(0);
        }
        else{
            // exit(0);
        }
    }

    while ((wpid = wait(&status)) > 0);
    fclose(fw);
    
    FILE *fr = fopen("temp.txt", "r");
    int res = 0;
    if (fr){
        char line[50];
        while(fgets(line, sizeof(line), fr)){
            int num = atoi(line);
            res += num;
        }
        fclose(fr);
    }else{
        printf("could not open file");
        exit(0);
    }
    printf("dot product = %d\n", res);
    return 0;
}