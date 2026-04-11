#include "func.h"

int main(){
    Circle c1 = getCircle(c1, 1);
    Circle c2 = getCircle(c2, 2);
    int big = ((c1.radius > c2.radius) ? 1 : 2);
    int small = ((c1.radius <= c2.radius) ? 1 : 2);

    double dis_X_Y = getDistance(c1, c2);
    printf("dis_X_Y : %.2lf\n", dis_X_Y);
    printf(intersect(c1, c2,dis_X_Y) ? "The circle intersect!\n" : "");

    if (contain(c1, c2, dis_X_Y)){
        printf("Circle %d contaions Circle %d", big, small);
    }



    return 0;
}