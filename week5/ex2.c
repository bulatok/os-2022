#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

struct Thread
{
    pthread_t id;
    int i;
    char message[256];
};

void *f(void *x){
    struct Thread *t = (struct Thread *) x;
    printf("Thread id=`%ld`, message=`%s`\n", t->id, t->message);
    printf("Thread %d exists\n\n", t->i);
}
int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);
    struct Thread arr[n];
    for (int i = 0; i < n; i++){
        arr[i].i = i;
        sprintf(arr[i].message, "Hello from thread %d", i);

        pthread_create(&arr[i].id, NULL, f, (void *)&arr[i]);
        printf("Thread %d is created\n", i);
        pthread_join(arr[i].id, NULL);
    } 
    pthread_exit(NULL);
}