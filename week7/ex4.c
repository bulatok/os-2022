#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}
void *realloc(void *ptr, size_t size, size_t old_size)
{
    if (ptr == NULL)
        return malloc(size);
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(size);
    new_ptr = memcpy(new_ptr, ptr, min(old_size, size));

    free(ptr);

    return new_ptr;
}