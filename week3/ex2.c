#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point{
    double x, y;
};

double distance(struct Point p1, struct Point p2){
    double v1 = p1.x - p2.x;
    double v2 = p1.y - p2.y; 
    return sqrt(v1*v1 + v2*v2);
}

double area(struct Point A, struct Point B, struct Point C){
    return 0.5 * fabs((A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y));
}

int main(void){
    struct Point A = {2.5, 6};
    struct Point B = {1, 2.2};
    struct Point C = {10, 6};

    printf("distance (A - B) = %lf\n", distance(A, B));
    printf("area (ABC) = %lf\n", area(A, B, C));
    return 0;
}