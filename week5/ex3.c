#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int is_prime(int n){
    if (n <= 1)
        return 0;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
        return 0;
    return 1;
}

int primes_count_in_interval(int start, int finish)
{
    int ret = 0;
    for (int i = start; i < finish; i++)
        if (is_prime(i) != 0)
        ret++;
    return ret;
}

typedef struct prime_counter_request
{
  int start, finish;
} prime_counter_request;

void *prime_counter(void *arg){
    prime_counter_request *req = (prime_counter_request* ) arg;
    int res = 0;
    for (int i = req->start; i < req->finish; i++){
        res += is_prime(i);
    }
    return (void *)res;
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]), n_threads = atoi(argv[2]);
    int segment_size = n / n_threads;
    
    pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

    prime_counter_request *requests = malloc(n_threads * sizeof(prime_counter_request));

    void **results = malloc(n_threads * sizeof(void *));

    for (int i = 0; i < n_threads; i++){
        prime_counter_request *req = malloc(sizeof(prime_counter_request));
        req->start = i * segment_size;
        req->finish = (i+1) * segment_size;
        if (i == n_threads - 1) req->finish = req->finish + 1;
        pthread_create(&threads[i], NULL, prime_counter, (void *)req);
    }

    for (int i = 0; i < n_threads; i++){
        pthread_join(threads[i], (void **)&results[i]);
    }

    int total_result = 0;
    for (int i = 0; i < n_threads; i++){
        int *val = (int *)results[i];
        total_result += (int) val;
    }
    
    printf("result=%d\n", total_result);
    free(results);
    free(requests);
    
    exit(EXIT_SUCCESS);
}