#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct table {
    int pages;
    int counters;
} table;


int main() {
    int n;
    printf("n: ");
    scanf("%d", &n);

    FILE *file = fopen("input.txt", "r");

    table* t = malloc(n * sizeof(table));

    for (int i = 0; i < n; i++) {
        table cur;
        cur.pages = -1;
        cur.counters = 0;
        t[i] = cur;
    }

    int cur_requested;
    int hit_counter = 0;
    int miss_counter = 0;

    while (fscanf(file, "%d", &cur_requested) == 1) {
        int page_found = 0;

        for (int i = 0; i < n; i++) {
            if (t[i].pages == cur_requested) {
                page_found = 1;
                break;
            }
        }

        if (page_found){
            hit_counter++;
        }else{
            miss_counter++;
            int flag = 0;
            for (int i = 0; i < n; i++) {
                if (t[i].pages == -1) {
                    table page;
                    page.pages = cur_requested;
                    page.counters = 0;
                    t[i] = page;
                    flag = 1;
                    break;
                }
            }

            if (flag){
                continue;
            }   

            int min_counter = INT_MAX;
            int index = -1;
            for (int i = 0; i < n; i++) {
                if (min_counter > t[i].counters) {
                    min_counter = t[i].counters;
                    index = i;
                }
            }

            table page;
            page.pages = cur_requested;
            page.counters = 0;
            t[index] = page;
        }

        for (int i = 0; i < n; i++) {
            t[i].counters >>= 1;

            if (page_found && cur_requested == t[i].pages) t[i].counters |= 1 << 31;
        }
    }

    printf("hits: %d\n", hit_counter);
    printf("misses: %d\n", miss_counter);
    printf("ratio: %f\n", (float) hit_counter / (float) miss_counter);

    free(t);
    fclose(file);

    return 0;
}