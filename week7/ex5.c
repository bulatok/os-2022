#include <stdio.h>
#include <stdlib.h>
int main()
{
    char **s = malloc(1 * sizeof(char**));
    char foo[] = "Hello World"; 
    *s = foo;
    printf("s is %s \n", *s);
    printf("s[0] is %c \n", (*s)[0]);
    return 0;
}