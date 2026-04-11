#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


typedef struct Circle{
    double radius;
    double x;
    double y;
}Circle;

Circle getCircle(Circle c, int i);

double getLength(double a, double b);

double getDistance(Circle c1, Circle c2);

bool intersect(Circle c1, Circle c2, double dis_X_Y);

bool contain(Circle c1, Circle c2, double dis_X_Y);



#endif