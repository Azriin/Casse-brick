#include <stdio.h>
#include <math.h>
#include "constant.h"
#include "balle.h"


void displayBalle(sBalle balle){
    printf("Balle info:\n");
    printf("X      = %f\n", balle -> x);
    printf("Y      = %f\n", balle -> y);
    printf("Vx     = %f\n", balle -> vx);
    printf("Vy     = %f\n", balle -> vy);
}

struct Balle initBalle(double x, double y, double vx, double vy){
    struct Balle balle;
    balle.x = x;
    balle.y = y;
    balle.vx = vx;
    balle.vy = vy;
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

void move(sBalle balle, unsigned char matrice[LAR][LON]){
    matrice[(int)(balle -> y)][(int)(balle -> x)] = 0;
    collideBall(balle, matrice);
    balle -> x += (balle -> vx);
    balle -> y += (balle -> vy);
    matrice[(int)(balle -> y)][(int)(balle -> x)] = 9;
}

void collideBall(sBalle balle, unsigned char matrice[LAR][LON]){
    int futurX = balle -> x + balle -> vx;
    int futurY = balle -> y + balle -> vy;
    switch (matrice[futurY][futurX]){
        case 1:
            setVelocity(balle, 0, 1);
            break;
        case 2:
            setVelocity(balle, 1, 0);
            break;
        case 3:
            setVelocity(balle, -1, 0);
            break;
        case 4:
            setVelocity(balle, 0, -1);
            break;
        case 5:
            setVelocity(balle, -1, -1);
            break;
        case 6:
            setVelocity(balle, 1, -1);
            break;
        case 7:
            setVelocity(balle, -1, 1);
            break;
        case 8:
            setVelocity(balle, 1, 1);
            break;
    }
}
