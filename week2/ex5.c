#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

long long tribonachi(long long n){
    // 0 1 1 2 4 7 13 24 44 ...
    if (n == 0){
        return 0;
    }
    if (n >= 1 && n <= 2){
        return 1;
    }

    long long v1 = 0;
    long long v2 = 1;
    long long v3 = 1;
    long long v4 = v1 + v2 + v3;

    int times = n - 3;
    while(times){
        v1 = v2;
        v2 = v3;
        v3 = v4;
        v4 = v1 + v2 + v3;
        times--;
    }
}
int main(void) {
    printf("trib(4) = %lli\n", tribonachi(4));
    printf("trib(36) = %lli\n", tribonachi(36)); 
	return 0;
}
