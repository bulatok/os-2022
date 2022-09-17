#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int *a, int l, int r) {
    int pivot = a[r]; // pivot element is just right most element (this is not inefficient sometimes).
    int i = (l - 1);
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return (i + 1);
}

void QuickSort(int *a, int l, int r){
    if (l < r){
        int pivot = partition(a, l, r);
        QuickSort(a, l, pivot - 1);
        QuickSort(a, pivot+1, r);
    }
}

void fill_array(int *a, int n){
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < n; i++){
        a[i] = rand() % 20;
    }
}
int main(void){
    const int n = 5;
    int* a= malloc(sizeof(int) * n);

    // filling with random elements;
    fill_array(a, n);

    // before
    printf("before: ");
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    // sorting...
    QuickSort(a, 0, n-1);

    // after
    printf("after: ");
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}