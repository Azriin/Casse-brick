#include <stdio.h>
#include <math.h>
#include "balle.h"


void displayBalle(sBalle balle){
    printf("Balle info:\n");
    printf("X      = %f\n", balle -> x);
    printf("Y      = %f\n", balle -> y);
    printf("Vx     = %f\n", balle -> vx);
    printf("Vy     = %f\n", balle -> vy);
    printf("Speed  = %d\n", balle -> speed);
    printf("Radius = %d\n", balle -> radius);
}

struct Balle initBalle(double x, double y, double vx, double vy, int speed, int radius){
    struct Balle balle;
    balle.x = x;
    balle.y = y;
    balle.vx = vx;
    balle.vy = vy;
    balle.speed = speed;
    balle.radius = radius;
    return balle;
}

double distance(int x, int y){
    return sqrt(x*x+y*y);
}

void setVelocity(sBalle balle, int vecteurX, int vecteurY){
    double dist = distance(vecteurX, vecteurY);
    balle -> vx = vecteurX/dist;
    balle -> vy = vecteurY/dist;
}

void move(sBalle balle){
    balle -> x += (balle -> vx) * (balle -> speed);
    balle -> y += (balle -> vy) * (balle -> speed);
}