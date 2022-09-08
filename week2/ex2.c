#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_STRING 256

int main(void) {
    char s[MAX_SIZE_STRING];
    char res[MAX_SIZE_STRING];
    fgets(s, MAX_SIZE_STRING, stdin);
    
    int flag = 1;
    int i = 0;
    for (i = 0; i < strlen(s); i++){
        if (s[i] == '.') {
            flag = 0;
            break;
        }
        res[i] = s[i];
    }
    
    if (flag){ // if we did not meet '.', then no need to print.
        return 0; 
    }

    printf("\"");
    for (int j = i - 1; j >= 0; j--){
        printf("%c", res[j]);
    }
    printf("\"");

	return 0;
}
