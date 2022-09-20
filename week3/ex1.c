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

    const int *const p = malloc(5 * sizeof(const int)); // acording to task description
    int *p_not_const = p;
    for (int i = 0; i < 5; i++){
        p_not_const[i] = x;
    }

    for (int i = 0; i < 5; i++){
        printf("%p ", p_not_const + i);
    }
    printf("\n");


    for (int i = 0; i < 5; i++){
        int age;
        printf("age: ");
        scanf("%d", &age);
        p_not_const[i] = age;
    }
    printf("\n");

    for (int i = 0; i < 5; i++){
        p_not_const[i] = foo(p[i]);
    }
    
    for (int i = 0; i < 5; i++){
        printf("birth year: %d\n", p[i]);
    }

    free(p_not_const);
    return 0;
}