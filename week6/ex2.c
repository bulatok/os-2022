#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h> 

struct MyPros
{
    int arrive_time;
    int burst_time;

    int ct_time;
    int tat_time;
    int wt_time;
};

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(int argc, char *argv[]){
    int n;
    double avg_tat = 0;
    double avg_wt = 0;

    printf("n - ");
    scanf("%d", &n);

    struct MyPros a[n];
    for (int i = 0; i < n; i++){
        printf("arrival time for pros %d - ", i);
        scanf("%d", &a[i].arrive_time);
        printf("burst time for pros %d - ", i);
        scanf("%d", &a[i].burst_time);
        printf("\n");
        
    }
    
    // sorting by arrival time...
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n-i-1; j++){
                if (a[j].arrive_time > a[j+1].arrive_time){
                    swap(&a[j].arrive_time, &a[j+1].arrive_time);
                }
            }
        }
    }

    // sorting by burst time (keeping in mind the preveous sorting)
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n-i-1; j++){
                if (a[j].burst_time > a[j+1].burst_time){
                    if (a[j].arrive_time >= a[j+1].arrive_time){
                        swap(&a[j].arrive_time, &a[j+1].arrive_time);
                        swap(&a[j].burst_time, &a[j+1].burst_time);
                    }
                }
            }
        }
    }
    


    // ------------------------------------------------------------------------------
    // for (int i = 0; i < n;i++){
    //     printf("%d) burst-%d, arrival_time-%d\n", i, a[i].burst_time, a[i].arrive_time);
    // }
    printf("\n");
    // Completion time(CT)
    {
        a[0].ct_time = a[0].arrive_time + a[0].burst_time;
        for (int i = 1; i < n; i++){
            int tmp = 0;
            if (a[i-1].ct_time < a[i].arrive_time){
                tmp = a[i].arrive_time - a[i].ct_time;
            }
            a[i].ct_time = a[i-1].ct_time + a[i].burst_time + tmp;
        }
        for (int i=0;i<n;i++){
           printf("CT for pros %d - %d\n", i, a[i].ct_time);
        }
        printf("\n");
    }

    // Turn around time(TAT) for each process
    {
        for (int i = 0; i < n; i++){
            a[i].tat_time = a[i].ct_time - a[i].arrive_time;
            avg_tat += (double)a[i].tat_time;
        }
        for (int i=0;i<n;i++){
           printf("TAT for pros %d - %d\n", i, a[i].tat_time);
        }
        avg_tat /= (double)n;
        printf("\n");
    }

    // Waiting time(WT) for each process
    {
        for (int i = 0; i < n; i++){
            a[i].wt_time = a[i].tat_time - a[i].burst_time;
            avg_wt += (double)a[i].wt_time;
        }
        for (int i=0;i<n;i++){
           printf("WT for pros %d - %d\n", i, a[i].wt_time);
        }
        avg_wt /= (double)n;
        printf("\n");
    }

    {
        printf("Average Turnaround time - %f\n", avg_tat);
        printf("Average waiting time - %f\n", avg_wt);
    }

}