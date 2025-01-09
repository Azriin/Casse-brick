#include <stdio.h>
#include <math.h>
#include "balle.h"


void displayBalle(sBalle balle){
    printf("Balle info:\n");
    printf("X      = %f\n", balle -> x);
    printf("Y      = %f\n", balle -> y);
    printf("Radius = %d\n", balle -> radius);
    printf("Speed  = %d\n", balle -> speed);
    printf("Degre  = %f\n", balle -> degre);
}

struct Balle initBalle(double x, double y, int radius, int speed, double degre){
    struct Balle balle;
    balle.x = x;
    balle.y = y;
    balle.radius = radius;
    balle.speed = speed;
    balle.degre = degre;
    return balle;
}

void addDegre(sBalle balle, double degre){
    balle -> degre += degre;
}

void move(sBalle balle){
    balle -> x += cos(balle -> degre) * (balle -> speed);
    balle -> y += sin(balle -> degre) * (balle -> speed);
}