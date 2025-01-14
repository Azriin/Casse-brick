#include <stdio.h>
#include <math.h>
#include "constant.h"
#include "balle.h"
#include "reflect.h"

void displayBalle(sBalle balle){
    printf("Balle info:\n");
    printf("X      = %f\n", balle -> x);
    printf("Y      = %f\n", balle -> y);
    printf("Vx     = %f\n", balle -> vx);
    printf("Vy     = %f\n", balle -> vy);
}

struct Balle initBalle(double x, double y, double vx, double vy){
    struct Balle balle = {x, y, vx, vy, 0.0, 0.0, 0.0, 0};
    return balle;
}

void setVelocity(sBalle balle, double vecteurX, double vecteurY){
    float orientation[] = {vecteurX, vecteurY};
    float direction[] = {balle -> vx, balle -> vy};
    float reflected[2];
    compute2DReflectedVectorRaw(orientation, direction, reflected);
    balle -> vx = reflected[0];
    balle -> vy = reflected[1];
}

static void getNext(sBalle balle) {
    balle -> x += balle -> vx;
    if (balle -> remainder < balle -> base) {
        balle -> remainder += (balle -> deviation);
    } else {
        balle -> y += balle -> vy;
        balle -> remainder -= (balle -> base);
    }
}

static void setBaseDeviation(sBalle balle){
    switch (balle -> area){
        case 1:
            balle -> base = fabs(balle -> vx) - fabs(balle -> vy);
            balle -> deviation = fabs(balle -> vy);
            break;
        case 2:
            balle -> base = fabs(balle -> vy) - fabs(balle -> vx);
            balle -> deviation = fabs(balle -> vx);
            break;
    }
}

void collideBall(sBalle balle, unsigned char matrice[LAR][LON]){
    int futurX = balle -> x + balle -> vx;
    int futurY = balle -> y + balle -> vy;
    switch (matrice[futurY][futurX]){
        case 1:
            setVelocity(balle, 0, 1);
            setBaseDeviation(balle);
            balle -> area = 2;
            break;
        case 2:
            setVelocity(balle, 1, 0);
            setBaseDeviation(balle);
            balle -> area = 1;
            break;
        case 3:
            setVelocity(balle, -1, 0);
            setBaseDeviation(balle);
            balle -> area = 1;
            break;
        case 4:
            setVelocity(balle, 0, -1);
            setBaseDeviation(balle);
            balle -> area = 2;
            break;
        case 5:
            setVelocity(balle, -1, -1);
            setBaseDeviation(balle);
            balle -> area = 0;
            break;
        case 6:
            setVelocity(balle, 1, -1);
            setBaseDeviation(balle);
            balle -> area = 0;
            break;
        case 7:
            setVelocity(balle, -1, 1);
            setBaseDeviation(balle);
            balle -> area = 0;
            break;
        case 8:
            setVelocity(balle, 1, 1);
            setBaseDeviation(balle);
            balle -> area = 0;
            break;
    }
}

void move(sBalle balle, unsigned char matrice[LAR][LON]){
    matrice[(int)(balle -> y)][(int)(balle -> x)] = 0;
    collideBall(balle, matrice);
    switch (balle -> area) {
        case 0 :
            balle -> x += balle -> vx;
            balle -> y += balle -> vy;
            break;
        case 1 :
            getNext(balle);
            break;
        case 2 :
            getNext(balle);
            break;
    }
    matrice[(int)(balle -> y)][(int)(balle -> x)] = 9;
}