#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("n - ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
}
