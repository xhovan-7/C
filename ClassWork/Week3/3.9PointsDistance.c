#include <stdio.h>
#include <math.h>

void scanPoints(int size, double points[size][2]){
    for (int i = 0, j = 'A'; i < size; i++, j++){
        printf("%c: ", j);
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }
}

double sq(double x){
    return x * x;
}

double distance(double a[], double b[]){
    double sq1 = sq(a[0] - b[0]);
    double sq2 = sq(a[1] - b[1]);
    return sqrt(sq1 + sq2);
}


void comparePoints (int size, double p[size][2], int nearest[]){
    double min = distance(p[0], p[1]);
    for (int i = 0; i < size - 1 ; i++){
        for (int j = i + 1; j < size; j++){
            double dist = distance(p[i], p[j]);
            if (min > dist){
                min = dist;
                nearest[0] = i;
                nearest[1] = j;
            }
        }
    }
}



int main(){
    int size; 
    int nearest[2] = {0, 1};

    printf("Enter the number of points:");
    scanf("%d", &size);

    double points[size][2];

    scanPoints(size, points);

    comparePoints(size, points, nearest);

    printf("The closest two points are ( %.1lf , %.1lf ) and ( %.1lf , %.1lf )", 
                                                    points[nearest[0]][0],
                                                    points[nearest[0]][1],
                                                    points[nearest[1]][0],
                                                    points[nearest[1]][1]);


    return 0;
}