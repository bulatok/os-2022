#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX_SIZE_STRING 256

int count(char s[], char c){
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++){
        char c2 = tolower(s[i]);
        if (c2 == c){
            cnt += 1;
        }
    }
    return cnt;
}

void countAll(char s[]){
    int cnt = 0;
    int n = strlen(s) - 1;
    for (int i = 0; i < n; i++){
        char c = tolower(s[i]);
        if (i == n - 1){
            printf("%c:%d", c, count(s, c));
            break;
        }
        printf("%c:%d, ", c, count(s, c));
    }
    printf("\n");
}
int main(void) {
	char s[MAX_SIZE_STRING];
    fgets(s, MAX_SIZE_STRING, stdin);

    countAll(s);
	return 0;
}
