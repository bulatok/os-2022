#include <stdio.h>

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){
    if (size == sizeof(int)){
        int *a = (int*) base;
        int* res = (int*) initial_value;
        int w = *res;
        for (int i = 0; i < n; i++){
            const int *v1 = &a[i];
            const int tmp = w;
            const int *v2 = &tmp;
            const int* out = (int*) opr((void*) v1, (void*) v2);
            w = *out;
        }
        const int tmp = w;
        void* any = (void*) &tmp;
        return any;
    }else if (size == sizeof(double)){
        double *a = (double*) base;
        double* res = (double*) initial_value;
        double w = *res;
        for (int i = 0; i < n; i++){
            const double *v1 = &a[i];
            const double tmp = w;
            const double *v2 = &tmp;
            const double* out = (double*) opr((void*) v1, (void*) v2);
            w = *out;
        }
        const double tmp = w;
        void* any = (void*) &tmp;
        return any;
    }
}
void *addition_ints(const void* x, const void* y){
    int* x_val = (int*) x;
    int* y_val = (int*) y;
    const int res = (*x_val + *y_val);
    void* any = (void*) &res;
    return any;
}

void *multi_ints(const void* x, const void* y){
    int* x_val = (int*) x;
    int* y_val = (int*) y;
    const int res = (*x_val * *y_val);
    void* any = (void*) &res;
    return any;
}

void *arithmetic_ints(const void* x, const void* y){
    int* x_val = (int*) x;
    int* y_val = (int*) y;
    const int res = (*x_val + *y_val) / 2;
    void* any = (void*) &res;
    return any;
}

void *arithmetic_double(const void* x, const void* y){
    double* x_val = (double*) x;
    double* y_val = (double*) y;
    
    const double res = (*x_val + *y_val) / 2.0;
    void* any = (void*) &res;
    return any;
}

void *addition_double(const void* x, const void* y){
    double* x_val = (double*) x;
    double* y_val = (double*) y;
    const double res = (*x_val + *y_val);
    void* any = (void*) &res;
    return any;
}

void *multi_double(const void* x, const void* y){
    double* x_val = (double*) x;
    double* y_val = (double*) y;
    const double res = (*x_val * *y_val);
    void* any = (void*) &res;
    return any; 
}



int main(void){
    int arrays_len = 5;
    const int init_val_1 = 0;
    const int init_val_2 = 1;
    const double init_val_2_dbl = 1.0;
    size_t size_int = sizeof(int);
    size_t size_double = sizeof(double);

    double dbls[5] = {0.5, 0.5, 0.5, 0.5, 0.5};
    int ints[5] = {1, 2, 3, 4, 5};

    printf("arrays of int: ");
    for (int i = 0; i < arrays_len; i++){
        printf("%d ", ints[i]);
    }
    printf("\n");
    int *res1 = (int*) aggregate (ints, size_int, arrays_len, (void* ) &init_val_1, addition_ints);;
    printf("addition of int array: %d\n", *res1);

    int *res2 = (int*) aggregate (ints, size_int, arrays_len, (void* ) &init_val_2, multi_ints);;
    printf("multi of int array: %d\n", *res2);

    int *res3 = (int*) aggregate (ints, size_int, arrays_len, (void* ) &init_val_1, arithmetic_ints);;
    printf("arithmetic of int array: %d\n", *res3);

    printf("\n");

    printf("arrays of double: ");
    for (int i = 0; i < arrays_len; i++){
        printf("%f ", dbls[i]);
    }
    printf("\n");
    double *res4 = (double*) aggregate (dbls, size_double, arrays_len, (void* ) &init_val_1, addition_double);;
    printf("addition of double array: %f\n", *res4);

    double *res5 = (double*) aggregate (dbls, size_double, arrays_len, (void* ) &init_val_2_dbl, multi_double);;
    printf("multi of double array: %f\n", *res5);

    double *res6 = (double*) aggregate (dbls, size_double, arrays_len, (void* ) &init_val_1, arithmetic_double);;
    printf("arithmetic of double array: %f\n", *res6);

    return 0;
}