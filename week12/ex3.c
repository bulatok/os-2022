#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int main() {
    int f = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    if (f == -1){
        return 0;
    }
    FILE *ex2 = fopen("ex2.txt", "a");
    while (1) {
        struct input_event event;
        read(f, &event, sizeof(events));
        if (event.value == 1) {
            fprintf(ex2, "PRESSED 0x%x (%d)\n", events[i].code, events[i].code);
            fflush(ex2);
        } else if (event.value == 0) {
            fprintf(ex2, "RELEASED 0x%x (%d)\n", events[i].code, events[i].code);
            fflush(ex2);
        }
    }
    return 0;
}