#include "func.h"


Circle getCircle(Circle c, int i){
    printf("Enter circle %d (radius, x, y): ", i);
    scanf("%lf %lf %lf", &c.radius, &c.x, &c.y);
    return c;
}


double getLength(double a, double b){
    //get absolute valur of disatance
    double dis = ((a < b) ? (b - a) : (a - b));
    printf("Dis = %.2lf\n", dis);
    return dis;    
}


double getDistance(Circle c1, Circle c2){
    printf("X-");
    double dis_X = getLength(c1.x, c2.x);
    printf("Y-");
    double dis_Y = getLength(c1.y, c2.y);
    double dis_X_sq = dis_X * dis_X; //(distance between X)²
    double dis_Y_sq = dis_Y * dis_Y; //(distance between Y)²

    double dis_X_Y = sqrt(dis_X_sq + dis_Y_sq); // distance x to y
    
    return dis_X_Y;
}


bool intersect(Circle c1, Circle c2, double dis_X_Y){
    // circles intersect if sum of the radius if bigger than the distance between them 
    // if the equation is true (and they intersect) the function return 1(true)
    //otherwise 0(false)
    return (dis_X_Y < (c1.radius + c1.radius));
}


bool contain(Circle c1, Circle c2, double dis_X_Y){
    double small_R;
    double big_R;

    //find the bigger and smaller circle and assign their radius
    if (c1.radius > c2.radius){
        small_R = c2.radius;
        big_R = c1.radius;
    }
    else{
        small_R = c1.radius;
        big_R = c2.radius;
    }

    //if the bigger radius is bigger than distance plus small radius return true
    return ((dis_X_Y + small_R) <= big_R);
}


