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
    int n, q;
    double avg_tat = 0;
    double avg_wt = 0;

    printf("n - ");
    scanf("%d", &n);
    printf("q - ");
    scanf("%d", &q);


    struct MyPros a[n];
    int tmp_burst[n];
    for (int i = 0; i < n; i++){
        printf("arrival time for pros %d - ", i);
        scanf("%d", &a[i].arrive_time);
        printf("burst time for pros %d - ", i);
        scanf("%d", &a[i].burst_time);
        printf("\n");
        
        a[i].wt_time = 0;         
    }
    
    // sorting by arrival time...
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n-i-1; j++){
                if (a[j].arrive_time > a[j+1].arrive_time){
                    swap(&a[j].arrive_time, &a[j+1].arrive_time);
                    swap(&a[j].burst_time, &a[j+1].burst_time);
                }
            }
        }
    }
    {
        for (int i = 0; i<n;i++){
            tmp_burst[i] = a[i].burst_time;
        }
    }
    // ------------------------------------------------------------------------------
    
    printf("\n");
    int sm = 0;
    int i2 = n;
    int cnt = 0;
    int wt = 0;
    int tat = 0;
    int t = 0;
    for (int i = 0; i2 != 0;){
        if (tmp_burst[i] <= q && tmp_burst[i] > 0){
            sm += tmp_burst[i];
            tmp_burst[i] = 0;
            cnt = 1;
        }else if(tmp_burst[i] > 0){
            tmp_burst[i] -= q;
            sm += q;
        }

        if (tmp_burst[i] == 0 && cnt == 1){
            i2--;
            
            a[i].tat_time = sm - a[i].arrive_time;
            
            a[i].wt_time = sm - a[i].arrive_time - a[i].burst_time;
            if (a[i].wt_time < 0){ // the first one which does not wait anyone
                a[i].wt_time = 0;
            }
            
            wt  += sm - a[i].tat_time - a[i].burst_time;  
            tat += sm - a[i].arrive_time;  
            cnt = 0; 
        }

        if(i == n-1){  
            i=0;  
        }else if(a[i+1].arrive_time <= sm){  
            i++;
        }else{  
            i=0;  
        } 
    }
    
    // Turn around time(TAT) for each process
    {
        for (int i = 0; i < n;i++){
            printf("TAT for pros %d - %d\n", i, a[i].tat_time);
            avg_tat += (double) a[i].tat_time;
        }
        avg_tat /= (double)n;
        printf("\n");
    }

    // Waiting time(WT) for each process
    {   
        for (int i=0;i<n;i++){
           printf("WT for pros %d - %d\n", i, a[i].wt_time);
           avg_wt += (double) a[i].wt_time;
           t += a[i].wt_time;
           t += a[i].burst_time;
        }
        avg_wt /= (double)n;
        printf("\n");
    }

    {
        printf("Completion time(CT) - %d\n", t);
        printf("Average Turnaround time - %f\n", avg_tat);
        printf("Average waiting time - %f\n", avg_wt);
    }

}