#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(void) {
	int v1 = INT_MAX;
	unsigned short int v2 = USHRT_MAX;
	long int v3 = LONG_MAX;
	float v4 = FLT_MAX;
	double v5 = DBL_MAX;

	printf("int variable - 1) size: %zu bytes 2) value: %d\n", sizeof(v1), v1);
	printf("unsigned short int variable - 1) size: %zu bytes 2) value: %d\n", sizeof(v2), v2);
	printf("long int variable - 1) size: %zu bytes 2) %ld\n", sizeof(v3), v3);
	printf("float variable - 1) size: %zu bytes 2) %f\n", sizeof(v4), v4);
	printf("double variable - 1) size: %zu bytes 2) %f\n", sizeof(v5), v5);
	return 0;
}
