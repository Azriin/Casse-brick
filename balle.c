#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "balle.h"


struct Balle{
    double x;
    double y;
    int radius;
    int speed;
    double degre;
};

void displayBalle(sBalle balle){
    printf("Balle info:\n");
    printf("X      = %f\n", balle -> x);
    printf("Y      = %f\n", balle -> y);
    printf("Radius = %d\n", balle -> radius);
    printf("Speed  = %d\n", balle -> speed);
    printf("Degre  = %f\n", balle -> degre);
}

sBalle initBalle(double x, double y, int radius, int speed, double degre){
    sBalle balle;
    balle = malloc(sizeof(sBalle));
    if (balle == NULL){
        return NULL;
    }
    balle -> x = x;
    balle -> y = y;
    balle -> radius = radius;
    balle -> speed = speed;
    balle -> degre = degre;
    return balle;
}

void remBalle(sBalle balle){
    free(balle);
}

void addDegre(sBalle balle, double degre){
    balle -> degre += degre;
}

void move(sBalle balle){
    balle -> x += cos(balle -> degre) * (balle -> speed);
    balle -> y += sin(balle -> degre) * (balle -> speed);
}