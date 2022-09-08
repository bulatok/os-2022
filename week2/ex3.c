#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE_STRING 256

long long myPow(long long a, int i){
    if (i == 0){
        return 1;
    }
    long long res = 1;
    for (int j = 0; j < i; j++){
        res *= a;
    }
    return res;
}
void convert(long long x, long long from, long long to){
    char s[MAX_SIZE_STRING];

    long long x10;
    int i = 0;
    // from -> 10
    while (x){
        long long w = x % 10;
        x10 += myPow(from, i) * w;
        i = i + 1;
        x /= 10;
    }

    // 10 -> to
    char res[MAX_SIZE_STRING];
    i = 0;
    while(1){
        if (x10 < to){
            res[i] = ((int) x10) + '0';
            i++;
            break;
        }
        res[i] = (x10 % to) + '0';
        i++;
        x10 /= to;
    }

    for (int j = i-1; j >= 0; j--){
        printf("%c", res[j]);
    }
    printf("\n");
}
int badBase(long long s){
    if (s < 2 || s > 8) return 1;
    return 0;
}
int main(void) {
    long long x, from, to;

    printf("x - ");
    scanf("%lli", &x);
    
    printf("s - ");
    scanf("%lli", &from);

    
    printf("t - ");
    scanf("%lli", &to);

    if (badBase(from) || badBase(to)){
        printf("cannot convert!");
        return 0;
    }

    convert(x, from, to);
	return 0;
}
