#include <stdio.h>
#include <stdlib.h>

int foo(int age){
    const int curYear = 2022;
    return curYear - age;
}

int main(void){
    const int x = 10;
    const int* q = &x;
    printf("%d\n", *q);

    int *const p = malloc(5 * sizeof(const int));
    for (int i = 0; i < 5; i++){
        p[i] = x;
        *(p + i) = x;
    }

    for (int i = 0; i < 5; i++){
        printf("%p ", &p[i]);
    }
    printf("\n");


    for (int i = 0; i < 5; i++){
        int age;
        printf("age: ");
        scanf("%d", &age);
        p[i] = age;
    }
    printf("\n");

    for (int i = 0; i < 5; i++){
        p[i] = foo(p[i]);
    }
    
    for (int i = 0; i < 5; i++){
        printf("birth year: %d\n", p[i]);
    }

    free(p);
    return 0;
}