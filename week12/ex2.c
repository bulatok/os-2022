#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int main() {
    int f = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event events[128];
    while (1) {
        int rb = read(f, events, sizeof(events));
        int till = (int) (rb / sizeof(struct input_event));
        for (int i = 0; i < till; i++) {
            if (events[i].value == 1) {
                printf("PRESSED 0x%x (%d)\n", events[i].code, events[i].code);
            } else if (events[i].value == 0) {
                printf("RELEASED 0x%x (%d)\n", events[i].code, events[i].code);
            }
        }
    }
    return 0;
}