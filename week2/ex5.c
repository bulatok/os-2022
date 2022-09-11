#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

long long tribonachi(long long n){
    // 1 2 3 4 5 6 7  8  9  ... idx
    // | | | | | | |  |  |   
    // 0 1 1 2 4 7 13 24 44 ... val
    if (n == 0){
        return 0;
    }
    if (n >= 1 && n <= 2){
        return 1;
    }

    long long v1 = 0;
    long long v2 = 1;
    long long v3 = 1;
    int times = n - 3;

    while(times){
        long long v4 = v1 + v2 + v3;
        v1 = v2;
        v2 = v3;
        v3 = v4;
        times--;
    }
    return v3;
}
int main(void) {
    printf("trib(4) = %lli\n", tribonachi(4));
    printf("trib(36) = %lli\n", tribonachi(36)); 
	return 0;
}
